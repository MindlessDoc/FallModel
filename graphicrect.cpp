#include "graphicrect.h"
#include "physicalbody.h"
#include <QString>

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

void GraphicRect::UpdateLabelSpeed()
{
    _labelSpeed->setText(QString::number(_physicalBody->GetSpeed()));
}

void GraphicRect::UpdateLabelX()
{
    _labelX->setText(QString::number(_physicalBody->GetX()));
}

void GraphicRect::UpdateLabelY()
{
    _labelY->setText(QString::number(_physicalBody->GetY()));
}

void GraphicRect::UpdateValues()
{
    _labelSpeed->setText(QString::number(_physicalBody->GetSpeed()));
    _labelX->setText(QString::number(_physicalBody->GetX()));
    _labelY->setText(QString::number(_physicalBody->GetY()));

}

void GraphicRect::SetLabelSpeed(QLabel *labelSpeed)
{
    _labelSpeed = labelSpeed;
}
void GraphicRect::SetLabelX(QLabel *labelX)
{
    _labelX = labelX;
}
void GraphicRect::SetLabelY(QLabel *labelY)
{
    _labelY = labelY;
}
