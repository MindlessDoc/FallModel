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
    void PhysicalBodyChanged();

public slots:
    void UpdatePhysicalBody();

private:
    PhysicalBody* _approximatePhysicalBody;
    PhysicalBody* _analyticPhysicalBody;
    MainWindow* _mainWindow;

    QTimer* _timer = nullptr;
};

