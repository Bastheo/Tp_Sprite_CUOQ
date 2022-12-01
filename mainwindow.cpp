#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
 : QMainWindow(parent)
 , ui(new Ui::MainWindow)
{
 ui->setupUi(this);
 scene = new QGraphicsScene(); // création de la zone de graphisme (scene)
 ui->graphicsView->setScene(scene); // On met la scene dans le graphicsView
 scene->addItem(new Sprite()); // On ajoute un sprite à la scene

}

MainWindow::~MainWindow()
{
 delete ui;
}
