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

void MainWindow::update(double leftSpeed, double rightSpeed, double time)
{
    leftScene->update();
    rightScene->update();

    if(time > 1.0)
    {
        _leftSeries->remove(0);
        _rightSeries->remove(0);
        _axisX->setRange(time - 1.0, time);
    }

    _leftSeries->append(time, leftSpeed);
    _rightSeries->append(time, rightSpeed);
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
    delete _axisX;
    delete _axisY;
    delete _leftSeries;
    delete _rightSeries;
    delete _chart;
    delete _chartview;
    delete _layout;


    _leftSeries = new QSplineSeries;
    _rightSeries = new QSplineSeries;
    _chart = new QChart;
    _chartview = new QChartView(_chart);
    _layout = new QHBoxLayout;

    _axisX = new QValueAxis;
    _axisY = new QValueAxis;

    _axisX-> setLabelFormat ("%f");
    _axisX-> setGridLineVisible (true);
    _axisX-> setMinorTickCount (1);
    _axisX-> setTitleText ("X");


    _axisY->setRange(-5, 5);
    _axisY->setLabelFormat("%f");
    _axisY->setGridLineVisible(true);
    _axisY->setTitleText("Y");

    _chart->addAxis (_axisX, Qt :: AlignBottom);
    _chart->addAxis (_axisY, Qt :: AlignLeft);


    // Создать источник данных
    _leftSeries->setPen (QPen(Qt::red, 1, Qt::SolidLine));
    _rightSeries->setPen (QPen(Qt::blue, 1, Qt::SolidLine));

    _chart->legend () -> hide ();
    _chart->addSeries(_leftSeries);
    _chart->addSeries(_rightSeries);

    _chart->setAxisX(_axisX, _leftSeries);
    _chart->setAxisY(_axisY, _leftSeries);

    _chart->setAxisX(_axisX, _rightSeries);
    _chart->setAxisY(_axisY, _rightSeries);

    _layout->addWidget(_chartview);
    ui->widget->setLayout(_layout);
}


