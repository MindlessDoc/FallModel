#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include "graphicrect.h"
#include "Charts/chart.h"


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
    void update(double time, double leftSpeed, double rightSpeed, double leftY, double rightY);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *leftScene;
    QGraphicsScene *rightScene;

    Chart* _leftChart = nullptr;
    Chart* _rightChart = nullptr;

};
