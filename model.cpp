#include "model.h"

Model::Model()
    : QObject()
{
    _rect = new GraphicRect;
    _mainWindow = new MainWindow(_rect);

    _timer = new QTimer();

    connect(_timer, &QTimer::timeout, _mainWindow, &MainWindow::update);
    connect(_timer, &QTimer::timeout, _mainWindow, &MainWindow::update);

}
