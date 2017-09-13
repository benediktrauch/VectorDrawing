#include "rectangle.h"
#include <QPen>
#include <QBrush>

    unsigned long Rectangle::m_rectangleCounter = 1;

/**
 * @brief Generates a new Rectangle Object
 * @param parent
 */
Rectangle::Rectangle(QObject *parent) : GraphicsObject (parent)
{
}

Rectangle::Rectangle(qreal x, qreal y, qreal width, qreal heigth, QColor color1, QColor color2)
{
    m_graphicsRect = new QGraphicsRectItem();
    this->setName(QString("rectangle_%1").arg(m_rectangleCounter));
    m_rectangleCounter++;

    m_graphicsRect->setRect(0, 0, heigth, width);
    m_graphicsRect->setPen(color1); //Border
    m_graphicsRect->setBrush(color2); //Fill
    m_graphicsRect->setPos(x, y);
}

QGraphicsItem *Rectangle::graphicsItem() const
{
    return m_graphicsRect;
}

QString Rectangle::toString()
{
    return "Rectangle: " + this->name()
            + "X: " + QString::number(m_graphicsRect->rect().x())
            + " Y: " + QString::number(m_graphicsRect->rect().y())
            + " Width: " + QString::number(m_graphicsRect->rect().width())
            + " Height: " + QString::number(m_graphicsRect->rect().height())
            + " fill color: " + m_graphicsRect->brush().color().name()
            + " border color: " + m_graphicsRect->pen().color().name();
}
