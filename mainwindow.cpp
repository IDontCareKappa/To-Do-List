#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("To Do List");

    ui->groupBox->setStyleSheet("QGroupBox{ border: none; }\n"
                                "QListWidget{\nborder: none;\ncolor: white; max-width: 160px; min-height: 400px;\n}\n"
                                "QListWidget::item:hover{ background-color: #222222; }"
                                "QListWidget::indicator:checked { background-color: #55ff00; }\n"
                                "QListWidget::item:selected{ color: white; border: none; }");
    ui->listWidget->setWordWrap(true);
    ui->listWidget->setTextElideMode(Qt::ElideNone);
    ui->groupBox_2->setVisible(0);


    QFile file("data.txt");
    if( file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        QTextStream stream(&file);
        int i;

        //Monday
        stream >> i;
        qDebug() << QString::number(i);
        while( i > 0 )
        {
            QString task;
            //stream >> task;
            task = stream.readLine();

            if( task != "" && mon_i < 10 )
            {
                QListWidgetItem *item = new QListWidgetItem;
                item->setText(task);
                item->setCheckState(Qt::Unchecked);
                ui->listWidget->addItem(item);

                monday[mon_i] = task;
                mon_i++;
            }
            i--;
        }

        //Tuesday
        stream >> i;
        qDebug() << QString::number(i);
        while( i > 0 )
        {
            QString task;
            task = stream.readLine();

            if( task != "" && tue_i < 10 )
            {
                QListWidgetItem *item = new QListWidgetItem;
                item->setText(task);
                item->setCheckState(Qt::Unchecked);

                ui->listWidget_2->addItem(item);

                tuesday[tue_i] = task;
                tue_i++;
            }
            i--;
        }

        //Wednesday
        stream >> i;
        qDebug() << QString::number(i);
        while( i > 0 )
        {
            QString task;
            task = stream.readLine();

            if( task != "" && wed_i < 10 )
            {
                QListWidgetItem *item = new QListWidgetItem;
                item->setText(task);
                item->setCheckState(Qt::Unchecked);

                ui->listWidget_3->addItem(item);

                wednesday[wed_i] = task;
                wed_i++;
            }
            i--;
        }

        //Thursday
        stream >> i;
        qDebug() << QString::number(i);
        while( i > 0 ) {
            QString task;
            task = stream.readLine();

            if( task != "" && thu_i < 10 )
            {
                QListWidgetItem *item = new QListWidgetItem;
                item->setText(task);
                item->setCheckState(Qt::Unchecked);

                ui->listWidget_4->addItem(item);

                thursday[thu_i] = task;
                thu_i++;
            }
            i--;
        }

        //Friday
        stream >> i;
        qDebug() << QString::number(i);
        while( i > 0 ) {
            QString task;
            task = stream.readLine();

            if( task != "" && fri_i < 10 )
            {
                QListWidgetItem *item = new QListWidgetItem;
                item->setText(task);
                item->setCheckState(Qt::Unchecked);

                ui->listWidget_5->addItem(item);

                friday[fri_i] = task;
                fri_i++;
            }
            i--;
        }

        //Saturday
        stream >> i;
        qDebug() << QString::number(i);
        while( i > 0 ){
            QString task;
            task = stream.readLine();

            if( task != "" && sat_i < 10 )
            {
                QListWidgetItem *item = new QListWidgetItem;
                item->setText(task);
                item->setCheckState(Qt::Unchecked);

                ui->listWidget_6->addItem(item);

                sat_tasks[sat_i] = item;
                saturday[sat_i] = task;
                sat_i++;
            }
            i--;
        }

        file.close();
    }
}

MainWindow::~MainWindow()
{
    QFile file("data.txt");
    if( file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        QTextStream stream(&file);
        int i = 0;
        stream.skipWhiteSpace();
        stream << mon_i+1 << "\n";
        while(i < mon_i)
        {
            stream << monday[i] << "\n";
            i++;
        }
        i = 0;
        stream << tue_i+1 << "\n";
        while(i < tue_i)
        {
            stream << tuesday[i] << "\n";
            i++;
        }
        i = 0;
        stream << wed_i+1 << "\n";
        while(i < wed_i)
        {
            stream << wednesday[i] << "\n";
            i++;
        }
        i = 0;
        stream << thu_i+1 << "\n";
        while(i < thu_i)
        {
            stream << thursday[i] << "\n";
            i++;
        }
        i = 0;
        stream << fri_i+1 << "\n";
        while(i < fri_i)
        {
            stream << friday[i] << "\n";
            i++;
        }
        i = 0;
        stream << sat_i+1 << "\n";
        while(i < sat_i)
        {
            stream << saturday[i] << "\n";
            i++;
        }
        file.close();
    }
    delete ui;
}


void MainWindow::on_add_clicked()
{
    ui->groupBox_2->setVisible(1);
}

