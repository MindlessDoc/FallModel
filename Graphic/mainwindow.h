#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include "graphicrect.h"
#include <QChart>
#include <QSplineSeries>
#include <QHBoxLayout>
#include <QValueAxis>
#include <QChartView>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void buildChart();

    QPushButton* GetStartButton();
    QPushButton* GetPauseButton();

    void InitPhysicalBodies(PhysicalBody* leftPhysicalBody, PhysicalBody* rightPhysicalBody);
    int GetTimeUpdate();

public slots:
    void update(double leftSpeed, double rightSpeed, double time);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *leftScene;
    QGraphicsScene *rightScene;

    QChart *_chart = nullptr;
    QChartView *_chartview = nullptr;
    QSplineSeries *_leftSeries = nullptr;
    QSplineSeries *_rightSeries = nullptr;
    QHBoxLayout *_layout = nullptr;
    QValueAxis *_axisX = nullptr;
    QValueAxis *_axisY = nullptr;

};
