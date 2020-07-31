#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*QFile file("data.txt");
    if( file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        QTextStream stream(&file);
        int i = 0;
        stream << w.mon_i << endl;
        while(i < w.mon_i)
        {
            stream << w.monday[i] << endl;
            i++;
        }
        file.close();
    }*/

    return a.exec();
}
