#include "tutoriallinetool.h"
#include "ui_tutoriallinetool.h"

/**
 * @brief TutorialLineTool::TutorialLineTool
 * @par Tutorial
 * Window where programm and buttons are explained
 */
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
