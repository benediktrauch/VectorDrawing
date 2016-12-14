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
