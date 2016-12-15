#include "drawingtoolselector.h"
#include "ui_drawingtoolselector.h"

DrawingToolSelector::DrawingToolSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawingToolSelector)
{
    ui->setupUi(this);
    //connect(&m_activeDrawingTool, SIGNAL(activeDrawingToolChanged(Draw::Tool)), , SLOT(setActiveDrawingTool(Draw::Tool)));
}

DrawingToolSelector::~DrawingToolSelector()
{
    delete ui;
}

void DrawingToolSelector::on_pb_select_clicked()
{
    this->setActiveDrawingTool(Draw::selectTool);
    emit activeDrawingToolChanged(m_activeDrawingTool);
}

void DrawingToolSelector::on_pb_circle_clicked()
{
    this->setActiveDrawingTool(Draw::circleTool);
    emit activeDrawingToolChanged(m_activeDrawingTool);
}

void DrawingToolSelector::on_pb_rect_clicked()
{
    this->setActiveDrawingTool(Draw::rectTool);
    emit activeDrawingToolChanged(m_activeDrawingTool);
}

Draw::Tool DrawingToolSelector::activeDrawingTool() const
{
    return m_activeDrawingTool;
}

void DrawingToolSelector::setActiveDrawingTool(const Draw::Tool &activeDrawingTool)
{

    if (m_activeDrawingTool != activeDrawingTool) {
        ui->pb_select->setChecked(false);
        ui->pb_circle->setChecked(false);
        ui->pb_rect->setChecked(false);

        switch (activeDrawingTool) {
        case Draw::selectTool:
            ui->pb_select->setChecked(true);
            break;
        case Draw::circleTool:
            ui->pb_circle->setChecked(true);
            break;
        case Draw::rectTool:
            ui->pb_rect->setChecked(true);
            break;
        }

        m_activeDrawingTool = activeDrawingTool;
        emit activeDrawingToolChanged(m_activeDrawingTool);
    }

    }


