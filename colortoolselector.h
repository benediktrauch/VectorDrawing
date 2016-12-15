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
    //void activeFillColorToolChanged(m_draw->fillColor);


public:
    explicit ColorToolSelector(QWidget *parent = 0);
    ~ColorToolSelector();

private:
    Ui::ColorToolSelector *ui;


protected:
    Draw *m_draw;

private slots:
    void on_pb_border_color_clicked();
    void on_pb_fill_color_clicked();
};

#endif // COLORTOOLSELECTOR_H
