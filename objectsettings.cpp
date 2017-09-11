#include "objectsettings.h"
#include "ui_objectsettings.h"
#include "mainwindow.h"
#include <iostream>
#include <QDebug>

ObjectSettings::ObjectSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ObjectSettings)
{
    ui->setupUi(this);

}

ObjectSettings::~ObjectSettings()
{
    delete ui;
}

void ObjectSettings::objectAttributes(GraphicsObject *myObject)
{
    qDebug() << "myObject :" << myObject;
    ui->le_objectName->setText(myObject->name());
}

void ObjectSettings::on_le_objectName_textChanged(const QString &arg1)
{
    emit myObjectNameChanged(arg1);
}

void ObjectSettings::on_pb_deleteObject_clicked()
{
    emit pb_removeObject();
}
