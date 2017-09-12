#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <qgraphicsscene.h>
#include "roomgroundplan.h"
#include "graphicsobject.h"
#include "graphicsobjectmap.h"
#include<draw.h>


class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
signals:
    void newPointSelected(QPointF newPoint);

public slots:
    void setActiveDrawingTool(const Draw::Tool &activeDrawingTool);
    void setCurrentMap(GraphicsObjectMap objectMap);

public:
    explicit GraphicsScene(QObject *parent = 0);
    ~GraphicsScene();

    QPointF getMyPoint() const;
    void setMyPoint(const QPointF &value);

    void createGrid();

    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    QPointF MyPoint;
    RoomGroundplan* myGroundplan;
    bool* lineToolActive;
    QGraphicsItem *mouseSelectedItem() const;

    QPainterPath* rectPath;
    QPointF* startPoint;
    QPointF* endPoint;

    GraphicsObjectMap m_graphicsObjectMap;


protected:
};

#endif // GRAPHICSSCENE_H
