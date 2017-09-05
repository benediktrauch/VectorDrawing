#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgraphicsscene.h"

#include <iostream>
#include <QString>
#include <draw.h>
#include <QtDebug>
#include <QColorDialog>
#include <QColor>
#include <QGraphicsSceneMouseEvent>

/**
 * @brief Creates new Window, binds Scene Object to graphicsView, sets background-color, connetion between tools/colors and mainwindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myDraw1 = new Draw();

    //Connections for tools
    connect(ui->drawingToolSelector, SIGNAL(activeDrawingToolChanged(Draw::Tool)), this, SLOT(generateNewUI(Draw::Tool)));
    connect(ui->drawingToolSelector, SIGNAL(activeDrawingToolChanged(Draw::Tool)), this, SLOT(setActiveDrawingTool(Draw::Tool)));
    connect(this, SIGNAL(activeDrawingToolChanged(Draw::Tool)), ui->drawingToolSelector, SLOT(setActiveDrawingTool(Draw::Tool)));

    //Connection for colors
    connect(ui->colorToolSelector, SIGNAL(activeFillColorToolChanged(QColor)), myDraw1, SLOT(setFillColor(QColor)));
    connect(ui->colorToolSelector, SIGNAL(activeBorderColorToolChanged(QColor)), myDraw1, SLOT(setBorderColor(QColor)));

    mygraphicobjects = new GraphicsObjectMap();
    myGraphicsscene = new GraphicsScene();

    ui->pb_AddObject->setEnabled(false);
    ui->settingsBox->setEnabled(false);

    ui->graphicsView->setScene(myGraphicsscene);

    myDraw1->setT(Draw::selectTool);
    myDraw1->setFillColor(Qt::red);
    myDraw1->setBorderColor(Qt::red);
    ui->graphicsView->setSceneRect(0,0,700,650);

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
    GraphicsObject *tempObj;
    if (myDraw1->getT() != Draw::selectTool)
    {
        if (myDraw1->getT() == Draw::rectTool)
        {            
            tempObj = new Rectangle(ui->sb_x_pos->value(), ui->sb_y_pos->value(), ui->sb_width->value(), ui->sb_heigth->value(), myDraw1->getBorderColor(), myDraw1->getFillColor());
        }

        if (myDraw1->getT() == Draw::circleTool)
        {
            tempObj = new Circle(ui->sb_x_pos->value(), ui->sb_y_pos->value(), ui->sb_width->value(), ui->sb_heigth->value(), myDraw1->getBorderColor(), myDraw1->getFillColor());
        }
        mygraphicobjects->myMap.insert(tempObj->graphicsItem(), tempObj);
        myGraphicsscene->addItem(tempObj->graphicsItem());
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


Draw *MainWindow::getMyDraw1() const
{
    return myDraw1;
}

/**
 * @brief Manipulates select tool state in menubar
 */
void MainWindow::on_actionSelect_Tool_triggered()
{
    ui->actionCircle_Tool->setChecked(false);
    ui->actionRectangle_Tool->setChecked(false);
    myDraw1->setT(Draw::selectTool);
    emit activeDrawingToolChanged(myDraw1->getT());
}

/**
 * @brief Manipulates circle tool state in menubar
 */
void MainWindow::on_actionCircle_Tool_triggered()
{
    ui->actionSelect_Tool->setChecked(false);
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
