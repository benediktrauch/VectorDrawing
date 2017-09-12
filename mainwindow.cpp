#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgraphicsscene.h"

#include <iostream>
#include <QString>
#include <draw.h>
#include "furniture.h"
#include <QtDebug>
#include <QColorDialog>
#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include "objectsettings.h"

/**
 * @brief Creates new Window, binds Scene Object to graphicsView, sets background-color, connetion between tools/colors and mainwindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuBar->setVisible(false);
    myDraw1 = new Draw();

    mygraphicobjects = new GraphicsObjectMap();
    myGraphicsscene = new GraphicsScene();

    //Connections for tools
    connect(ui->drawingToolSelector, SIGNAL(activeDrawingToolChanged(Draw::Tool)), this, SLOT(generateNewUI(Draw::Tool)));
    connect(ui->drawingToolSelector, SIGNAL(activeDrawingToolChanged(Draw::Tool)), this, SLOT(setActiveDrawingTool(Draw::Tool)));
    connect(this, SIGNAL(activeDrawingToolChanged(Draw::Tool)), ui->drawingToolSelector, SLOT(setActiveDrawingTool(Draw::Tool)));

    //Connection for colors
    connect(ui->colorToolSelector, SIGNAL(activeFillColorToolChanged(QColor)), myDraw1, SLOT(setFillColor(QColor)));
    connect(ui->colorToolSelector, SIGNAL(activeBorderColorToolChanged(QColor)), myDraw1, SLOT(setBorderColor(QColor)));

    connect(myGraphicsscene, SIGNAL(newPointSelected(QPointF)), this, SLOT(setSelectedPoint(QPointF)));
    connect(this, SIGNAL(activeDrawingToolChanged(Draw::Tool)), myGraphicsscene, SLOT(setActiveDrawingTool(Draw::Tool)));
    connect(this, SIGNAL(newObjectAdded(GraphicsObjectMap)), myGraphicsscene, SLOT(setCurrentMap(GraphicsObjectMap)));
    connect(this, SIGNAL(objectRecieved(GraphicsObject*)), ui->objectSettingsWidget, SLOT(objectAttributes(GraphicsObject*)));

    connect(ui->objectSettingsWidget, SIGNAL(myObjectNameChanged(QString)), this, SLOT(selectedObjectNameChanged(QString)));
    connect(ui->objectSettingsWidget, SIGNAL(pb_removeObject()), this, SLOT(removeCurrentObject()));
    connect(ui->objectSettingsWidget, SIGNAL(closeButtonPressed()), this, SLOT(ObjectSettingsClose()));
    connect(ui->objectSettingsWidget, SIGNAL(dial_rotationChanged(int)), this, SLOT(selectedObjectRotated(int)));


    ui->pb_AddObject->setEnabled(false);
    ui->settingsBox->setEnabled(false);

    ui->graphicsView->setScene(myGraphicsscene);

    myDraw1->setT(Draw::selectTool);
    myDraw1->setFillColor(Qt::red);
    myDraw1->setBorderColor(Qt::red);
    ui->graphicsView->setSceneRect(0,0,300,150);

    ui->objectSettingsWidget->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Border Color debug message
 */
void MainWindow::runBorderDebug()
{
    qDebug() << "Border Color changed to: " << myDraw1->getBorderColor();
}

GraphicsObject *MainWindow::getSelectedObject() const
{
    return m_selectedObject;
}

void MainWindow::setSelectedObject(GraphicsObject *selectedObject)
{
    m_selectedObject = selectedObject;
    emit objectRecieved(selectedObject);

}


GraphicsObjectMap *MainWindow::getMygraphicobjects() const
{
    return mygraphicobjects;
}

QPointF *MainWindow::getMySelectedPoint() const
{
    return this->mySelectedPoint;
}

void MainWindow::setMySelectedPoint(QPointF *value)
{
    emit newObjectAdded(*mygraphicobjects);
    mySelectedPoint = value;
}

