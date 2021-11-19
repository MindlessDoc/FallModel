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
                       ui->leftSpeeLabel, ui->leftXLabel, ui->leftYLabel,
                                 QColor(Qt::red));
    leftPhysicalBody->InitMethod(new EulerMethod(ui->stepLineEdit->text().toDouble(),
                                        new Function(ui->resistanceLineEdit->text().toDouble())));
    leftScene->addItem(leftPhysicalBody->GetAvatar());

    rightPhysicalBody->InitValues(ui->OxLineEdit->text().toDouble(), ui->OyLineEdit->text().toDouble(),
                       ui->speedLineEdit->text().toDouble(),
                       ui->rightSpeedLabel, ui->rightXLabel, ui->rightYLabel,
                                  QColor(Qt::blue));
    rightPhysicalBody->InitMethod(new ClassicFourthRKMethod(ui->stepLineEdit->text().toDouble(),
                                        new Function(ui->resistanceLineEdit->text().toDouble())));
    rightScene->addItem(rightPhysicalBody->GetAvatar());

}

void MainWindow::update(double time, double leftSpeed, double rightSpeed, double leftY, double rightY)
{
    leftScene->update();
    rightScene->update();

    _leftChart->Update(time, leftSpeed, rightSpeed);
    _rightChart->Update(time, leftY, rightY);
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


void MainWindow::buildChart()
{
    delete _leftChart; _leftChart = nullptr;
    delete _rightChart; _rightChart = nullptr;

    _leftChart = new Chart(ui->leftWidget, 1.0, 5.0, "T", "Speed");
    _rightChart = new Chart(ui->rightWidget, 1.0, 5.0, "T", "Y");
}


