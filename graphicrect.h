#pragma once

#include <QGraphicsItem>
#include <QPainter>

class GraphicRect : public QGraphicsItem
{
public:
    GraphicRect();
    ~GraphicRect();
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void SetX(int x);
    void SetY(int y);

    int GetX();
    int GetY();

private:
    int _x, _y;
};
