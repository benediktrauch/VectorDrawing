#include "welcomedialog.h"
#include "ui_welcomedialog.h"
#include <iostream>
#include <QDebug>

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
    qDebug() << "accept";
    emit showLineTutorialClick();
}

void WelcomeDialog::on_buttonBox_rejected()
{
    qDebug() << "reject";
}

void WelcomeDialog::openLineTutorial()
{
    tutoriallinetool = new TutorialLineTool();
    tutoriallinetool->show();
}
