#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::on_pushButtonNative_clicked()
{
   qDebug() << "native";

   QFileDialog dia(this);
   QString defaultPath = QDir::currentPath();
   QString filename = dia.getOpenFileName(this, tr("test"), defaultPath,
                                          "test (*.*)", 0);
   dia.close();
   qDebug() << filename;
}

void MainWindow::on_pushButtonNonNative_clicked()
{
   qDebug() << "non-native";
   QFileDialog dia(this);
   QString defaultPath = QDir::currentPath();
   QString filename = dia.getOpenFileName(this, tr("test"), defaultPath,
                                          "test (*.*)", 0, QFileDialog::DontUseNativeDialog);
   dia.close();
   qDebug() << filename;
}
