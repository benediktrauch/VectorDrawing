#include "furniture.h"
#include <iostream>
#include <QDebug>

Furniture::Furniture(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
}


void Furniture::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << event;
}

void Furniture::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << event;
}

void Furniture::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << event;
}

void Furniture::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << event;
}

void Furniture::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << event;
}

qreal Furniture::height() const
{
    return m_height;
}

void Furniture::setHeight(const qreal &height)
{
    m_height = height;
}

qreal Furniture::width() const
{
    return m_width;
}

void Furniture::setWidth(const qreal &width)
{
    m_width = width;
}

QColor Furniture::fillColor() const
{
    return m_fillColor;
}

void Furniture::setFillColor(const QColor &fillColor)
{
    m_fillColor = fillColor;
}

QColor Furniture::borderColor() const
{
    return m_borderColor;
}

void Furniture::setBorderColor(const QColor &borderColor)
{
    m_borderColor = borderColor;
}

QPointF Furniture::pos() const
{
    return m_pos;
}

void Furniture::setPos(const QPointF &pos)
{
    m_pos = pos;
}

QString Furniture::name() const
{
    return m_name;
}

void Furniture::setName(const QString &name)
{
    m_name = name;
}
