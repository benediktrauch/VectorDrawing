#include "colorbutton.h"
#include <QPainter>
#include <QString>
#include <QDebug>


ColorButton::ColorButton()
{

}

ColorButton::ColorButton(QWidget *parent) : QPushButton(parent), m_color(Qt::red)
{

}

ColorButton::ColorButton(QColor color, QWidget *parent) : QPushButton(parent), m_color(color)
{

}

QColor ColorButton::color() const
{
    return m_color;
}

void ColorButton::setColor(const QColor &color)
{
    m_color = color;
}

/**
 * @brief Overrides paintEvent. Sets color to m_color
 * @param paint
 */
void ColorButton::paintEvent(QPaintEvent *paint)
{
    QPushButton::paintEvent(paint);

    QPainter my_p(this);
    my_p.save();


    my_p.setPen(Qt::black);
    my_p.drawRect(0, 0, width()+40, height()+10);

    my_p.fillRect(0, 0, width()+40, height()+10, m_color);
    my_p.restore();
}
