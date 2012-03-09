#include "othelloqt.h"

OthelloQt::OthelloQt(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	creerAction();
}

void OthelloQt::creerAction(){
	//connect(ui.actionNouveau, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
	connect(ui.actionNouveau, SIGNAL(triggered(bool)), this, SLOT(nouvellePartie()));

}

void OthelloQt::nouvellePartie(){
	dia = new dialogueConfiguration();
	dia->show();
    int retour = dia->exec();
}

OthelloQt::~OthelloQt()
{

}
