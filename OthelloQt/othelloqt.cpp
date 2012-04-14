#include "othelloqt.h"
#include<iostream>


OthelloQt::OthelloQt(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	ui.frame->hide();												//cache les contrôles car aucune partie lancée
	ui.actionNouveau->setShortcut(QKeySequence(tr("Ctrl+N")));
	ui.actionCharger->setShortcut(QKeySequence(tr("Ctrl+C")));
	ui.actionSauver->setShortcut(QKeySequence(tr("Ctrl+S")));
	ui.actionQuitter->setShortcut(QKeySequence(tr("Ctrl+Q")));
	ui.actionFermer->setShortcut(QKeySequence(tr("Ctrl+F")));
	ui.actionTexte->setShortcut(QKeySequence(tr("Ctrl+T")));
	ui.actionExpert->setShortcut(QKeySequence(tr("Ctrl+E")));
	ui.actionOthello->setShortcut(QKeySequence(tr("Ctrl+R")));
	ui.actionAuteur->setShortcut(QKeySequence(tr("Ctrl+A")));
	obsTxt = 0;
	obsExpe = 0;
	creerAction();
}

void OthelloQt::creerAction(){
	connect(ui.actionNouveau, SIGNAL(triggered(bool)), this, SLOT(nouvellePartie()));
	connect(ui.actionSauver, SIGNAL(triggered(bool)), this, SLOT(sauverPartie()));
	connect(ui.actionCharger, SIGNAL(triggered(bool)), this, SLOT(chargerPartie()));
	connect(ui.placer, SIGNAL(clicked()), this, SLOT(jouerCoup()));
	connect(ui.actionQuitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
	connect(ui.actionFermer, SIGNAL(triggered(bool)), this, SLOT(fermerPartie()));
	connect(ui.actionTexte, SIGNAL(triggered(bool)), this, SLOT(obsTexte(bool)));
	connect(ui.actionExpert, SIGNAL(triggered(bool)), this, SLOT(obsExpert(bool)));
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
	ui.frame->hide();							//cache les contrôles
	if(ui.actionTexte->isChecked()){
		obsTxt->hide();							//cache l'observateur
		ui.actionTexte->setChecked(false);		//décoche l'observateur
	}
	if(obsTxt !=0){
		obsTxt = 0 ;							//donne la valeur 0 à l'observateur pour qu'il puisse être recréé.
	}
	ui.actionFermer->setEnabled(false);
	ui.menuObservateurs->setEnabled(false);
	ui.actionNouveau->setEnabled(true);
	ui.frame->setEnabled(false);
	positions.clear();
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
	  noterCoup(pion, pos);
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
	std::cout << actif << std::endl;
	  if(actif){
		  if(obsTxt == 0){														//pour ne pas recréer l'observateur à chaque appel.
			  obsTxt = new observateurTexte(othellier, this->pos());
			  this->attacher(obsTxt);
			  this->notifierChangement();
		  }


		  obsTxt->show();
	  }
	  else
	  {
		  obsTxt->hide();
	  }
}


void OthelloQt::obsExpert(bool actif) {
	std::cout << actif << std::endl;
	ui.centralwidget->hide();
	ui.actionTexte->setEnabled(false);
	if (actif) {

		if (obsExpe == 0) { //pour ne pas recréer l'observateur à chaque appel.

			obsExpe = new observateurExpert(othellier, this->pos());
		}
		obsExpe->show();
	} else {
		obsExpe->hide();
	}
}

void OthelloQt::closeEvent(QCloseEvent *){
	delete obsTxt;
	delete obsExpe;
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
void OthelloQt::noterCoup(bool pionBlanc, Position pos){
	Coup current;
	current.pionBlanc = pionBlanc;
	current.pos = pos;
	this->positions.push_back(current);								//ajoute un coup à la liste des coups joués.
}

void OthelloQt::sauverPartie() {
	QString fileName;
	QString filter = "Othello game (*.oth)";
	fileName = QFileDialog::getSaveFileName(this, tr("Sauvegarder la partie"),  QDir::currentPath(), filter);	//permet de créer un fichier de sauvegarde *.oth
	QFile file(fileName);
	if(!file.open(QIODevice::WriteOnly)) return;
	QDataStream toSave(&file);

	unsigned taille = positions.size();
	Coup current;
	toSave << taille << this->othellier->rangees() << this->othellier->colonnes();			//sauve la taille de la liste et de l'othellier
	for (unsigned i = 0; i < taille; ++ i) {
		current = positions.at(i);
		toSave << current.pionBlanc << current.pos.numC << current.pos.numR;				//sauve chaque coups contenus dans la liste.
	}
	file.close();

	//fileName = QFileDialog::getOpenFileName(this,"Choisir un fichier de mots", QDir::currentPath());

}

void OthelloQt::chargerPartie(){
	bool pionBlanc = true;
	unsigned taille, nbRan, nbCol;
	Coup current;

	QString filter = "Othello game (*.oth)";


	QString fileName=QFileDialog::getOpenFileName(this,"Charger une partie", QDir::currentPath(), filter);			//Permet d'ouvrir un fichier de sauvegarde *.oth
	QFile file(fileName);
	if(!file.open(QIODevice::ReadOnly)) return;
	QDataStream toLoad(&file);
	toLoad >> taille >> nbRan >> nbCol;								// Récupère la taille de la liste des coups joués, et la taille d'othellier.
	if (ui.actionFermer->isEnabled()){
		this->fermerPartie();
	}

	QString alphabet = "ABCDEFGHIJKL";
	ui.colonne->clear();											//remet les comboBox à 0
	ui.rangee->clear();
	for(unsigned int i = 0; i < nbCol;i++){							//remplit les combobox avec les nouvelles dimensions
		ui.colonne->addItem((QString)alphabet[i]);
	}
	for(unsigned int i = 1; i <= nbRan;i++){
		ui.rangee->addItem(QString::number(i));
	}

	ui.menuObservateurs->setEnabled(true);
	ui.frame->setEnabled(true);
	ui.actionNouveau->setEnabled(false);
	ui.actionFermer->setEnabled(true);
		try{														//recrée l'othellier
			this->othellier = new Othello(nbRan,nbCol);
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

	for (unsigned i = 0; i<taille;++i){												//extrait la liste des coups joués
		toLoad >> current.pionBlanc >> current.pos.numC >> current.pos.numR;
		this->positions.push_back(current);
	}
	file.close();
	for (unsigned i = 0; i < taille; ++ i) {										//joue la liste des coups extraits de la sauvegarde
		pionBlanc = positions.at(i).pionBlanc;
		current = positions.at(i);
		this->othellier->placer(current.pionBlanc,current.pos);
	}
}

std::string OthelloQt::coupsToString() {						//Traduit la liste des coups jouées en une liste lisible.
	unsigned taille = positions.size();
	std::stringstream str;
	char col;
	for(unsigned i = 0; i< taille; ++i){
		if (positions.at(i).pionBlanc) {
			str << "blanc : ";
		}else{
			str << "noir  : ";
		}
		switch(positions.at(i).pos.numC){
			case 0 :col = 'A'; break;
			case 1 :col = 'B'; break;
			case 2 :col = 'C'; break;
			case 3 :col = 'D'; break;
			case 4 :col = 'E';break;
			case 5 :col = 'F';break;
			case 6 :col = 'G';break;
			case 7 :col = 'H';break;
			case 8 :col = 'I';break;
			case 9 :col = 'J';break;
			case 10 :col = 'K';break;
			case 11 :col = 'L';break;
			default : col = 'Z'; break;
		}
		str << col << " " << positions.at(i).pos.numR+1 << std::endl ;

	}
	return str.str();
}