void MainWindow::on_pushButton_clicked()
{
    QString task = ui->lineEdit->text();
    ui->lineEdit->setText("");

    if( task != "" && mon_i < 10 )
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(task);
        item->setCheckState(Qt::Unchecked);

        ui->listWidget->addItem(item);
        ui->groupBox_2->setVisible(0);

        monday[mon_i] = task;
        mon_i++;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString task = ui->lineEdit_2->text();
    ui->lineEdit_2->setText("");

    if( task != "" && tue_i < 10 )
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(task);
        item->setCheckState(Qt::Unchecked);

        ui->listWidget_2->addItem(item);
        ui->groupBox_2->setVisible(0);

        tuesday[tue_i] = task;
        tue_i++;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString task = ui->lineEdit_3->text();
    ui->lineEdit_3->setText("");

    if( task != "" && wed_i < 10 )
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(task);
        item->setCheckState(Qt::Unchecked);

        ui->listWidget_3->addItem(item);
        ui->groupBox_2->setVisible(0);

        wednesday[wed_i] = task;
        wed_i++;
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString task = ui->lineEdit_4->text();
    ui->lineEdit_4->setText("");

    if( task != "" && thu_i < 10 )
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(task);
        item->setCheckState(Qt::Unchecked);

        ui->listWidget_4->addItem(item);
        ui->groupBox_2->setVisible(0);

        thursday[thu_i] = task;
        thu_i++;
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QString task = ui->lineEdit_5->text();
    ui->lineEdit_5->setText("");

    if( task != "" && fri_i < 10 )
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(task);
        item->setCheckState(Qt::Unchecked);

        ui->listWidget_5->addItem(item);
        ui->groupBox_2->setVisible(0);

        friday[fri_i] = task;
        fri_i++;
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    QString task = ui->lineEdit_6->text();
    ui->lineEdit_6->setText("");

    if( task != "" && sat_i < 10 )
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(task);
        item->setCheckState(Qt::Unchecked);

        ui->listWidget_6->addItem(item);
        ui->groupBox_2->setVisible(0);

        sat_tasks[sat_i] = item;

        saturday[sat_i] = task;
        sat_i++;
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    /*ui->groupBox->setStyleSheet("QGroupBox{ border: none; }\n"
                                "QListWidget{\nborder: none;\ncolor: white; max-width: 160px; min-height: 400px;\n}\n"
                                "QListWidget::item{ background-color: #333333; }\n"
                                "QListWidget::item:hover{ background-color: #222222; border: 1px solid red; }"
                                "QListWidget::indicator:checked { background-color: #55ff00; }\n"
                                "QListWidget::item:selected{ color: white; border: none; }");

    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    QList<QListWidgetItem*> items2 = ui->listWidget_2->selectedItems();
    QList<QListWidgetItem*> items3 = ui->listWidget_3->selectedItems();
    QList<QListWidgetItem*> items4 = ui->listWidget_4->selectedItems();
    QList<QListWidgetItem*> items5 = ui->listWidget_5->selectedItems();
    QList<QListWidgetItem*> items6 = ui->listWidget_6->selectedItems();*/



    for(int i=ui->listWidget->model()->rowCount()-1;i>=0;--i){
        if(ui->listWidget->model()->index(i,0).data(Qt::CheckStateRole).toInt()==Qt::Checked){
            ui->listWidget->model()->removeRow(i);
            monday[i].clear();
        }
    }
    for(int i=ui->listWidget_2->model()->rowCount()-1;i>=0;--i){
        if(ui->listWidget_2->model()->index(i,0).data(Qt::CheckStateRole).toInt()==Qt::Checked){
            ui->listWidget_2->model()->removeRow(i);
            tuesday[i].clear();
        }
    }
    for(int i=ui->listWidget_3->model()->rowCount()-1;i>=0;--i){
        if(ui->listWidget_3->model()->index(i,0).data(Qt::CheckStateRole).toInt()==Qt::Checked){
            ui->listWidget_3->model()->removeRow(i);
            wednesday[i].clear();
        }
    }
    for(int i=ui->listWidget_4->model()->rowCount()-1;i>=0;--i){
        if(ui->listWidget_4->model()->index(i,0).data(Qt::CheckStateRole).toInt()==Qt::Checked){
            ui->listWidget_4->model()->removeRow(i);
            thursday[i].clear();
        }
    }
    for(int i=ui->listWidget_5->model()->rowCount()-1;i>=0;--i){
        if(ui->listWidget_5->model()->index(i,0).data(Qt::CheckStateRole).toInt()==Qt::Checked){
            ui->listWidget_5->model()->removeRow(i);
            friday[i].clear();
        }
    }
    for(int i=ui->listWidget_6->model()->rowCount()-1;i>=0;--i){
        if(ui->listWidget_6->model()->index(i,0).data(Qt::CheckStateRole).toInt()==Qt::Checked){
            ui->listWidget_6->model()->removeRow(i);
            saturday[i].clear();
        }
    }

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->groupBox_2->setVisible(0);
}
