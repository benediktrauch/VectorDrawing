#include "colortoolselector.h"
#include "ui_colortoolselector.h"

ColorToolSelector::ColorToolSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorToolSelector)
{
    ui->setupUi(this);
}

ColorToolSelector::~ColorToolSelector()
{
    delete ui;
}
