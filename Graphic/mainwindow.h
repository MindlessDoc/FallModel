#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include "graphicrect.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPushButton* GetStartButton();
    QPushButton* GetPauseButton();

    void InitPhysicalBodies(PhysicalBody* leftPhysicalBody, PhysicalBody* rightPhysicalBody);
    int GetTimeUpdate();

public slots:
    void update();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *leftScene;
    QGraphicsScene *rightScene;
};
