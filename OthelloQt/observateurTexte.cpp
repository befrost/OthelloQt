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
	   rafraichir();
}

void observateurTexte::rafraichir(){
	this->setText(oth->toString().c_str());
}

observateurTexte::~observateurTexte() {
	// TODO Auto-generated destructor stub
}

