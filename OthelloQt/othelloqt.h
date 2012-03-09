#ifndef OTHELLOQT_H
#define OTHELLOQT_H

#include <QtGui/QMainWindow>
#include "ui_othelloqt.h"
#include "lib/Othello_lib.h"
#include "dialogueConfiguration.h"
#include <string.h>
#include <QMessageBox>

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
    Ui::OthelloQtClass ui;

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
};

#endif // OTHELLOQT_H
