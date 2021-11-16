#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QGraphicsItem* item, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    scene->addLine(-200, 100, 200, 100);
    scene->addItem(item);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    scene->update();
}

