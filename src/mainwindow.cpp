#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"
#include "../../lisa_design/UIrework/src/main.h"

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

void MainWindow::timerEvent(QTimerEvent *event)
{
//    std::clog << "timer event\n";
    if (event->timerId() == timer.timerId()) {
        ++step;
    } else {
        std::clog << "?? ??\n";
        QWidget::timerEvent(event);
    }
//    std::clog << "Step: "<< step <<"\n";
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_pressed()
{
    step = 0;
    timer.start(100, this);
}

void MainWindow::on_pushButton_released()
{
    timer.stop();
    if(step < 3) {
        std::clog << "PB_A1 short press\n";
        buttonWrapper(0, 30);
    } else if(step >= 3) {
        std::clog << "PB_A1 long press\n";
        buttonWrapper(0, 80);
    }
}

void MainWindow::on_pushButton_5_clicked()
{

}

void MainWindow::on_pushButton_5_pressed()
{
    step = 0;
    timer.start(100, this);
}

void MainWindow::on_pushButton_5_released()
{
    timer.stop();
    if(step < 3) {
        std::clog << "PB_A2 short press\n";
        buttonWrapper(1, 30);
    } else if(step >= 3) {
        std::clog << "PB_A2 long press\n";
        buttonWrapper(1, 80);
    }
}


void MainWindow::on_pushButton_4_pressed()
{
    step = 0;
    timer.start(100, this);
}


void MainWindow::on_pushButton_4_released()
{
    timer.stop();
    if(step < 3) {
        std::clog << "PB_B1 short press\n";
        buttonWrapper(2, 30);
    } else if(step >= 3) {
        std::clog << "PB_B1 long press\n";
        buttonWrapper(2, 80);
    }
}

void MainWindow::on_pushButton_6_pressed()
{
    step = 0;
    timer.start(100, this);
}

void MainWindow::on_pushButton_6_released()
{
    timer.stop();
    if(step < 3) {
        std::clog << "PB_B2 short press\n";
        buttonWrapper(3, 30);
    } else if(step >= 3) {
        std::clog << "PB_B2 long press\n";
        buttonWrapper(3, 80);
    }
}

void MainWindow::on_toolButton_pressed()
{
    step = 0;
    timer.start(100, this);
}

void MainWindow::on_toolButton_released()
{
    timer.stop();
    if(step < 3) {
        std::clog << "Magnet short 'press'\n";
        magnetWrapper(200);
    } else if(step >= 3) {
        std::clog << "Magnet long 'press'\n";
        magnetWrapper(800);
    }
}
