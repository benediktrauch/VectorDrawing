#ifndef GRAPHICSOBJECTMAP_H
#define GRAPHICSOBJECTMAP_H

#include <QMap>
#include <QGraphicsItem>
#include "graphicsobject.h"


class GraphicsObjectMap :
        public QMap<QGraphicsItem *,
        GraphicsObject *>
{
public:
    GraphicsObjectMap();
    QMap <QGraphicsItem *, GraphicsObject *> myMap;

    void PrintObjects();
};

#endif // GRAPHICSOBJECTMAP_H
