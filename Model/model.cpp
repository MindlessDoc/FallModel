#include "model.h"
#include "CalculationMethods/func.h"

Model::Model()
    : QObject()
{

    _leftPhysicalBody = new PhysicalBody();
    _rightPhysicalBody = new PhysicalBody();
    _mainWindow = new MainWindow();
    _timer = new QTimer();

    connect(_mainWindow->GetStartButton(), &QPushButton::clicked, this, &Model::StartModel);
    connect(_mainWindow->GetPauseButton(), &QPushButton::clicked, this, &Model::PauseModel);
    connect(_timer, &QTimer::timeout, this, &Model::UpdatePhysicalBody);
    connect(this, &Model::PhysicalBodyChanged, _mainWindow, &MainWindow::update);
}

void Model::UpdatePhysicalBody()
{
    _leftPhysicalBody->UpdateValues();
    _rightPhysicalBody->UpdateValues();

    _time += double(_timeUpdate) / 1000;

    emit PhysicalBodyChanged(_time, _leftPhysicalBody->GetSpeed(), _rightPhysicalBody->GetSpeed(),
                             _leftPhysicalBody->GetY(), _rightPhysicalBody->GetY());
}

void Model::StartGUI()
{
    _mainWindow->show();
}

void Model::StartModel()
{
    _time = 0;

    _timeUpdate = _mainWindow->GetTimeUpdate();
    _mainWindow->buildChart();

    _mainWindow->GetPauseButton()->setText("Пауза");
    _mainWindow->InitPhysicalBodies(_leftPhysicalBody, _rightPhysicalBody);

    _timer->start(_timeUpdate);
}

void Model::PauseModel()
{
    if(_timer)
    {
        if(_timer->isActive())
        {
            _timer->stop();
            _mainWindow->GetPauseButton()->setText("Продолжить");
        }
        else
        {
            _timer->start();
            _mainWindow->GetPauseButton()->setText("Пауза");
        }
    }
}
