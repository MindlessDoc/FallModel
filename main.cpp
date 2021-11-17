#include "model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    model.StartGUI();
    //model.StartModel();

    return a.exec();
}
