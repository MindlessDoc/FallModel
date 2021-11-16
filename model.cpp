#include "model.h"
#include "func.h"

Model::Model()
    : QObject()
{
    _physicalBody = new PhysicalBody(0, 200, 0);
    _mainWindow = new MainWindow(_physicalBody->GetAvatar());

    _timer = new QTimer();

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

    std::cout << _physicalBody->GetSpeed() << " " << _physicalBody->GetY() << std::endl;

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
