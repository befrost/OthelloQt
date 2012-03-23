#include "dialogueconfiguration.h"
#include <QMessageBox>


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
	QObject::connect(ui.nbCol, SIGNAL(currentIndexChanged(int)), this, SLOT(setNbColonnes(int)));
	QObject::connect(ui.nbRan, SIGNAL(currentIndexChanged(int)), this, SLOT(setNbRangees(int)));
}

void dialogueConfiguration::setNbRangees(int nb){
    nbRan = 4 + nb*2;								//correction de la valeur sur l'index de la comboBox
}

void dialogueConfiguration::setNbColonnes(int nb){
    nbCol = 4 + nb*2;								//correction de la valeur sur l'index de la comboBox
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
