#include "othelloqt.h"


OthelloQt::OthelloQt(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	ui.frame->hide();								//cache les contrôles car aucune partie lancée
	ui.actionNouveau->setShortcut(QKeySequence(tr("Ctrl+N")));
	ui.actionQuitter->setShortcut(QKeySequence(tr("Ctrl+Q")));
	ui.actionFermer->setShortcut(QKeySequence(tr("Ctrl+F")));
	ui.actionTexte->setShortcut(QKeySequence(tr("Ctrl+T")));
	ui.actionOthello->setShortcut(QKeySequence(tr("Ctrl+R")));
	ui.actionAuteur->setShortcut(QKeySequence(tr("Ctrl+A")));
	creerAction();
}

void OthelloQt::creerAction(){
	connect(ui.actionNouveau, SIGNAL(triggered(bool)), this, SLOT(nouvellePartie()));
	connect(ui.placer, SIGNAL(clicked()), this, SLOT(jouerCoup()));
	connect(ui.actionQuitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
	connect(ui.actionFermer, SIGNAL(triggered(bool)), this, SLOT(fermerPartie()));
	connect(ui.actionTexte, SIGNAL(triggered(bool)), this, SLOT(obsTexte(bool)));
	connect(ui.actionAuteur, SIGNAL(triggered(bool)), this, SLOT(auteur()));
	connect(ui.actionOthello, SIGNAL(triggered(bool)), this, SLOT(regles()));

}

void OthelloQt::nouvellePartie(){
	dia = new dialogueConfiguration(this);
	//dia->show();
	//on regarde comment la fenêtre s'est fermée
	int retour = dia->exec();


	QString alphabet = "ABCDEFGHIJKL";
	for(unsigned int i = 0; i < dia->getNbCol();i++){
		ui.colonne->addItem((QString)alphabet[i]);
	}
	for(unsigned int i = 1; i <= dia->getNbRan();i++){
		ui.rangee->addItem(QString::number(i));
	}


	// Ca s'est déroulé correctement
	if(retour == 1){
		// On active le menu observateur
		ui.menuObservateurs->setEnabled(true);
		ui.frame->setEnabled(true);
		ui.actionNouveau->setEnabled(false);
		ui.actionFermer->setEnabled(true);

		try{
			othellier = new Othello(dia->getNbRan(),dia->getNbCol());
			ui.frame->show();
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
	ui.frame->hide();						//cache les contrôles
	obsTxt->hide();							//cache l'observateur
	ui.actionTexte->setChecked(false);		//décoche l'observateur
	ui.actionFermer->setEnabled(false);
	ui.menuObservateurs->setEnabled(false);
	ui.actionNouveau->setEnabled(true);
	ui.frame->setEnabled(false);
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
	if(othellier->aQuiLeTour() == 1){
		ui.blanc->setChecked(true);
	}else{
		ui.noir->setChecked(true);
    }
}

void OthelloQt::obsTexte(bool actif){
	  if(actif){
		  //if(obsTxt == 0){
		  obsTxt = new observateurTexte(othellier, this->pos());
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

void OthelloQt::auteur(){
	QMessageBox::information((QWidget *)this, "Auteurs", "Jean Sebastien Maya Bravo <p> Arnaud Hinderickx");

}

void OthelloQt::regles(){
   QString message;
	message = "<p>Il s'agit d'un jeu opposant deux joueurs: ";
	message += "le joueur aux pions blancs et le joueurs aux pions noirs. ";
	message += "En fait, chaque pion a une face de chaque couleur.</p>";
	message +=
			"<p> Chaque joueur essaye de placer un pion de sa couleur, sur une case vide :";
	message +=
			"<ul> <p> -adjacente à une case contenant un pion de l'autre couleur,</p>";
	message +=
			"<p> -de manière à ce que ce pion placé encadreavec un autre pion";
	message +=
			"de la même couleur 1 ou plusieurs pions de l'autre couleur.</p>";
	message +=
			"<p><i> L'encadreement ne peut contenir de cases vides et peut se faire";
	message += "horizontalement, verticalement ou en diagonale.";
	message += "les pions encadrés sont ensuite retournées.</i></p></ul>";
	message +=
			"<p> Chaque joueur joue à son tour. C'est toujours le joueur noir qui commence.</p>";
	message += "<p> Quand un joueur ne peut pas jouer, il passe son tour.</p>";
	message +=
			"<p> Quand plus aucun joueur ne peut jouer, le jeu est terminé.</p>";
	message +=
			"<p> Le nombre de pion de chaque couleur détermine le vainqueur.</p>";
	message +=
			"<p><a href=\"http://www.ffothello.org/\">En savoir plus ... </a></p><br/>";
	message += "<p><b>Bon amusement !</b></p>";
	QMessageBox::information((QWidget *)this, "Règles",message);
}

OthelloQt::~OthelloQt()
{

}


