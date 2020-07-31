#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*ARRAYS FOR EVERY DAY DATA*/

    QString monday[10], tuesday[10], wednesday[10], thursday[10], friday[10], saturday[10];
    QList<QListWidgetItem *> sat_tasks;

    /*ITERATORS FOR EVERY DAY*/

    int mon_i = 0, tue_i = 0, wed_i = 0, thu_i = 0, fri_i = 0, sat_i = 0;

private slots:
    void on_add_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
