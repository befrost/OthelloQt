#ifndef OTHELLOQT_H
#define OTHELLOQT_H

#include <QtGui/QMainWindow>
#include "ui_othelloqt.h"
#include "lib/Othello_lib.h"
#include "dialogueConfiguration.h"

class OthelloQt : public QMainWindow
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
    ~OthelloQt();

private:
    Othello * othellier;
    dialogueConfiguration * dia;

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


    Ui::OthelloQtClass ui;
};

#endif // OTHELLOQT_H
