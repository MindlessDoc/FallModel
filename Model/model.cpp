#include "model.h"
#include "CalculationMethods/func.h"

Model::Model()
    : QObject()
{
    _approximatePhysicalBody = new PhysicalBody();
    _mainWindow = new MainWindow();
    _timer = new QTimer();

    connect(_mainWindow->GetStartButton(), &QPushButton::clicked, this, &Model::StartModel);
    connect(_mainWindow->GetPauseButton(), &QPushButton::clicked, this, &Model::PauseModel);
    connect(_timer, &QTimer::timeout, this, &Model::UpdatePhysicalBody);
    connect(this, &Model::PhysicalBodyChanged, _mainWindow, &MainWindow::update);
}

void Model::UpdatePhysicalBody()
{
    double additional_speed = _approximatePhysicalBody->GetSpeed();
    _approximatePhysicalBody->SetSpeed(MethodEuler(_approximatePhysicalBody->GetSpeed(), 0.01));
    _approximatePhysicalBody->SetY(MethodEuler_2(_approximatePhysicalBody->GetY(), additional_speed, 0.01));

    if(_approximatePhysicalBody->GetY() < 0)
    {
        _approximatePhysicalBody->SetSpeed(-_approximatePhysicalBody->GetSpeed());
    }

   _approximatePhysicalBody->GetAvatar()->UpdateValues();

    emit PhysicalBodyChanged();
}

void Model::StartGUI()
{
    _mainWindow->show();
}

void Model::StartModel()
{
    _mainWindow->InitPhysicalBody(_approximatePhysicalBody);
    _timer->start(1);
}

void Model::PauseModel()
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
