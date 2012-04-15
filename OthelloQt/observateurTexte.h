/*
 * observateurTexte.h
 *
 *  Created on: 17 mars 2012
 *      Author: Administrateur
 */

#include <QLabel>
#include <QHBoxLayout>
#include "Othello.h"
#include "O_SDO/observateur.h"
#include <QScrollArea>
#include <QWidget>
#include <QPoint>


#ifndef OBSERVATEURTEXTE_H_
#define OBSERVATEURTEXTE_H_


class observateurTexte : public QLabel, public Observateur {

Q_OBJECT

public:
	observateurTexte();
	observateurTexte(Othello * othellier, QPoint pos);
	virtual ~observateurTexte();
private:
	Othello * oth;
	QLabel * listeCoups, * vuePlateau;
	void rafraichir(SujetDObservation * sdo);
	void closeEvent(QCloseEvent * e);

signals:
    void masque(int);
};

#endif /* OBSERVATEURTEXTE_H_ */
