#include "chart.h"

Chart::Chart(QWidget* widget, double xLimit, double yLimit, QString xName, QString yName)
    : _xLimit(xLimit)
    , _yLimit(yLimit)
{    
    _leftSeries = new QSplineSeries;
    _rightSeries = new QSplineSeries;
    _chart = new QChart;
    _chartview = new QChartView(_chart);
    _layout = new QHBoxLayout;

    _axisX = new QValueAxis;
    _axisY = new QValueAxis;

    _axisY->setRange(0, _xLimit);
    _axisX-> setLabelFormat ("%f");
    _axisX-> setGridLineVisible (true);
    _axisX-> setMinorTickCount (1);
    _axisX-> setTitleText (xName);


    _axisY->setRange(-_yLimit, _yLimit);
    _axisY->setLabelFormat("%f");
    _axisY->setGridLineVisible(true);
    _axisY->setTitleText(yName);

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

    _layout->removeWidget(_chartview);
    _layout->addWidget(_chartview);

    widget->setLayout(_layout);

}

Chart::~Chart()
{
    delete _axisX;
    delete _axisY;
    delete _leftSeries;
    delete _rightSeries;
    delete _chart;
    delete _chartview;
    delete _layout;
}

void Chart::Update(double x, double leftY, double rightY)
{
    if(x > _xLimit)
    {
        _leftSeries->remove(0);
        _rightSeries->remove(0);
        _axisX->setRange(x - _xLimit, x);
    }

    _leftSeries->append(x, leftY);
    _rightSeries->append(x, rightY);
}
