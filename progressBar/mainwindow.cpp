#include <QKeyEvent>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    ui->groupBox->hide();

    //for progressbar(dowload) without forms and doing in mainwindow
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),
            ui->progressBar_2,SLOT(setValue(int)));
}
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    QObject::eventFilter(watched,event);

    if (event->type()==QEvent::Enter)
    {
        if (watched == ui->pushButton)
        {
            int f =0;
            qDebug()<<"aaaa";
            QKeyEvent * keyEvent= static_cast<QKeyEvent *>(event);
            if(keyEvent->key())
            {
                ui->groupBox->show();
                qDebug()<<"BACKSPECE";
            }
        }
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label_3->setText("HELLO INDIAN MAN!");
}
