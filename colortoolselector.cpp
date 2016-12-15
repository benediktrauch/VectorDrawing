#include "colortoolselector.h"
#include "ui_colortoolselector.h"

ColorToolSelector::ColorToolSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorToolSelector)
{
    ui->setupUi(this);
    m_draw = new Draw();
}

ColorToolSelector::~ColorToolSelector()
{
    delete ui;
}

void ColorToolSelector::on_pb_border_color_clicked()
{

}

void ColorToolSelector::on_pb_fill_color_clicked()
{

}
