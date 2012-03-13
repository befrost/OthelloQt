#include "othelloqt.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OthelloQt w;
    w.show();
    return a.exec();
}

void test(){

}
