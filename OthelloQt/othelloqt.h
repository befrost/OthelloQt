#ifndef OTHELLOQT_H
#define OTHELLOQT_H

#include <QtGui/QMainWindow>
#include "ui_othelloqt.h"

class OthelloQt : public QMainWindow
{
    Q_OBJECT

public:
    OthelloQt(QWidget *parent = 0);
    ~OthelloQt();

private:
    Ui::OthelloQtClass ui;
};

#endif // OTHELLOQT_H
