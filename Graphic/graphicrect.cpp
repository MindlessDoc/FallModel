#include "graphicrect.h"
#include "PhysicalBody/physicalbody.h"
#include <QString>

GraphicRect::GraphicRect(PhysicalBody* physicalBody, QColor color)
    : QGraphicsItem()
    , _color(color)
    , _physicalBody(physicalBody)
{
    //setFocus();
}

GraphicRect::~GraphicRect()
{

}

QRectF GraphicRect::boundingRect() const
{
    return QRectF(0, 0, 40, 40);
}

void GraphicRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        painter->setPen(QPen(Qt::black));
        painter->setBrush(QBrush(_color));
        painter->drawRect(_physicalBody->GetX() * 100, -_physicalBody->GetY() * 100 - 40, 40, 40);

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

void GraphicRect::UpdateLabels()
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
