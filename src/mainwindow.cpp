#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"
#include "../../lisa_design/UIrework/src/main.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    step{0},
    globalTicks{0}
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
    if (event->timerId() == timer1.timerId()) {
        ++step;
//        std::clog << "Step: "<< step <<"\n";
        if(step >= 3) {
                //        std::clog << "PB_A1 long press\n";
                        buttonWrapper(0, 80);
        }
    } else if (event->timerId() == timer4.timerId()) {
        ++step;
//        std::clog << "Step: "<< step <<"\n";
        if(step >= 3) {
        //        std::clog << "PB_B1 long press\n";
                buttonWrapper(2, 80);
        }
    } else if (event->timerId() == timer5.timerId()) {
        ++step;
        if(step >= 3) {
        //        std::clog << "PB_A2 long press\n";
                buttonWrapper(1, 80);
        }
//        std::clog << "Step: "<< step <<"\n";
    } else if (event->timerId() == timer6.timerId()) {
        ++step;
//        std::clog << "Step: "<< step <<"\n";
        if(step >= 3) {
        //        std::clog << "PB_B2 long press\n";
                buttonWrapper(3, 80);
        }
    } else if (event->timerId() == timer7.timerId()) {
        ++step;
//        std::clog << "Step: "<< step <<"\n";
    } else if(event->timerId() == globalTimer.timerId()) {
        ++globalTicks;
        if(globalTicks == 5) {
           globalTicks = 0;
           /* start UI timerticks */
           timerTick();
        }
//        std::clog << "Step: "<< globalTicks <<"\n";
    } else if (event->timerId() == timerM.timerId()) {
        ++step;
    } else {
        std::clog << "?? timerID unknown ??\n";
        QWidget::timerEvent(event);
    }

}

void MainWindow::on_pushButton_clicked()
{
    std::clog << "**************************\n";
}

void MainWindow::on_pushButton_pressed()
{
//    std::clog << "PB_A1\n";
    step = 0;
    timer1.start(100, this);
}

void MainWindow::on_pushButton_released()
{
    timer1.stop();
    if(step < 3) {
//        std::clog << "PB_A1 short press\n";
        buttonWrapper(0, 30);
    }
    buttonWrapper(0, 0);
}

void MainWindow::on_pushButton_5_clicked()
{
    std::clog << "**************************\n";
}

void MainWindow::on_pushButton_5_pressed()
{
    step = 0;
    timer5.start(100, this);
}

void MainWindow::on_pushButton_5_released()
{
    timer5.stop();
    if(step < 3) {
//        std::clog << "PB_A2 short press\n";
        buttonWrapper(1, 30);
    }
    buttonWrapper(1, 0);
}


void MainWindow::on_pushButton_4_pressed()
{
    step = 0;
    timer4.start(100, this);
}


void MainWindow::on_pushButton_4_released()
{
    timer4.stop();
    if(step < 3) {
//        std::clog << "PB_B1 short press\n";
        buttonWrapper(2, 30);
    }
        buttonWrapper(2, 0);
}

void MainWindow::on_pushButton_6_pressed()
{
    step = 0;
    timer6.start(100, this);
}

void MainWindow::on_pushButton_6_released()
{
    timer6.stop();
    if(step < 3) {
//        std::clog << "PB_B2 short press\n";
        buttonWrapper(3, 30);
    }
        buttonWrapper(3, 0);
}

void MainWindow::on_toolButton_pressed()
{
    step = 0;
    timerM.start(100, this);
}

void MainWindow::on_toolButton_released()
{
    timerM.stop();
    if(step < 3) {
//        std::clog << "Magnet short 'press'\n";
        magnetWrapper(200);
    } else if(step >= 3) {
//        std::clog << "Magnet long 'press'\n";
        magnetWrapper(800);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    std::clog << "**************************\n";
}

void MainWindow::on_pushButton_4_clicked()
{
    std::clog << "**************************\n";
}

void MainWindow::on_toolButton_clicked()
{
    std::clog << "**************************\n";
}

void MainWindow::on_pushButton_7_toggled(bool checked)
{

}

void MainWindow::on_pushButton_7_pressed()
{
    static bool checked = false;
    if(checked) {
        checked = false;
        std::clog << "Stop timer\n";
        globalTimer.stop();
    } else {
        checked = true;
        std::clog << "Start timer\n";
        globalTimer.start(100, this);
    }
}

void MainWindow::on_pushButton_8_pressed()
{
    printLEDs();
    std::clog << "**************************\n";
}
