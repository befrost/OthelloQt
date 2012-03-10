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
			othellier = new Othello(dia->getNbRan(),dia->getNbCol());

		}catch(std::logic_error &ex){
			    std::string info = ex.what();
				QString erreur = QString::fromStdString(info);
				QMessageBox::information((QWidget *)this, "Information", erreur);
				ui.actionFermer->setEnabled(false);
				ui.menuObservateurs->setEnabled(false);
				ui.actionNouveau->setEnabled(true);
		}


	}

}

// A verifier

void OthelloQt::fermerPartie(){
	othellier = 0;
	delete othellier;
}

OthelloQt::~OthelloQt()
{

}
