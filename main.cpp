#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QApplication::translate("toplevel", "Pathfinder"));
    w.resize(640, 480);
    w.setMinimumSize(640, 480);
    w.show();
    return a.exec();
}
