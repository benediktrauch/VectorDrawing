#ifndef DRAWINGTOOLSELECTOR_H
#define DRAWINGTOOLSELECTOR_H

#include <QWidget>

#include<draw.h>

namespace Ui {
class DrawingToolSelector;
}

class DrawingToolSelector : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingToolSelector(QWidget *parent = 0);
    ~DrawingToolSelector();

    Draw::Tool activeDrawingTool() const;

signals:
    void activeDrawingToolChanged(Draw::Tool activeDrawingTool);

public slots:
    void setActiveDrawingTool(const Draw::Tool &activeDrawingTool);

private slots:

    void on_pb_select_clicked();

    void on_pb_circle_clicked();

    void on_pb_rect_clicked();

    void on_pb_line_clicked();

private:
    Ui::DrawingToolSelector *ui;

protected:
    Draw::Tool m_activeDrawingTool;
};

#endif // DRAWINGTOOLSELECTOR_H
