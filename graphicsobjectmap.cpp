#include "graphicsobjectmap.h"
#include <QDebug>

GraphicsObjectMap::GraphicsObjectMap()
{

}

/**
 * @brief Prints all objects of map object
 */
void GraphicsObjectMap::PrintObjects()
{
    QMapIterator<QGraphicsItem *, GraphicsObject *>i (myMap);
    while(i.hasNext()){
        i.next();
        qDebug() << i.value()->toString();
    }
}
