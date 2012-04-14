#ifndef OTHELLOQT_H
#define OTHELLOQT_H

#include <QtGui/QMainWindow>
#include "ui_othelloqt.h"
#include "Othello.h"
#include "dialogueConfiguration.h"
#include "observateurTexte.h"
#include "observateurExpert.h"
#include "O_SDO/sujetDObservation.h"
#include <QFileDialog>
#include <QFile>
#include <QDataStream>
#include <vector>
#include <sstream>
#include <string.h>
#include <QMessageBox>


struct Coup {							// structure représentant un coup joué.
	Position pos;						// la position du coup
	bool pionBlanc;					 	// la couleur du pion placé.
};

class OthelloQt : public QMainWindow, public SujetDObservation
{
    Q_OBJECT

public:
    /*! \brief
     * Constructeur :
     * \param QWidget
     */
    OthelloQt(QWidget *parent = 0);

    /* \brief
     * Destructeur :
     *
     */

    std::string coupsToString();

    ~OthelloQt();

private:
    std::vector<Coup> positions;
    Othello * othellier;
    dialogueConfiguration * dia;
    observateurTexte * obsTxt;
    observateurExpert * obsExpe;
    void noterCoup(bool pionBlanc, Position pos);
    Ui::OthelloQtClass ui;
    virtual void closeEvent(QCloseEvent *);

// surtout pas oublier de mettre les méthodes suivantes dans slots, sinon la connexion ne se fera pas


private slots:

     /*! \brief
     *  Methode qui permet de gérer tout ce qui concerne les actions
     *  \param aucun
     *  \return aucun
     *  */

     void creerAction();


    /* \brief
     * Methode qui permet la creation d'un nouveu jeu othello a partir des infos reçues de
     * la fenêtre de dialogue.
     */

    void nouvellePartie();


    /* \brief
     * Methode qui permet de mettre fin à une partie en cours
     */

    void fermerPartie();

    /* \brief
     * Methode qui permet de jouer des coups
     */

    void jouerCoup();

    /* \brief
     * Methode qui permet d'afficher l'observateur text
     */

    void obsTexte(bool actif);


    void obsExpert(bool actif);

    /* \brief
     * Permet d'afficher un cadre avec les joueurs du jeu.
     */

    void auteur();

    /* \brief
     * Permet d'afficher les règles du jeu.
     */

    void regles();



    void sauverPartie();


    void chargerPartie();
};


#endif // OTHELLOQT_H
