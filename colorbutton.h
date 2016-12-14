#ifndef COLORBUTTON_H
#define COLORBUTTON_H
#include <QPushButton>


class ColorButton : public QPushButton
{
public:
    ColorButton();
    ColorButton(QWidget *parent = 0);
    ColorButton(QColor color, QWidget *parent = 0);

    QColor color() const;
    void setColor(const QColor &color);

protected:
    QColor m_color;

    void paintEvent(QPaintEvent *);
};

#endif // COLORBUTTON_H
