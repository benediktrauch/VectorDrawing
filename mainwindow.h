#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "rectangle.h"
#include "circle.h"
#include "draw.h"
#include "graphicsobjectmap.h"
#include "graphicsscene.h"
#include "colorbutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_pb_AddObject_clicked();

    void on_pb_circle_clicked();

    void on_pb_rect_clicked();

    void on_pb_select_clicked();

    void on_pb_returnobj_clicked();

    void on_pb_fill_color_clicked();

    void on_pb_border_color_clicked();

private:
    Ui::MainWindow *ui;
    Draw *myDraw1;
    GraphicsScene *myGraphicsscene;

    //ColorButton *fillColorButton = new ColorButton();
    //ColorButton *borderColorButton = new ColorButton();

    void runFillDebug();
    void runBorderDebug();

    GraphicsObjectMap *mygraphicobjects;

};

#endif // MAINWINDOW_H
