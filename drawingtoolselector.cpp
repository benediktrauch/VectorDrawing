#include "drawingtoolselector.h"
#include "ui_drawingtoolselector.h"

DrawingToolSelector::DrawingToolSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawingToolSelector)
{
    ui->setupUi(this);
}

DrawingToolSelector::~DrawingToolSelector()
{
    delete ui;
}

void DrawingToolSelector::on_pb_select_clicked()
{
    if(m_activeDrawingTool != Draw::selectTool){
        this->setActiveDrawingTool(Draw::selectTool);
        emit activeDrawingToolChanged(m_activeDrawingTool);


    }
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
    m_activeDrawingTool = activeDrawingTool;
}
