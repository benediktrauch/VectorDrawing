#include "graphicsscene.h"
#include <QGraphicsSceneMouseEvent>

#include <iostream>
#include <QtDebug>

#include "roomgroundplan.h"
#include "mainwindow.h"
#include "draw.h"

GraphicsScene::GraphicsScene(QObject *parent):
    QGraphicsScene(parent)
{
    lineToolActive = new bool;
    *lineToolActive = false;
    myGroundplan = new RoomGroundplan();
    this->addItem(myGroundplan);

    this->createGrid();
}


GraphicsScene::~GraphicsScene()
{
    QGraphicsScene(parent);
}

void GraphicsScene::setActiveDrawingTool(const Draw::Tool &activeDrawingTool)
{
    if(activeDrawingTool == Draw::lineTool)
    {
        *lineToolActive = true;
    }
    else
    {
        *lineToolActive = false;
    }

}

QPointF GraphicsScene::getMyPoint() const
{
    return MyPoint;
}

void GraphicsScene::setMyPoint(const QPointF &value)
{
    MyPoint = value;
}

void GraphicsScene::createGrid()
{
    QPen pen1;
    pen1.setColor(QColor(50, 50, 50, 10));

    QPen pen2;
    pen2.setColor(QColor(50, 50, 50, 30));

    QPointF origin;
    QPointF target;

    for(qint16 i = 0; i < 165; i++){
        if(i%5 == 0){
            this->addLine(i*10, 0, i*10, 950, pen2);
        }
        this->addLine(i*10, 0, i*10, 950, pen1);
    }
    for(qint16 i = 0; i < 95; i++){
        if(i%5 == 0){
            this->addLine(0, i*10, 1650, i*10, pen2);
        }
        this->addLine(0, i*10, 1650, i*10, pen1);
    }
}


void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() == Qt::LeftButton)
    {
        double rad = 1;
        QPointF pt = mouseEvent->scenePos();

        int myPtX = pt.x();
        int myPtY = pt.y();

        if(myPtX % 10 < 5){
            myPtX = (pt.x()-(myPtX % 10));
        } else {
            myPtX = (pt.x()+(10 - myPtX % 10));
        }
        if(myPtY % 10 < 5){
            myPtY = (pt.y()-(myPtY % 10));
        } else {
            myPtY = (pt.y()+(10 - myPtY % 10));
        }

        pt.setX(myPtX);
        pt.setY(myPtY);

        if(this->getMyPoint().x() != 0 && this->getMyPoint().y() != 0)
        {
            if(*lineToolActive){
                myGroundplan->addLineToGroup(this->getMyPoint(), pt);

            }
        }

        if(*lineToolActive){
            this->setMyPoint(pt);
            this->addEllipse(myPtX-rad, myPtY-rad, rad*2.0, rad*2.0,QPen(), QBrush(Qt::SolidPattern));
        }
        emit newPointSelected(pt);
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}

