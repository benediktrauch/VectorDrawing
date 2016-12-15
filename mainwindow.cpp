#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <draw.h>
#include <QtDebug>
#include <QColorDialog>


/**
 * @brief Creates new Window, binds Scene Object to graphicsView, sets background-color
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    myDraw1 = new Draw();


    connect(ui->drawingToolSelector, SIGNAL(activeDrawingToolChanged(Draw::Tool)), myDraw1, SLOT(setActiveDrawingTool(Draw::Tool)));
    connect(myDraw1, SIGNAL(activeDrawingToolChanged(Draw::Tool)), ui->drawingToolSelector, SLOT(setActiveDrawingTool(Draw::Tool)));



    mygraphicobjects = new GraphicsObjectMap();
    myGraphicsscene = new GraphicsScene();

    //ui->pb_AddObject->setEnabled(false);
    //ui->groupBox_4->setEnabled(false);
    //ui->groupBox_5->setEnabled(false);
    ui->graphicsView->setScene(myGraphicsscene);

    myDraw1->setT(Draw::selectTool);
    myDraw1->setFillColor(Qt::red);
    myDraw1->setBorderColor(Qt::red);
    ui->graphicsView->setSceneRect(0,0,700,650);
    //ui->pb_fill_color->setStyleSheet("background-color: rgb(255, 0, 0)");
    //ui->pb_border_color->setStyleSheet("background-color: rgb(255, 0, 0)");
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

//void MainWindow::on_pb_circle_clicked()
//{
//    myDraw1->setT(Draw::circleTool);
//    ui->pb_AddObject->setEnabled(true);
//    ui->groupBox_4->setEnabled(true);
//    ui->groupBox_5->setEnabled(true);

//}

//void MainWindow::on_pb_rect_clicked()
//{
//    myDraw1->setT(Draw::rectTool);
//    ui->pb_AddObject->setEnabled(true);
//    ui->groupBox_4->setEnabled(true);
//    ui->groupBox_5->setEnabled(true);
//}


//void MainWindow::on_pb_select_clicked()
//{
//    myDraw1->setT(Draw::selectTool);
//    ui->pb_AddObject->setEnabled(false);
//    ui->groupBox_4->setEnabled(false);
//    ui->groupBox_5->setEnabled(false);

//}

void MainWindow::on_pb_returnobj_clicked()
{
    mygraphicobjects->PrintObjects();
}

/**
 * @brief Colordialog for fillcolor, writes new color to draw object, changes button color to picked color
 */
//void MainWindow::on_pb_fill_color_clicked()
//{
//    QColor newColor = QColorDialog::getColor(myDraw1->getFillColor(), this, "Select fill Color", QColorDialog::ShowAlphaChannel);
//    if (newColor.isValid())
//    {
//        ui->pb_fill_color->setColor(newColor);
//        myDraw1->setFillColor(newColor);

//    }
//}

///**
// * @brief Colordialog for bordercolor, writes new color to draw object, changes button color to picked color
// */
//void MainWindow::on_pb_border_color_clicked()
//{
//    QColor newColor = QColorDialog::getColor(myDraw1->getBorderColor(), this, "Select border Color", QColorDialog::ShowAlphaChannel);
//    if (newColor.isValid())
//    {
//        ui->pb_border_color->setColor(newColor);
//        myDraw1->setBorderColor(newColor);

//    }
//}
