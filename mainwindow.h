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

signals:
    void activeDrawingToolChanged(Draw::Tool activeDrawingTool);


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Draw *getMyDraw1() const;

private slots:

    void on_pb_AddObject_clicked();

    void on_actionCircle_Tool_triggered();

    void on_actionExit_triggered();

    void on_actionRectangle_Tool_triggered();

    void on_actionSelect_Tool_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

public slots:
    void generateNewUI(Draw::Tool selectedTool);
    void setActiveDrawingTool(Draw::Tool activeDrawingTool);


private:
    Ui::MainWindow *ui;
    Draw *myDraw1;
    GraphicsScene *myGraphicsscene;

    void runFillDebug();
    void runBorderDebug();

    GraphicsObjectMap *mygraphicobjects;

};

#endif // MAINWINDOW_H
