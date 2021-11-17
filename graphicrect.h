#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QLabel>

class PhysicalBody;

class GraphicRect : public QGraphicsItem
{
public:
    GraphicRect(PhysicalBody* _physicalBody);
    ~GraphicRect();
    QRectF boundingRect() const override;

    void SetLabelSpeed(QLabel* labelSpeed);
    void SetLabelX(QLabel* labelX);
    void SetLabelY(QLabel* labelY);

    void UpdateLabelSpeed();
    void UpdateLabelX();
    void UpdateLabelY();

    void UpdateValues();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    QLabel* _labelSpeed;
    QLabel* _labelX;
    QLabel* _labelY;
    PhysicalBody* _physicalBody;
};