/**
 * @brief Fill Color debug message
 */
void MainWindow::runFillDebug()
{
    qDebug() << "Fill Color changed to: " << myDraw1->getFillColor();
}


/**
 * @brief Add Object Button
 */
void MainWindow::on_pb_AddObject_clicked()
{
//    GraphicsObject *tempObj;
//    if (myDraw1->getT() != Draw::selectTool)
//    {
//        if (myDraw1->getT() == Draw::rectTool)
//        {
//            tempObj = new Rectangle(ui->sb_x_pos->value(), ui->sb_y_pos->value(), ui->sb_width->value(), ui->sb_heigth->value(), myDraw1->getBorderColor(), myDraw1->getFillColor());
//        }

//        if (myDraw1->getT() == Draw::circleTool)
//        {
//            tempObj = new Circle(ui->sb_x_pos->value(), ui->sb_y_pos->value(), ui->sb_width->value(), ui->sb_heigth->value(), myDraw1->getBorderColor(), myDraw1->getFillColor());
//        }

//        mygraphicobjects->myMap.insert(tempObj->graphicsItem(), tempObj);
//        myGraphicsscene->addItem(tempObj->graphicsItem());
//        //qDebug() << this->getMygraphicobjects()->myMap.last()->name();
//    }
    QGraphicsItem *tempObj;
    if (myDraw1->getT() != Draw::selectTool)
    {
        if (myDraw1->getT() == Draw::rectTool)
        {
            tempObj = new QGraphicsRectItem(ui->sb_x_pos->value(), ui->sb_y_pos->value(), ui->sb_width->value(), ui->sb_heigth->value());
        }

        if (myDraw1->getT() == Draw::circleTool)
        {
            tempObj = new QGraphicsEllipseItem(ui->sb_x_pos->value(), ui->sb_y_pos->value(), ui->sb_width->value(), ui->sb_heigth->value());
        }

        mygraphicobjects->myMap.insert(tempObj, tempObj);
        myGraphicsscene->addItem(tempObj);
        //qDebug() << this->getMygraphicobjects()->myMap.last()->name();
    }
    else
    {
        qDebug("No Tool");
    }
}

/**
 * @brief Manipulates UI
 */
void MainWindow::generateNewUI(Draw::Tool selectedTool)
{
    if (selectedTool != Draw::selectTool) {
        ui->settingsBox->setEnabled(true);
        ui->pb_AddObject->setEnabled(true);
    } else {
        ui->settingsBox->setEnabled(false);
        ui->pb_AddObject->setEnabled(false);
    }
}

/**
 * @brief Switching between active and inactive toolbuttons
 */
void MainWindow::setActiveDrawingTool(Draw::Tool activeDrawingTool)
{
    if (activeDrawingTool != myDraw1->getT()) {
        myDraw1->setT(activeDrawingTool);
        ui->actionSelect_Tool->setChecked(false);
        ui->actionCircle_Tool->setChecked(false);
        ui->actionRectangle_Tool->setChecked(false);

        switch (activeDrawingTool) {
        case Draw::selectTool:
            ui->actionSelect_Tool->setChecked(true);
            break;
        case Draw::lineTool:
            ui->actionCircle_Tool->setChecked(true);
            break;
        case Draw::circleTool:
            ui->actionCircle_Tool->setChecked(true);
            break;
        case Draw::rectTool:
            ui->actionRectangle_Tool->setChecked(true);
            break;
        }
        emit activeDrawingToolChanged(activeDrawingTool);
    }
}

