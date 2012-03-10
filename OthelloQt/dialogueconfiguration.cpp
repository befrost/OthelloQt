#include "dialogueconfiguration.h"

dialogueConfiguration::dialogueConfiguration(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	nbRan = 8;
	nbCol = 8;
	creerAction();
}

void dialogueConfiguration::creerAction(){
	QObject::connect(ui.cancel, SIGNAL(pressed()), this, SLOT(reject()));
	QObject::connect(ui.ok, SIGNAL(pressed()), this, SLOT(accept()));
	QObject::connect(ui.nbCol, SIGNAL(valueChanged(int)), this, SLOT(setNbColonnes(int)));
	QObject::connect(ui.nbRan, SIGNAL(valueChanged(int)), this, SLOT(setNbRangees(int)));
}

void dialogueConfiguration::setNbRangees(int nb){
    nbRan = nb;
}

void dialogueConfiguration::setNbColonnes(int nb){
    nbCol = nb;
}


unsigned dialogueConfiguration::getNbCol(){
	return nbCol;
}

unsigned dialogueConfiguration::getNbRan(){
	return nbRan;
}


dialogueConfiguration::~dialogueConfiguration()
{

}
