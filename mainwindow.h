#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonStartWykres1_clicked();

    void on_pushButtonStartWykres2_clicked();

    void on_TimerInterrupt1();
    void on_TimerInterrupt2();
    void on_TimerInterrupt3();

    void on_frequency_1_valueChanged(int value);

    void on_amplitude_valueChanged(int value);

    void on_dial_3_valueChanged(int value);

    void on_accept_1_clicked();

    void on_frequency_2_valueChanged(int value);

    void on_amplitude_2_valueChanged(int value);

    void on_bias_2_valueChanged(int value);

    void on_accept_2_clicked();

    void on_frequency_3_valueChanged(int value);

    void on_amplitude_3_valueChanged(int value);

    void on_bias_3_valueChanged(int value);

    void on_accept_3_clicked();

    void on_pushButtonStartWykres3_clicked();

private:
    Ui::MainWindow *ui;
    QTimer * timer1;
    QTimer * timer2;
    QTimer * timer3;
    bool StartStop1;
    bool StartStop2;
    bool StartStop3;
    int amplitude_1 = 1;
    int frequency_1 = 1;
    int bias_1 = 0;
    int range_1 = 4;
    int amplitude_2 = 1;
    int frequency_2 = 1;
    int bias_2 = 0;
    int range_2 = 4;
    bool square = true;
    int val_1 = 1;
    double val_2_1 = 0;
    int amplitude_3 = 1;
    int frequency_3 = 1;
    int bias_3 = 0;
    int range_3 = 4;
    bool triange = true;
    double val_2 = 1;
    double previus_t_1 = 0;
    double previus_t_2 = 0;

};
#endif // MAINWINDOW_H
