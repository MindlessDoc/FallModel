#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "PhysicalBody/physicalbody.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    leftScene = new QGraphicsScene();
    ui->leftView->setScene(leftScene);

    rightScene = new QGraphicsScene();
    ui->rightView->setScene(rightScene);

    this->resize(1200,800);

    leftScene->addLine(-200, 0, 200, 0);
    rightScene->addLine(-200, 0, 200, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitPhysicalBodies(PhysicalBody* leftPhysicalBody, PhysicalBody* rightPhysicalBody)
{
    leftPhysicalBody->InitValues(ui->OxLineEdit->text().toDouble(), ui->OyLineEdit->text().toDouble(),
                       ui->speedLineEdit->text().toDouble(),
                       ui->leftSpeeLabel, ui->leftXLabel, ui->leftYLabel);
    leftPhysicalBody->InitMethod(new EulerMethod(ui->stepLineEdit->text().toDouble(),
                                        new Function(ui->resistanceLineEdit->text().toDouble())));
    leftScene->addItem(leftPhysicalBody->GetAvatar());

    rightPhysicalBody->InitValues(ui->OxLineEdit->text().toDouble(), ui->OyLineEdit->text().toDouble(),
                       ui->speedLineEdit->text().toDouble(),
                       ui->rightSpeedLabel, ui->rightXLabel, ui->rightYLabel);
    rightPhysicalBody->InitMethod(new ClassicFourthRKMethod(ui->stepLineEdit->text().toDouble(),
                                        new Function(ui->resistanceLineEdit->text().toDouble())));
    rightScene->addItem(rightPhysicalBody->GetAvatar());

}

void MainWindow::update()
{
    leftScene->update();
    rightScene->update();
}

QPushButton* MainWindow::GetStartButton()
{
    return ui->startButtom;
}

QPushButton* MainWindow::GetPauseButton()
{
    return ui->pauseButtom;
}

int MainWindow::GetTimeUpdate()
{
    return ui->stepLineEdit->text().toDouble() * 1000;
}


