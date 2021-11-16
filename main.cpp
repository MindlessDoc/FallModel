#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    for(int y = 0; y <= 100; y += 10)
    {
        w.TestDraw(y);
    }

    return a.exec();
}
