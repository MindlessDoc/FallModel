#pragma once

#include <QChart>
#include <QSplineSeries>
#include <QHBoxLayout>
#include <QValueAxis>
#include <QChartView>
#include <QWidget>

class Chart
{
public:
    Chart(QWidget* widget, double xLimit, double yLimit, QString xName, QString yName);
    ~Chart();

    void Update(double x, double leftY, double rightY);

private:
    double _xLimit;
    double _yLimit;

    QChart *_chart = nullptr;
    QChartView *_chartview = nullptr;
    QSplineSeries *_leftSeries = nullptr;
    QSplineSeries *_rightSeries = nullptr;
    QHBoxLayout *_layout = nullptr;
    QValueAxis *_axisX = nullptr;
    QValueAxis *_axisY = nullptr;
};
