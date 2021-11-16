#pragma once
#include "mainwindow.h"
#include "rect.h"

#include <QTimer>
#include <QTime>

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:
    Model();

signals:
    void PhysicalBodyChanged();

public slots:
    void UpdatePhysicalBody(int x, int y);

private:
    GraphicRect* _rect;
    MainWindow* _mainWindow;

    QTimer* _timer;
};

