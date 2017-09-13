#include "mainwindow.h"
#include "welcomedialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    WelcomeDialog welcome;
    w.showMaximized();
    //w.show();
    welcome.show();

    return a.exec();
}
