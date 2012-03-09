#include "othelloqt.h"

OthelloQt::OthelloQt(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	creerAction();
}

void OthelloQt::creerAction(){
	connect(ui.actionNouveau, SIGNAL(triggered(bool)), this, SLOT(nouvellePartie()));

}

void OthelloQt::nouvellePartie(){
	dia = new dialogueConfiguration(this);
	dia->show();

	// on regarde comment la fenêtre s'est fermée
	int retour = dia->exec();

	// Ca s'est déroulé correctement
	if(retour == 1){
		// On active le menu observateur
		ui.menuObservateurs->setEnabled(true);
		ui.actionNouveau->setEnabled(false);
		ui.actionFermer->setEnabled(true);

		try{

		}catch(std::string &ex){
				std::string test = ex;
				QString qstr = QString::fromStdString(ex);
				QMessageBox::information((QWidget *)this, "Information", qstr);
		}


	}



}

OthelloQt::~OthelloQt()
{

}
