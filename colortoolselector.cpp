#include "colortoolselector.h"
#include "ui_colortoolselector.h"

#include <QColorDialog>

#include <QtDebug>

ColorToolSelector::ColorToolSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorToolSelector)
{
    ui->setupUi(this);
    m_draw = new Draw();
    m_draw->setFillColor(Qt::red);
}

ColorToolSelector::~ColorToolSelector()
{
    delete ui;
}



//void ColorToolSelector::setFillColor(const QColor &fillColor)
//{
//    if (fillColor != m_draw->getFillColor()) {
//        m_draw->setFillColor(fillColor);
//        emit activeFillColorToolChanged(m_draw->getFillColor());
//    }
//}

void ColorToolSelector::on_pb_border_color_clicked()
{

}

void ColorToolSelector::on_pb_fill_color_clicked()
{
    QColor newColor = QColorDialog::getColor(m_draw->getFillColor(), this, "Select fill Color", QColorDialog::ShowAlphaChannel);
    if (newColor.isValid())
    {
        m_draw->setFillColor(newColor);
        ui->pb_fill_color->setColor(newColor);
        emit activeFillColorToolChanged(newColor);

    }
}
