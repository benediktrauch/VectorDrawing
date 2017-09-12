#ifndef TUTORIALLINETOOL_H
#define TUTORIALLINETOOL_H

#include <QDialog>

namespace Ui {
class TutorialLineTool;
}

class TutorialLineTool : public QDialog
{
    Q_OBJECT

public:
    explicit TutorialLineTool(QWidget *parent = 0);
    ~TutorialLineTool();

private:
    Ui::TutorialLineTool *ui;
};

#endif // TUTORIALLINETOOL_H
