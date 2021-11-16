#include "graphicrect.h"
#include "physicalbody.h"

GraphicRect::GraphicRect(PhysicalBody* physicalBody)
    : QGraphicsItem()
    , _physicalBody(physicalBody)
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
        painter->drawRect(_physicalBody->GetX() - 50, -_physicalBody->GetY(), 100, 100);

        Q_UNUSED(option);
        Q_UNUSED(widget);
}
