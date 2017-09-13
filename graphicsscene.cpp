#include "graphicsscene.h"
#include <QGraphicsSceneMouseEvent>

#include <iostream>
#include <QtDebug>
#include <QString>
#include "roomgroundplan.h"
#include "mainwindow.h"
#include "draw.h"
#include <QPainterPath>
#include <QToolTip>

GraphicsScene::GraphicsScene(QObject *parent):
    QGraphicsScene(parent)
{
    lineToolActive = new bool;
    *lineToolActive = false;
    mousePressed = new bool;
    *mousePressed = false;
    groundplanFinished = new bool;
    *groundplanFinished = false;

    myGroundplan = new RoomGroundplan();

    rectPath = new QPainterPath;
    startPoint = new QPointF;
    endPoint = new QPointF;

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

void GraphicsScene::setCurrentMap(GraphicsObjectMap objectMap)
{
    m_graphicsObjectMap = objectMap;

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

    for(qint16 i = 0; i < 165; i++){
        if(i%5 == 0){
            this->addLine(i*10, 0, i*10, 950, pen2);
        }
        if(i%10 == 0){
            this->addText("| " + QString::number(i/10)+" m")->setPos(i*10 - 6, -5);
        }
        this->addLine(i*10, 0, i*10, 950, pen1);
    }
    for(qint16 i = 0; i < 95; i++){
        if(i%5 == 0){
            this->addLine(0, i*10, 1650, i*10, pen2);
            //this->addText(QString::number(i/10) + " m")->setPos(2, i*10 - 5);
        }
        this->addLine(0, i*10, 1650, i*10, pen1);
    }
}

QGraphicsItem *GraphicsScene::mouseSelectedItem() const
{
    return 0;
}
void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    QMap<QGraphicsItem *, GraphicsObject *>::const_iterator i = m_graphicsObjectMap.myMap.constBegin();
    while (i != m_graphicsObjectMap.myMap.constEnd()) {

        QRectF bounds = i.value()->graphicsItem()->boundingRect();
        int height, width;
        height = bounds.height();
        width = bounds.width();
        int x = i.value()->graphicsItem()->pos().x();
        int y = i.value()->graphicsItem()->pos().y();

        if(mouseEvent->scenePos().x() >= x && mouseEvent->scenePos().y() >= y){
            if(mouseEvent->scenePos().x() <= (x+width) && mouseEvent->scenePos().y() <= (y+height)){
                i.value()->graphicsItem()->setToolTip(i.value()->name());
                if(*mousePressed){
                    i.value()->graphicsItem()->setPos(mouseEvent->scenePos().x()-width/2, mouseEvent->scenePos().y()-height/2);
                }
            }
        }
        ++i;
    }
}
void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    *mousePressed = false;
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() == Qt::LeftButton)
    {
        *mousePressed = true;

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
        if(!*groundplanFinished){
            if(*lineToolActive && endPoint->isNull()){
                if(startPoint->isNull()){
                    rectPath->moveTo(pt.x(), pt.y());
                    startPoint->setX(pt.x());
                    startPoint->setY(pt.y());
                }
                else if(pt.x() == startPoint->x() && pt.y() == startPoint->y()){
                    rectPath->closeSubpath();

                    rectPath->moveTo(-10, -10);
                    rectPath->lineTo(-10, 10000);
                    rectPath->lineTo(10000, 10000);
                    rectPath->lineTo(10000, -10);
                    rectPath->closeSubpath();

                    QPen pen;  // creates a default pen

                    pen.setStyle(Qt::SolidLine);
                    pen.setWidth(3);
                    pen.setBrush(Qt::black);
                    pen.setCapStyle(Qt::RoundCap);
                    pen.setJoinStyle(Qt::RoundJoin);

                    QBrush brush;

                    brush.setColor(Qt::black);
                    brush.setStyle(Qt::BDiagPattern);

                    this->addPath(*rectPath, pen, brush);
                    endPoint->setX(pt.x());
                    endPoint->setY(pt.y());

                    *groundplanFinished = true;

                    pt.setX(0);
                    pt.setY(0);

                    this->setMyPoint(pt);
                    *startPoint = pt;
                    *endPoint = pt;
                }
                else
                {
                    rectPath->lineTo(pt.x(), pt.y());
                }
            }
        }
        emit newPointSelected(pt);
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}

