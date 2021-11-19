#pragma once
#include "Graphic/mainwindow.h"
#include "PhysicalBody/physicalbody.h"

#include <QTimer>
#include <QTime>

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:
    Model();
    void StartGUI();
    void StartModel();
    void PauseModel();

signals:
    void PhysicalBodyChanged(double time, double leftSpeed, double rightSpeed,
                             double leftY, double rightY);

public slots:
    void UpdatePhysicalBody();

private:
    PhysicalBody* _leftPhysicalBody;
    PhysicalBody* _rightPhysicalBody;
    MainWindow* _mainWindow;

    double _time = 0.0;
    QTimer* _timer = nullptr;
    int _timeUpdate;
};

