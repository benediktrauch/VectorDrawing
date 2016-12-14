#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "graphicsobject.h"

#include <QObject>
#include <QString>
#include <QGraphicsRectItem>

/**
 * @brief The Rectangle class
 */
class Rectangle : public GraphicsObject
{
public:
    explicit Rectangle(QObject *parent = 0);
    Rectangle(qreal x, qreal y, qreal width, qreal heigth, QColor color1, QColor color2);
    virtual QGraphicsItem *graphicsItem() const;

    QString toString();
private:
    static unsigned long m_rectangleCounter; ///< Counter for Rectangle Objects
    QGraphicsRectItem *m_graphicsRect;
};

#endif // RECTANGLE_H
