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

    void InitPhysicalBody(PhysicalBody* physicalBody);

public slots:
    void update();

private slots:
    void on_beginButtom_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *approximateScene;
    QGraphicsScene *analyticScene;
};