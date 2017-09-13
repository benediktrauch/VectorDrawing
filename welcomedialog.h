#ifndef WELCOMEDIALOG_H
#define WELCOMEDIALOG_H

#include <QDialog>
#include "tutoriallinetool.h"

namespace Ui {
class WelcomeDialog;
}

/**
 * @brief The WelcomeDialog class
 */
class WelcomeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomeDialog(QWidget *parent = 0);
    ~WelcomeDialog();

signals:
    void showLineTutorialClick();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void openLineTutorial();

private:
    Ui::WelcomeDialog *ui;
    TutorialLineTool *tutoriallinetool;
};

#endif // WELCOMEDIALOG_H
