#include "welcomedialog.h"
#include "ui_welcomedialog.h"
#include <iostream>
#include <QDebug>

/**
 * @brief WelcomeDialog::WelcomeDialog
 * @par Window shown on start up
 */
WelcomeDialog::WelcomeDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::WelcomeDialog)
{
    ui->setupUi(this);
    connect(this, SIGNAL(showLineTutorialClick()), this, SLOT(openLineTutorial()));
}

WelcomeDialog::~WelcomeDialog()
{
    delete ui;
}

void WelcomeDialog::on_buttonBox_accepted()
{
    emit showLineTutorialClick();
}

void WelcomeDialog::on_buttonBox_rejected()
{
}

void WelcomeDialog::openLineTutorial()
{
    tutoriallinetool = new TutorialLineTool();
    tutoriallinetool->show();
}
