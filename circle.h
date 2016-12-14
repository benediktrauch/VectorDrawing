#ifndef CIRCLE_H
#define CIRCLE_H

#include "graphicsobject.h"

#include <QObject>
#include <QString>
#include <QGraphicsEllipseItem>

/**
 * @brief The Circle class
 */
class Circle : public GraphicsObject
{
public:
    explicit Circle(QObject *parent = 0);
    virtual QGraphicsItem *graphicsItem() const;
    Circle(qreal x, qreal y, qreal width, qreal heigth, QColor color1, QColor color2);

    QString toString();
private:
    static unsigned long m_circleCounter; ///< Couner for all Circle Objects
    QGraphicsEllipseItem *m_graphicsEllipse;
};

#endif // CIRCLE_H
