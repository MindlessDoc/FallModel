#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "physicalbody.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    ui->approximateView->setScene(scene);

    this->resize(1200,800);

    scene->addLine(-200, 100, 200, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitPhysicalBody(PhysicalBody *physicalBody)
{
    physicalBody->Init()
    scene->addItem(physicalBody->GetAvatar());
}

void MainWindow::update()
{
    scene->update();
}

QPushButton* MainWindow::GetStartButton()
{
    return ui->startButtom;
}

//Ui::MainWindow* MainWindow::GetUI()
//{
//    return ui;
//}

//void MainWindow::AddPhysicalBody(GraphicRect* graphicRect)
//{

//}


void MainWindow::on_beginButtom_clicked()
{

}

