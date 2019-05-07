#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBasicTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void timerEvent(QTimerEvent *event) override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_5_clicked();

    void on_pushButton_5_pressed();

    void on_pushButton_5_released();

    void on_pushButton_4_pressed();

    void on_pushButton_4_released();

    void on_pushButton_6_pressed();

    void on_pushButton_6_released();

    void on_toolButton_pressed();

    void on_toolButton_released();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_toolButton_clicked();

    void on_pushButton_7_toggled(bool checked);

    void on_pushButton_7_pressed();

    void on_pushButton_8_pressed();

private:
    Ui::MainWindow *ui;
    QBasicTimer timerM;
    QBasicTimer timer1;
    QBasicTimer timer4;
    QBasicTimer timer5;
    QBasicTimer timer6;
    QBasicTimer timer7;
    int step;
    QBasicTimer globalTimer;
    int globalTicks;
};

#endif // MAINWINDOW_H
