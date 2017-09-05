#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <qgraphicsscene.h>
#include "roomgroundplan.h"
#include<draw.h>


class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
signals:
    void newPointSelected(QPointF newPoint);

public slots:
    void setActiveDrawingTool(const Draw::Tool &activeDrawingTool);


public:
    explicit GraphicsScene(QObject *parent = 0);
    ~GraphicsScene();

    QPointF getMyPoint() const;
    void setMyPoint(const QPointF &value);

    void createGrid();

private:
    QPointF MyPoint;
    RoomGroundplan* myGroundplan;
    bool* lineToolActive;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

};

#endif // GRAPHICSSCENE_H
