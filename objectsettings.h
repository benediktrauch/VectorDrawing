#ifndef OBJECTSETTINGS_H
#define OBJECTSETTINGS_H

#include <QWidget>
#include "graphicsobject.h"

namespace Ui {
class ObjectSettings;
}

class ObjectSettings : public QWidget
{
    Q_OBJECT

public:
    explicit ObjectSettings(QWidget *parent = 0);
    ~ObjectSettings();

public slots:
    void objectAttributes(GraphicsObject *myObject);

signals:
    void myObjectNameChanged(QString arg1);
    void pb_removeObject();
    void dial_rotationChanged(int value);
    void closeButtonPressed();

private slots:
    void on_le_objectName_textChanged(const QString &arg1);

    void on_pb_deleteObject_clicked();

    void on_dial_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::ObjectSettings *ui;
};

#endif // OBJECTSETTINGS_H
