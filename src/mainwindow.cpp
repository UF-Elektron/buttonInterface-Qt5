#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    step(0)
{   
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::clog << "left button clicked\n";
}

void MainWindow::on_pushButton_pressed()
{
    timer.start(100, this);
    std::clog << "left button pressed\n";
}

void MainWindow::on_pushButton_released()
{
    timer.stop();
    std::clog << "left button released\n";
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    std::clog << "timer event\n";
    if (event->timerId() == timer.timerId()) {
        ++step;
    } else {
        std::clog << "?? ??\n";
        QWidget::timerEvent(event);
    }
    std::clog << "Step: "<< step <<"\n";
}
