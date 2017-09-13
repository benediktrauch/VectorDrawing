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
    #include "graphicsobject.h"
#include "objectsettings.h"
#include "tutoriallinetool.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Draw *getMyDraw1() const;

    QPointF *getMySelectedPoint() const;
    void setMySelectedPoint(QPointF *value);

    GraphicsObjectMap *getMygraphicobjects() const;

    GraphicsObject *getSelectedObject() const;
    void setSelectedObject(GraphicsObject *selectedObject);

signals:
    void activeDrawingToolChanged(Draw::Tool activeDrawingTool);
    void newObjectAdded(GraphicsObjectMap newObject);
    void objectRecieved(GraphicsObject *myObject);

private slots:
    void on_pb_AddObject_clicked();
    void on_actionCircle_Tool_triggered();
    void on_actionExit_triggered();
    void on_actionRectangle_Tool_triggered();
    void on_actionSelect_Tool_triggered();
    void on_actionLine_Tool_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_pushButton_2_clicked();

public slots:
    void generateNewUI(Draw::Tool selectedTool);
    void setActiveDrawingTool(Draw::Tool activeDrawingTool);
    void setSelectedPoint(QPointF selectedPoint);
    void selectedObjectNameChanged(QString arg1);
    void removeCurrentObject();
    void selectedObjectRotated(int value);
    void ObjectSettingsClose();

private:
    Ui::MainWindow *ui;
    Draw *myDraw1;
    GraphicsScene *myGraphicsscene;

    void runFillDebug();
    void runBorderDebug();

    QPointF *mySelectedPoint;
    GraphicsObjectMap *mygraphicobjects;
    GraphicsObject *m_selectedObject;
    TutorialLineTool *tutoriallinetool;

};

#endif // MAINWINDOW_H
