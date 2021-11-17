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

//    Ui::MainWindow* GetUI();
    QPushButton* GetStartButton();

    void InitPhysicalBody(PhysicalBody* physicalBody);

    //void AddPhysicalBody(GraphicRect* graphicRect);

public slots:
    void update();

private slots:
    void on_beginButtom_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};
