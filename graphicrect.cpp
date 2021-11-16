#include "graphicrect.h"

GraphicRect::GraphicRect()
    : QGraphicsItem()
    , _x(0)
    , _y(0)
{

}

GraphicRect::~GraphicRect()
{

}

QRectF GraphicRect::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void GraphicRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        painter->setPen(QPen(Qt::green));
        painter->setBrush(QBrush(Qt::yellow));
        painter->drawRect(_x, _y, 100, 100);

        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void GraphicRect::SetX(int x) { _x = x; }
void GraphicRect::SetY(int y) { _y = y; }
