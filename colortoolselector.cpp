#include "colortoolselector.h"
#include "ui_colortoolselector.h"

#include <QColorDialog>

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

QColor ColorToolSelector::fillColor() const
{
    return m_fillColor;
}

void ColorToolSelector::setFillColor(const QColor &fillColor)
{
    qDebug("Blubbern nochmal");
    if (fillColor != m_draw->getFillColor()) {
        m_draw->setFillColor(fillColor);
        emit activeFillColorToolChanged(m_draw->getFillColor());
    }
}

void ColorToolSelector::on_pb_border_color_clicked()
{

}

void ColorToolSelector::on_pb_fill_color_clicked()
{
    QColor newColor = QColorDialog::getColor(m_draw->getFillColor(), this, "Select fill Color", QColorDialog::ShowAlphaChannel);
    if (newColor.isValid())
    {
        qDebug("valid");
        ui->pb_fill_color->setColor(newColor);
        emit activeFillColorToolChanged(newColor);

    }
}
