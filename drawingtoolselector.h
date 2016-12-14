#ifndef DRAWINGTOOLSELECTOR_H
#define DRAWINGTOOLSELECTOR_H

#include <QWidget>

namespace Ui {
class DrawingToolSelector;
}

class DrawingToolSelector : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingToolSelector(QWidget *parent = 0);
    ~DrawingToolSelector();

private:
    Ui::DrawingToolSelector *ui;
};

#endif // DRAWINGTOOLSELECTOR_H
