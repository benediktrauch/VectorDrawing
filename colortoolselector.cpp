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
    m_draw->setBorderColor(Qt::red);
}

ColorToolSelector::~ColorToolSelector()
{
    delete ui;
}

void ColorToolSelector::on_pb_border_color_clicked()
{
    QColor newColor = QColorDialog::getColor(m_draw->getBorderColor(), this, "Select border color", QColorDialog::ShowAlphaChannel);
    if (newColor.isValid()){
        m_draw->setBorderColor(newColor);
        ui->pb_border_color->setColor(newColor);
        emit activeBorderColorToolChanged(newColor);
    }
}

void ColorToolSelector::on_pb_fill_color_clicked()
{
    QColor newColor = QColorDialog::getColor(m_draw->getFillColor(), this, "Select fill color", QColorDialog::ShowAlphaChannel);
    if (newColor.isValid())
    {
        m_draw->setFillColor(newColor);
        ui->pb_fill_color->setColor(newColor);
        emit activeFillColorToolChanged(newColor);

    }
}
