#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <qgraphicsscene.h>
#include "roomgroundplan.h"

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GraphicsScene(QObject *parent = 0);
    ~GraphicsScene();

    QPointF getMyPoint() const;
    void setMyPoint(const QPointF &value);

    void createGrid();

private:
    QPointF MyPoint;
    RoomGroundplan* myGroundplan;
    bool test;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

};

#endif // GRAPHICSSCENE_H
