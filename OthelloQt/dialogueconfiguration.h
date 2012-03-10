#ifndef DIALOGUECONFIGURATION_H
#define DIALOGUECONFIGURATION_H

#include <QtGui/QDialog>
#include "ui_dialogueconfiguration.h"

class dialogueConfiguration : public QDialog
{
    Q_OBJECT

public:
    dialogueConfiguration(QWidget *parent = 0);
    ~dialogueConfiguration();

    /*! \brief
     *  Getter :
     *  \return le nombre de colonnes
     */
    unsigned getNbCol();

    /*! \brief
     *  Getter :
     *  \return le nombre de rangees
     */

    unsigned getNbRan();

private:
    // on les met � 8 car si  pas de value change = pas de connexion et donc pas initialis�
    unsigned nbCol , nbRan;
    Ui::dialogueConfigurationClass ui;


private slots:

     /*! \brief
     *  Methode qui permet de g�rer tout ce qui concerne les actions
     *  \param aucun
     *  \return aucun
     *  */

     void creerAction();

     /*! \brief
      * Setter : met � jour le nombre de rang�es
      * \param le nombre de rang�es
      */

     void setNbRangees(int nb);

     /*! \brief
      * Setter : met � jour le nombre de colonnes
      * \param le nombre de colonnes
      */

     void setNbColonnes(int nb);

};

#endif // DIALOGUECONFIGURATION_H
