#include "tutoriallinetool.h"
#include "ui_tutoriallinetool.h"

TutorialLineTool::TutorialLineTool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TutorialLineTool)
{
    ui->setupUi(this);
}

TutorialLineTool::~TutorialLineTool()
{
    delete ui;
}
