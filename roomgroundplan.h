#ifndef ROOMGROUNDPLAN_H
#define ROOMGROUNDPLAN_H

#include <QObject>
#include <QGraphicsItemGroup>

/**
 * @brief The RoomGroundplan class
 */
class RoomGroundplan : public QGraphicsItemGroup
{
public:
    RoomGroundplan(QGraphicsItem* parent = 0);
    void addLineToGroup(QPointF origin, QPointF target);
};


#endif // ROOMGROUNDPLAN_H
