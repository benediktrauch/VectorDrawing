#ifndef ROOMGROUNDPLAN_H
#define ROOMGROUNDPLAN_H

#include <QObject>
#include <QGraphicsItemGroup>

class RoomGroundplan : public QGraphicsItemGroup
{
public:
    RoomGroundplan(QGraphicsItem* parent = 0);
    void addLineToGroup(QPointF origin, QPointF target);
};


#endif // ROOMGROUNDPLAN_H
