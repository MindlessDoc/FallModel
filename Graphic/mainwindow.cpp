#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "PhysicalBody/physicalbody.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    approximateScene = new QGraphicsScene();
    ui->approximateView->setScene(approximateScene);

    analyticScene = new QGraphicsScene();
    ui->analyticView->setScene(analyticScene);

    this->resize(1200,800);

    approximateScene->addLine(-200, 0, 200, 0);
    analyticScene->addLine(-200, 0, 200, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitPhysicalBody(PhysicalBody *physicalBody)
{
    physicalBody->Init(ui->OxLineEdit->text().toDouble(), ui->OyLineEdit->text().toDouble(),
                       ui->speedLineEdit->text().toDouble(),
                       ui->approximateSpeeLabel, ui->approximateXLabel, ui->approximateYLabel);

    //std::cout << physicalBody->GetAvatar()->hasFocus() << std::endl;
    approximateScene->addItem(physicalBody->GetAvatar());

    //approximateScene->setFocusItem(physicalBody->GetAvatar());
    //std::cout << approximateScene->hasFocus();
}

void MainWindow::update()
{
    approximateScene->update();
}

QPushButton* MainWindow::GetStartButton()
{
    return ui->startButtom;
}

QPushButton* MainWindow::GetPauseButton()
{
    return ui->pauseButtom;
}


void MainWindow::on_beginButtom_clicked()
{

}

