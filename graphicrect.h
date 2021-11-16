#pragma once

#include <QGraphicsItem>
#include <QPainter>

class PhysicalBody;

class GraphicRect : public QGraphicsItem
{
public:
    GraphicRect(PhysicalBody* _physicalBody);
    ~GraphicRect();
    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    PhysicalBody* _physicalBody;
};
