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

	QString alphabet = "ABCDEFGHIJKL";
	for(unsigned int i = 0; i < dia->getNbRan();i++){
		ui.rangee->addItem((QString)alphabet[i]);
	}
	for(unsigned int i = 1; i <= dia->getNbCol();i++){
		ui.colonne->addItem(QString::number(i));
	}

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

void OthelloQt::jouerCoup(){
	try{
	  bool pion;
	  Position pos;


	  // permet de récupérer la valeur d'un combobox

	  pos.numR = (ui.rangee->itemData(ui.rangee->currentIndex())).toInt();
	  pos.numC = (ui.colonne->itemData(ui.colonne->currentIndex())).toInt();

	  if(ui.blanc->isChecked()){
		  pion = true;
	  }else{
		  pion = false;
	  }
	  othellier->placer(pion, pos);
	}catch(std::logic_error &ex){
		std::string info = ex.what();
	    QString erreur = QString::fromStdString(info);
	    QMessageBox::information((QWidget *)this, "Information", erreur);
	}
}


OthelloQt::~OthelloQt()
{

}