void MainWindow::setSelectedPoint(QPointF selectedPoint)
{
    MainWindow::setMySelectedPoint(&selectedPoint);
    double px = selectedPoint.x();
    double py = selectedPoint.y();
    ui->sb_x_pos->setValue(px);
    ui->sb_y_pos->setValue(py);

    QMap<QGraphicsItem *, GraphicsObject *>::const_iterator i = mygraphicobjects->myMap.constBegin();
    while (i != mygraphicobjects->myMap.constEnd()) {
        QRectF bounds = i.value()->graphicsItem()->boundingRect();
        int height, width;
        height = bounds.height();
        width = bounds.width();
        int x = i.value()->graphicsItem()->pos().x();
        int y = i.value()->graphicsItem()->pos().y();

        if(px >= x && py >= y){
            if(px <= (x+width) && py <= (y+height)){
                ui->objectSettingsWidget->setVisible(true);
                this->setSelectedObject(i.value());
                emit activeDrawingToolChanged(Draw::selectTool);
            }
        }
        ++i;
    }
}

void MainWindow::selectedObjectNameChanged(QString arg1)
{
    this->getSelectedObject()->setName(arg1);
}

void MainWindow::removeCurrentObject()
{
    QMap<QGraphicsItem *, GraphicsObject *>::const_iterator i = mygraphicobjects->myMap.constBegin();
    while (i != mygraphicobjects->myMap.constEnd()) {
        i.value();
        if(this->getSelectedObject()->name() == i.value()->name()
                && this->getSelectedObject()->posX() == i.value()->posX()
                && this->getSelectedObject()->posY() == i.value()->posY())
        {
            mygraphicobjects->myMap.remove(i.key());
            myGraphicsscene->removeItem(this->getSelectedObject()->graphicsItem());
            i = mygraphicobjects->myMap.constEnd();
        } else {
            ++i;
        }
    }
    ui->objectSettingsWidget->setVisible(false);
}

void MainWindow::selectedObjectRotated(int value)
{
    int height, width;
    QRectF bounds = this->getSelectedObject()->graphicsItem()->boundingRect();

    height = bounds.height();
    width = bounds.width();

    this->getSelectedObject()->graphicsItem()->setTransformOriginPoint(width/2, height/2);
    this->getSelectedObject()->graphicsItem()->setRotation(value);
}

void MainWindow::ObjectSettingsClose()
{
    ui->objectSettingsWidget->setVisible(false);
}

Draw *MainWindow::getMyDraw1() const
{
    return myDraw1;
}

/**
 * @brief Manipulates select tool state in menubar
 */
void MainWindow::on_actionSelect_Tool_triggered()
{
    ui->actionLine_Tool->setChecked(false);
    ui->actionCircle_Tool->setChecked(false);
    ui->actionRectangle_Tool->setChecked(false);
    myDraw1->setT(Draw::selectTool);
    emit activeDrawingToolChanged(myDraw1->getT());
}

void MainWindow::on_actionLine_Tool_triggered()
{
    ui->actionSelect_Tool->setChecked(false);
    ui->actionCircle_Tool->setChecked(false);
    ui->actionRectangle_Tool->setChecked(false);
    myDraw1->setT(Draw::lineTool);
    emit activeDrawingToolChanged(myDraw1->getT());
}

/**
 * @brief Manipulates circle tool state in menubar
 */
void MainWindow::on_actionCircle_Tool_triggered()
{
    ui->actionSelect_Tool->setChecked(false);
    ui->actionLine_Tool->setChecked(false);
    ui->actionRectangle_Tool->setChecked(false);
    myDraw1->setT(Draw::circleTool);
    emit activeDrawingToolChanged(myDraw1->getT());
}

/**
 * @brief Manipulates rectangle tool state in menubar
 */
void MainWindow::on_actionRectangle_Tool_triggered()
{
    ui->actionSelect_Tool->setChecked(false);
    ui->actionCircle_Tool->setChecked(false);
    ui->actionLine_Tool->setChecked(false);
    myDraw1->setT(Draw::rectTool);
    emit activeDrawingToolChanged(myDraw1->getT());
}

void MainWindow::on_actionOpen_triggered()
{
    qDebug("Open File");
}

void MainWindow::on_actionSave_triggered()
{
    qDebug("Save File");
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    tutoriallinetool = new TutorialLineTool();
    tutoriallinetool->show();
}
