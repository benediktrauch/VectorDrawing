#ifndef COLORTOOLSELECTOR_H
#define COLORTOOLSELECTOR_H

#include <QWidget>
#include "draw.h"

namespace Ui {
class ColorToolSelector;
}

class ColorToolSelector : public QWidget
{
    Q_OBJECT

signals:
    void activeFillColorToolChanged(QColor fillColor);


public:
    explicit ColorToolSelector(QWidget *parent = 0);
    ~ColorToolSelector();

    QColor fillColor() const;

private:
    Ui::ColorToolSelector *ui;


protected:
    Draw *m_draw;
    QColor m_fillColor;
    QColor m_borderColor;

private slots:
    void on_pb_border_color_clicked();
    void on_pb_fill_color_clicked();

public slots:
    void setFillColor(const QColor &fillColor);

};

#endif // COLORTOOLSELECTOR_H
