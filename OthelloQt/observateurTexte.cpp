/*
 * observateurTexte.cpp
 *
 *  Created on: 17 mars 2012
 *      Author: Administrateur
 */

#include "observateurTexte.h"

observateurTexte::observateurTexte() : QLabel() {
	// TODO Auto-generated constructor stub

}

observateurTexte::observateurTexte(Othello * othellier) : QLabel(){
	   Qt::WindowFlags flags = 0;
	   flags |= Qt::CustomizeWindowHint;
	   flags |= Qt::WindowTitleHint;
	   setWindowFlags(flags);
	   oth = othellier;
}

void observateurTexte::rafraichir(SujetDObservation * sdo){
	if(!oth->estFini()){
	  this->setText(oth->toString().c_str());
	}else{
	  switch (oth->vainqueur()){
	     case 0 : this->setText("Match nul");break;
	     case 1 : this->setText("Victoire du blanc"); break;
	     case 2 : this->setText("Victoire du noir"); break;
	  }
	}
}

void observateurTexte::closeEvent(QCloseEvent * e){
	emit masque();
	//e->accept();
}

observateurTexte::~observateurTexte() {
	// TODO Auto-generated destructor stub
}

