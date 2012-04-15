/*
 * observateurExpert.cpp
 *
 *  Created on: 11 avr. 2012
 *      Author: Administrateur
 */

#include "observateurExpert.h"
#include "sstream"

observateurExpert::observateurExpert() {
	// TODO Auto-generated constructor stub

}

observateurExpert::observateurExpert(Othello * othellier, QPoint pos) :
		QWidget() {
	oth = othellier;
	layoutExpert = new QVBoxLayout(this);
	setWindowTitle("Observateur Expert");
	Qt::WindowFlags flags = 0;
	flags |= Qt::CustomizeWindowHint;
	flags |= Qt::WindowTitleHint;
	setWindowFlags(flags);



	this->move(pos.x() + 300, pos.y() + 300);

	plateau = new QTableWidget(oth->rangees(), oth->colonnes(), this);
	plateau->setStyleSheet("QTableWidget { background-color: #c88954; }");
	plateau->setFixedSize((oth->colonnes() * 56)+24, (oth->rangees() * 56)+28);
	plateau->setHorizontalHeaderLabels((QStringList)"a"<<"b"<<"c"<<"d"<<"e"<<"f"<<"g"<<"h"<<"i"<<"j"<<"k"<<"l");

	for (unsigned i = 0; i < oth->rangees(); i++) {
		plateau->setRowHeight(i, 56);
	}

	for (unsigned i = 0; i < oth->colonnes(); i++) {
		plateau->setColumnWidth(i, 56);
	}

	tab.resize(oth->rangees());
	for (unsigned i = 0; i < oth->rangees(); i++) {
		tab[i].resize(oth->colonnes());
	}

	for (unsigned i = 0; i < oth->rangees(); i++) {
		for (unsigned j = 0; j < oth->colonnes(); j++) {
			tab[i][j] = new QTableWidgetItem();
			tab[i][j]->setData(Qt::DecorationRole,
					QPixmap(":/case_vierge.jpg").scaled(56, 56));
		}
	}

	pion = false;


	//texte sur l'état du jeu
	etatJeu = new QLabel(this);
	{
		std::ostringstream oss;
		std::string nomJoueur[]={"RIEN","BLANC","NOIR"};
		oss << "Blancs:  "<< oth->pionsBlancs() << "   Noirs:  " <<oth->pionsNoirs()<<"   Cases Vides:  "<< oth->casesVides() << std::endl << nomJoueur[oth->aQuiLeTour()] << " doit jouer";
		etatJeu->setText(oss.str().c_str());
	}
	//

	//layout
	layoutExpert->addWidget(plateau);
	layoutExpert->addWidget(etatJeu);
	this->setLayout(layoutExpert);
	//

	this->attacher(this);
	this->adjustSize();

	this->notifierChangement();

	connect(plateau, SIGNAL(cellClicked(int,int)), this, SLOT(placer(int,int)));

}

observateurExpert::~observateurExpert() {
	this->detacher(this);
}

void observateurExpert::rafraichir(SujetDObservation * sdo) {
	int val;
	std::ostringstream oss;
	std::string nomJoueur[]={"PERSONNE","BLANC","NOIR"};
	if(!oth->estFini()){
	oss << "Blancs:  "<< oth->pionsBlancs() << "   Noirs:  " <<oth->pionsNoirs()<<"   Cases Vides:  "<< oth->casesVides() << std::endl << nomJoueur[oth->aQuiLeTour()]
      <<" doit jouer et avantage pour : " << nomJoueur[oth->vainqueur()] << " !";
	etatJeu->setText(oss.str().c_str());
	}else{
		oss << "Blancs:  "<< oth->pionsBlancs() << "   Noirs:  " <<oth->pionsNoirs()<<"   Cases Vides:  "<< oth->casesVides() << std::endl << nomJoueur[oth->vainqueur()] << " a gagné !";
		etatJeu->setText(oss.str().c_str());
	}

	for (unsigned i = 0; i < oth->rangees(); i++) {
		for (unsigned j = 0; j < oth->colonnes(); j++) {
			val = oth->at(Position(i, j));
			switch (val) {
			case 0:
				tab[i][j]->setData(Qt::DecorationRole,
						QPixmap(":/case_vierge.jpg").scaled(56, 56));
				plateau->setItem(i, j, tab[i][j]);
							break;
			case 1:
				tab[i][j]->setData(Qt::DecorationRole,
						QPixmap(":/pion_blanc.jpg").scaled(56, 56));
				plateau->setItem(i, j, tab[i][j]);

				break;
			case 2:
				tab[i][j]->setData(Qt::DecorationRole,
						QPixmap(":/pion_noir.jpg").scaled(56, 56));
				plateau->setItem(i, j, tab[i][j]);

				break;

			}
		}
	}
}
bool observateurExpert::absolute(int i){			//utile pour récupérer le tour du joueur
	if(i<0){
		return -i;
	}else{
		return i;}
}

void observateurExpert::placer(int l, int c) {
	try {
		oth->placer(pion, Position(l, c));
		emit changement(pion, l, c);
		pion = absolute(oth->aQuiLeTour()-2);
		this->attacher(this);
		this->notifierChangement();

	} catch (std::logic_error &ex) {
		std::string info = ex.what();
		QString erreur = QString::fromStdString(info);
		QMessageBox::information((QWidget *) this, "Information", erreur);
	}
}

void observateurExpert::closeEvent(QCloseEvent * e){
	emit masque();
	//e->accept();
}
