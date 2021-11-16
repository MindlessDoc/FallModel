#pragma once

#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QGraphicsItem* item, QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void update();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};
