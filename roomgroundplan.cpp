#include "roomgroundplan.h"
#include <QGraphicsLineItem>
#include <QDebug>

/**
 * @brief RoomGroundplan::RoomGroundplan
 * @par Map for groundplan and lines
 */
RoomGroundplan::RoomGroundplan(QGraphicsItem *parent) :
    QGraphicsItemGroup(parent)
{

}

void RoomGroundplan::addLineToGroup(QPointF origin, QPointF target)
{

    QGraphicsLineItem* myLine;
    myLine = new QGraphicsLineItem();

    myLine->setLine(origin.x(), origin.y(), target.x(), target.y());

    this->addToGroup(myLine);

}


