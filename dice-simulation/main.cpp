#include "mainwindow.h"

#include <QApplication>
#include <QSoundEffect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Dice simulator");
    w.show();
    return a.exec();
}
