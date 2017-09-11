#include "circle.h"
#include <QPen>
#include <QBrush>

    unsigned long Circle::m_circleCounter = 1;

/**
 * @brief Generates a new Circle Object
 * @param parent
 */
Circle::Circle(QObject *parent) : GraphicsObject (parent)
{

}
/**
 * @brief GraphicsItem
 * @return Returns Ellipse
 */
QGraphicsItem *Circle::graphicsItem() const
{
    return m_graphicsEllipse;
}
/**
 * @brief Circle::Circle
 * @param X-Position
 * @param Y-Position
 * @param Width
 * @param Heigth
 * @param color1
 * @param color2
 */
Circle::Circle(qreal x, qreal y, qreal width, qreal heigth, QColor color1, QColor color2)
{
    m_graphicsEllipse = new QGraphicsEllipseItem();
    this->setName(QString("circle_%1").arg(m_circleCounter));
    m_circleCounter++;

    m_graphicsEllipse->setRect(0, 0, heigth, width);
    m_graphicsEllipse->setPen(color1); //Border
    m_graphicsEllipse->setBrush(color2); //Fill
    m_graphicsEllipse->setPos(x, y);
}

QString Circle::toString()
{
        return "Circle: " + this->name()
                + "X: " + QString::number(m_graphicsEllipse->rect().x())
                + " Y: " + QString::number(m_graphicsEllipse->rect().y())
                + " Width: " + QString::number(m_graphicsEllipse->rect().width())
                + " Height: " + QString::number(m_graphicsEllipse->rect().height())
                + " fill color: " + m_graphicsEllipse->brush().color().name()
                + " border color: " + m_graphicsEllipse->pen().color().name();
 }
