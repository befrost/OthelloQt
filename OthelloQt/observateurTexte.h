/*
 * observateurTexte.h
 *
 *  Created on: 17 mars 2012
 *      Author: Administrateur
 */

#include <QLabel>
#include "Othello.h"


#ifndef OBSERVATEURTEXTE_H_
#define OBSERVATEURTEXTE_H_


class observateurTexte : public QLabel {

Q_OBJECT

public:
	observateurTexte();
	observateurTexte(Othello * oth);
	virtual ~observateurTexte();
};

#endif /* OBSERVATEURTEXTE_H_ */
