#include "graphicsobject.h"
#include <QObject>
#include <iostream>
#include <QDebug>

unsigned long GraphicsObject::m_graphicsObjectCounter = 0;

/**
 * @brief GraphicsObject::GraphicsObject
 * @param parent is 0
 */
GraphicsObject::GraphicsObject(QObject *parent) : QObject (parent)
{
    m_graphicsItem = NULL;
    m_name = QString("graphics_%1").arg(m_graphicsObjectCounter);
}
/**
 * @brief Getter for name of GraphicsObject
 * @return m_name
 */
QString GraphicsObject::name() const
{
    return m_name;
}

/**
 * @brief Setter for name of GraphicsObject
 * @param new name
 */
void GraphicsObject::setName(const QString &name)
{
    m_name = name;
}
/**
 * @brief GraphicsObject::graphicsItem
 * @return
 */
QGraphicsItem *GraphicsObject::graphicsItem() const
{
    return m_graphicsItem;
}
/**
 * @brief GraphicsObject::posX
 * @return
 */
qreal GraphicsObject::posX() const
{
    return m_posX;
}
/**
 * @brief GraphicsObject::setPosX
 * @param posX
 */
void GraphicsObject::setPosX(const qreal &posX)
{
    m_posX = posX;
}
/**
 * @brief GraphicsObject::posY
 * @return
 */
qreal GraphicsObject::posY() const
{
    return m_posY;
}
/**
 * @brief GraphicsObject::setPosY
 * @param posY
 */
void GraphicsObject::setPosY(const qreal &posY)
{
    m_posY = posY;
}
/**
 * @brief GraphicsObject::borderColor
 * @return
 */
QColor GraphicsObject::borderColor() const
{
    return m_borderColor;
}
/**
 * @brief GraphicsObject::setBorderColor
 * @param borderColor
 */
void GraphicsObject::setBorderColor(const QColor &borderColor)
{
    m_borderColor = borderColor;
}
/**
 * @brief GraphicsObject::fillColor
 * @return
 */
QColor GraphicsObject::fillColor() const
{
    return m_fillColor;
}
/**
 * @brief GraphicsObject::setFillColor
 * @param fillColor
 */
void GraphicsObject::setFillColor(const QColor &fillColor)
{
    m_fillColor = fillColor;
}


