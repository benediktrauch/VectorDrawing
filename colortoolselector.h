#ifndef COLORTOOLSELECTOR_H
#define COLORTOOLSELECTOR_H

#include <QWidget>

namespace Ui {
class ColorToolSelector;
}

class ColorToolSelector : public QWidget
{
    Q_OBJECT

public:
    explicit ColorToolSelector(QWidget *parent = 0);
    ~ColorToolSelector();

private:
    Ui::ColorToolSelector *ui;
};

#endif // COLORTOOLSELECTOR_H
