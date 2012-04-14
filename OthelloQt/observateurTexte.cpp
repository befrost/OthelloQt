/*
 * observateurTexte.cpp
 *
 *  Created on: 17 mars 2012
 *      Author: Administrateur
 */

#include "observateurTexte.h"
#include "othelloqt.h"

observateurTexte::observateurTexte() : QLabel() {
	// TODO Auto-generated constructor stub

}

observateurTexte::observateurTexte(Othello * othellier, QPoint  pos) : QLabel(){

	   setWindowTitle("Observateur Texte");
	   this->move(pos.x() + 300, pos.y());
	   Qt::WindowFlags flags = 0;
	   QFont sansFont("Lucida Console", 12);		//police à utiliser
	   sansFont.setWordSpacing(5);
	   flags |= Qt::CustomizeWindowHint;
	   flags |= Qt::WindowTitleHint;
	   setWindowFlags(flags);
	   this->setMinimumWidth(650);
	   this->setFont(sansFont);						//défini la police


	   QHBoxLayout *horizontalLayout;
	   QScrollArea *scrollArea;
	   QWidget *scrollAreaWidgetContents;
	   QVBoxLayout *verticalLayout;

	   horizontalLayout = new QHBoxLayout(this);
       horizontalLayout->setSpacing(6);
       horizontalLayout->setContentsMargins(11, 11, 11, 11);
       horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
       vuePlateau = new QLabel(this);
       vuePlateau->setObjectName(QString::fromUtf8("vuePlateau"));
       horizontalLayout->addWidget(vuePlateau);
       scrollArea = new QScrollArea(this);
       //scrollArea->setFixedWidth(185);
       scrollArea->setMinimumWidth(185);
       scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
       scrollArea->setWidgetResizable(true);
       scrollAreaWidgetContents = new QWidget();
       scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
       scrollAreaWidgetContents->setGeometry(QRect(0, 0, 285, 642));
       verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
       verticalLayout->setSpacing(6);
       verticalLayout->setContentsMargins(11, 11, 11, 11);
       verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
       listeCoups = new QLabel(scrollAreaWidgetContents);
       listeCoups->setObjectName(QString::fromUtf8("listeCoups"));
       listeCoups->setAlignment(Qt::AlignLeft|Qt::AlignTop);
       verticalLayout->addWidget(listeCoups);
       scrollArea->setWidget(scrollAreaWidgetContents);
       vuePlateau->raise();
       listeCoups->raise();
       horizontalLayout->addWidget(scrollArea);

	   oth = othellier;
}

void observateurTexte::rafraichir(SujetDObservation * sdo){
	OthelloQt * othQt;
	othQt = (OthelloQt * ) sdo;
	if(!oth->estFini()){
		std::string str, str2;
		str = "Liste des coups :\n\n" + othQt->coupsToString();
		listeCoups->setText(str.c_str());
		str2 = oth->toString();
	  this->vuePlateau->setText(str2.c_str());
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

