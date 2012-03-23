/*
 * observateurTexte.h
 *
 *  Created on: 17 mars 2012
 *      Author: Administrateur
 */

#include <QLabel>
#include <QVBoxLayout>
#include "Othello.h"
#include "O_SDO/observateur.h"


#ifndef OBSERVATEURTEXTE_H_
#define OBSERVATEURTEXTE_H_


class observateurTexte : public QLabel, public Observateur {

Q_OBJECT

public:
	observateurTexte();
	observateurTexte(Othello * othellier);
	virtual ~observateurTexte();
private:
	Othello * oth;
	void rafraichir(SujetDObservation * sdo);
	void closeEvent(QCloseEvent * e);
signals:
    void masque();
};

#endif /* OBSERVATEURTEXTE_H_ */
