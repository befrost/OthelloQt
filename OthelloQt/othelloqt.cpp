#include "othelloqt.h"


OthelloQt::OthelloQt(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	creerAction();
}

void OthelloQt::creerAction(){
	connect(ui.actionNouveau, SIGNAL(triggered(bool)), this, SLOT(nouvellePartie()));
	connect(ui.placer, SIGNAL(clicked()), this, SLOT(jouerCoup()));
	connect(ui.actionQuitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
	connect(ui.actionFermer, SIGNAL(triggered(bool)), this, SLOT(fermerPartie()));
	connect(ui.actionTexte, SIGNAL(triggered(bool)), this, SLOT(obsTexte(bool)));

}

void OthelloQt::nouvellePartie(){
	dia = new dialogueConfiguration(this);
	dia->show();

	QString alphabet = "ABCDEFGHIJKL";
	for(unsigned int i = 0; i < dia->getNbCol();i++){
		ui.colonne->addItem((QString)alphabet[i]);
	}
	for(unsigned int i = 1; i <= dia->getNbRan();i++){
		ui.rangee->addItem(QString::number(i));
	}

	// on regarde comment la fenêtre s'est fermée
	int retour = dia->exec();

	// Ca s'est déroulé correctement
	if(retour == 1){
		// On active le menu observateur
		ui.menuObservateurs->setEnabled(true);
		ui.frame->setEnabled(true);
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
				ui.frame->setEnabled(false);
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

	  pos.numR = (ui.rangee->currentIndex());
	  pos.numC = (ui.colonne->currentIndex());

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
	this->notifierChangement();
}

void OthelloQt::obsTexte(bool actif){
	  if(actif){
		  //if(obsTxt == 0){
		  obsTxt = new observateurTexte(othellier);
		  this->attacher(obsTxt);
		  this->notifierChangement();

		  //}

		  obsTxt->show();
	  }
	  else
	  {
		  obsTxt->hide();
	  }
}


void OthelloQt::closeEvent(QCloseEvent *){
	delete obsTxt;
}

OthelloQt::~OthelloQt()
{

}
