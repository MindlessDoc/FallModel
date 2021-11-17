#include "model.h"
#include "func.h"

Model::Model()
    : QObject()
{
    _approximatePhysicalBody = new PhysicalBody();
    _mainWindow = new MainWindow(_physicalBody->GetAvatar());
    _timer = new QTimer();

    connect(_mainWindow->GetStartButton(), &QPushButton::clicked, this, &Model::StartModel);
    connect(_timer, &QTimer::timeout, this, &Model::UpdatePhysicalBody);
    connect(this, &Model::PhysicalBodyChanged, _mainWindow, &MainWindow::update);
}

void Model::UpdatePhysicalBody()
{
    double additional_speed = _physicalBody->GetSpeed();
    _physicalBody->SetSpeed(MethodEuler(_physicalBody->GetSpeed(), 0.01));
    _physicalBody->SetY(MethodEuler_2(_physicalBody->GetY(), additional_speed, 0.01));

    if(_physicalBody->GetY() < 0)
    {
        _physicalBody->SetSpeed(-_physicalBody->GetSpeed());
    }

    //_physicalBody->GetAvatar()->UpdateValues();

    emit PhysicalBodyChanged();
}

void Model::StartGUI()
{
    _mainWindow->show();
}

void Model::StartModel()
{
    _timer->start(1);
}
