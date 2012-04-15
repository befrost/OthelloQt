/*
 * observateurExpert.h
 *
 *  Created on: 11 avr. 2012
 *      Author: Administrateur
 */


#include <QLabel>
#include <QVector>
#include <QVBoxLayout>
#include "Othello.h"
#include "O_SDO/observateur.h"
#include "O_SDO/sujetDObservation.h"
#include <QScrollArea>
#include <QWidget>
#include <QPoint>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>

#ifndef OBSERVATEUREXPERT_H_
#define OBSERVATEUREXPERT_H_
class observateurExpert : public QWidget, public Observateur, public SujetDObservation {

Q_OBJECT

public:
	observateurExpert();
	observateurExpert(Othello * othellier, QPoint pos);
	virtual ~observateurExpert();
private:
	bool pion;
	Othello * oth;
	QVector < QVector <QTableWidgetItem *> > tab;
	QTableWidget * plateau;
	QLabel * etatJeu;
	QVBoxLayout * layoutExpert;
	void rafraichir(SujetDObservation * sdo);
	void closeEvent(QCloseEvent * e);
	bool absolute(int);	//retourne valeur absolue
	QVector <Position> coupsPossibles(Othello *, bool);
private slots:
    void placer(int l, int c);
signals:
    void masque(int);
    void changement(bool, int, int);
};

#endif /* OBSERVATEUREXPERT_H_ */
