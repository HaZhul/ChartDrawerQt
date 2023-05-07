#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->timer1 = new QTimer();
    this->timer2 = new QTimer();
    this->timer3 = new QTimer();
    connect(this->timer1, SIGNAL(timeout()),this, SLOT(on_TimerInterrupt1()));
    connect(this->timer2, SIGNAL(timeout()),this, SLOT(on_TimerInterrupt2()));
    connect(this->timer3, SIGNAL(timeout()),this, SLOT(on_TimerInterrupt3()));
    ui->wykres1->addGraph();
    ui->wykres2->addGraph();
    ui->wykres3->addGraph();
    this->StartStop1 = false;
    this->StartStop2 = false;
    this->StartStop3 = false;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer1;
    delete timer2;
}


void MainWindow::on_pushButtonStartWykres1_clicked()
{
    if(this->StartStop1){
        timer1->stop();
        this->StartStop1 = false;
    }
    else{
        timer1->start(10);
        this->StartStop1 = true;
    }

}

void MainWindow::on_pushButtonStartWykres2_clicked()
{
    if(this->StartStop2){
        timer2->stop();
        this->StartStop2 = false;
    }
    else
    {
        timer2->start(10);
        this->StartStop2 = true;
    }

}

void MainWindow::on_pushButtonStartWykres3_clicked()
{
    if(this->StartStop3){
        timer3->stop();
        this->StartStop3 = false;
    }
    else{
        timer3->start(10);
        this->StartStop3 = true;
    }
}


void MainWindow::on_TimerInterrupt1()

{
    static unsigned int licznik = 0;
    static QList<double> time;
    static QList<double> value;
    double t = licznik * 0.01;
    double val = amplitude_2*sin(3.1416*t*frequency_2)+bias_2;
    time.append(t);
    value.append(val);
    ui->wykres1->graph(0)->setData(time.toVector(),value.toVector());
    ui->wykres1->xAxis->setRange(t-range_2,t);
    ui->wykres1->yAxis->setRange(-2-amplitude_2-bias_2,2+amplitude_2+bias_2);
    ui->wykres1->replot();
    licznik++;
}
void MainWindow::on_TimerInterrupt2()
{
    static unsigned int licznik = 0;
    static QList<double> time;
    static QList<double> value;
    double t = licznik * 0.01;
    if(int liczba_calkowita = (licznik%(50/frequency_1)) == 0)
    {
        square = !square;
    }
    if(square == true)
    {
    val_1 = amplitude_1*1+bias_1;
    }
    else
    {
    val_1 = amplitude_1*-1+bias_1;
    }
    time.append(t);
    value.append(val_1);
    ui->wykres2->graph(0)->setData(time.toVector(),value.toVector());
    ui->wykres2->xAxis->setRange(t-range_1,t);
    ui->wykres2->yAxis->setRange(-1-amplitude_1-bias_1,1+amplitude_1+bias_1);
    ui->wykres2->replot();
    licznik++;
}

void MainWindow::on_TimerInterrupt3()

{
    static unsigned int licznik = 0;
    static QList<double> time;
    static QList<double> value;
    double t =licznik * 0.01;
    if(int liczba_calkowita = (licznik%(100/frequency_3)) == 0)
    {
        triange = !triange;
        previus_t_1 = t;
    }
    if(triange == true)
    {
        val_2 = (val_2_1-amplitude_3*(t-previus_t_1)*frequency_3);
    }
    else
    {
        val_2 = (amplitude_3*(t-previus_t_1)*frequency_3)-0.5*amplitude_3+bias_3;
        val_2_1 = val_2;
    }
    time.append(t);
    value.append(val_2);
    ui->wykres3->graph(0)->setData(time.toVector(),value.toVector());

    ui->wykres3->xAxis->setRange(t-range_3,t);
    ui->wykres3->yAxis->setRange(-amplitude_3-bias_3,amplitude_3+bias_3);//-1???
    ui->wykres3->replot();
    licznik++;
}


void MainWindow::on_frequency_1_valueChanged(int value)
{
    frequency_1 = (value*0.09)+1;
    ui->lcd_f_1->display(frequency_1);
}


void MainWindow::on_amplitude_valueChanged(int value)
{
    amplitude_1 = (value * 0.09)+1;
    ui->lcd_a_1->display(amplitude_1);
}


void MainWindow::on_dial_3_valueChanged(int value)
{
    bias_1 = value * 1/10;
    ui->lcd_b_1->display(bias_1);
}


void MainWindow::on_accept_1_clicked()
{
    QString q_range_1 = ui->input_range_1->toPlainText();
    range_1 = q_range_1.toInt();

}


void MainWindow::on_frequency_2_valueChanged(int value)
{
    frequency_2 = (value*0.09)+1;
    ui->lcd_f_2->display(frequency_2);
}


void MainWindow::on_amplitude_2_valueChanged(int value)
{
    amplitude_2 = (value * 0.09)+1;
    ui->lcd_a_2->display(amplitude_2);
}


void MainWindow::on_bias_2_valueChanged(int value)
{
    bias_2 = value * 1/10;
    ui->lcd_b_2->display(bias_2);
}


void MainWindow::on_accept_2_clicked()
{
    QString q_range_2 = ui->input_range_2->toPlainText();
    range_2 = q_range_2.toInt();
}


void MainWindow::on_frequency_3_valueChanged(int value)
{
    frequency_3 = (value*0.09)+1;
    ui->lcd_f_3->display(frequency_3);
}


void MainWindow::on_amplitude_3_valueChanged(int value)
{
    amplitude_3 = (value * 0.09)+1;
    ui->lcd_a_3->display(amplitude_3);
}


void MainWindow::on_bias_3_valueChanged(int value)
{
    bias_3 = value * 1/10;
    ui->lcd_b_3->display(bias_3);
}


void MainWindow::on_accept_3_clicked()
{
    QString q_range_3 = ui->input_range_3->toPlainText();
    range_3 = q_range_3.toInt();
}

