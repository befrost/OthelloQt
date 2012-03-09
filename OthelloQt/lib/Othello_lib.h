/*
 * Othello.h
 *
 *  Created on: F�vrier 2012
 *      Author: SMB
 */

/*!
 * \mainpage Othello
 *
 * Othello est une classe m�tier impl�mentant compl�tement la gestion d'une
 * partie du
 * <a href="https://fr.wikipedia.org/wiki/Othello_%28jeu%29" target="_blank">jeu d'Othello</a>.
 *
 * \author    S. Monbaliu
 * \date    F�vrier 2012
 */

#ifndef OTHELLO_H_
#define OTHELLO_H_

#include <stdexcept>
#include <string>

/*!
 * \brief Structure repr�sentant une position qui permettra de situer
 * une case de l'othellier, ou de passer d'une case � une autre.
 *
 * \author 	S. Monbaliu
 * \date 	F�vrier 2012
 */

struct Position
{
    /*!
     * \brief Constructeur.
     *
     * \param r Le num�ro de la rang�e (0 pour la rang�e du haut).
     *
     * \param c Le num�ro de la colonne (0 pour la colonne la plus � gauche).
     */
    Position(int r = -1, int c = -1) :
            numR(r), numC(c)
    {
    }
    /*!
     * \brief Num�ro de la rang�e (� partir de 0).
     */
    int numR;
    /*!
     * \brief Num�ro dans la rang�e (� partir de 0).
     */
    int numC;
    /*!
     * \brief Surcharge de l'op�rateur d'addition.
     *
     * \param p La position � ajouter.
     *
     * \return La position r�sultat de l'addition.
     */
    Position operator+(Position p) const
    {
        return Position(numR + p.numR, numC + p.numC);
    }
};

/*!
 * \brief Classe m�tier unique du jeu Othello.
 *
 * Cette classe offre ce qu'il faut pour permettre la r�alisation d'une partie
 * d'Othello.
 *
 * \author 	S. Monbaliu
 * \date 	F�vrier 2012.
 */
class Othello
{
public:
    /*!
     * \brief Diverses constantes pour les valeurs des cases de l'othellier.
     */
    enum Etat
    {
        VIDE, /*!< Valeur initiale des cases de l'othellier. */
        BLANC, /*!< Valeur traduisant la pr�sence d'un pion blanc. */
        NOIR
    /*!< Valeur traduisant la pr�sence d'un pion noir. */
    };

    /*!
     * Constructeur du jeu.
     *
     * \param nbRangees Nombre de rang�es de l'othellier (8 par d�faut).
     *
     * \param nbColonnes Nombre de colonnes de l'othellier (8 par d�faut).
     *
     *
     * \exception std::logic_error si le nombre de rang�es et/ou colonnes est
     * impair, si le nombre de rang�es et/ou colonnes n'appartient pas
     * � [4,12].
     *
     */
    Othello(unsigned nbRangees = 8, unsigned nbColonnes = 8)
            throw (std::logic_error);

    /*!
     * \brief Destructeur.
     *
     * Il est rendu obligatoire par le masquage de l'impl�mentation.
     *
     */
    virtual ~Othello();

    /*!
     * \brief Constructeur par recopie.
     *
     * Il est rendu obligatoire par le masquage de l'impl�mentation.
     *
     * \param original L'Othello � cloner.
     */
    Othello(const Othello & original);

    /*!
     * \brief Surcharge de l'op�rateur d'assignation.
     *
     * Il est rendu obligatoire par le masquage de l'impl�mentation.
     *
     * \param droite L'Othello � droite du signe �gal.
     *
     * \return Une r�f�rence vers l'Othello � gauche du signe �gal.
     */
    Othello & operator=(const Othello & droite);

    /*!
     * \brief Accesseur en lecture pour savoir � qui c'est le tour de jouer.
     *
     * \return la valeur d�signant le joueur (BLANC ou NOIR) ou VIDE
     * si le jeu est fini.
     */
    Etat aQuiLeTour() const;

    /*!
     * \brief Accesseur en lecture de l'�tat fini ou non du jeu.
     *
     * \return <i>true</i> si le jeu est fini, <i>false</i> sinon.
     */
    bool estFini() const;

    /*!
     * \brief Accesseur en lecture pour savoir qui m�ne (si le jeu est en
     * cours) ou qui a gagn� (si le jeu est fini).
     *
     * \return la valeur d�signant le joueur (BLANC ou NOIR) ou VIDE
     * en cas de match nul.
     */
    Etat vainqueur() const;

    /*!
     * \brief M�thode permettant de placer un pion sur l'othellier.
     *
     * \param pionBlanc <i>true</i> si on place un pion blanc, <i>false</i>
     *  si on place un pion noir.
     *
     * \param pos La position o� placer le pion.
     *
     * \exception std::logic_error Si le jeu est fini, si ce n'est pas
     * la bonne couleur � placer, si la position donn�e est hors othellier,
     * ou est celle d'une case occup�e, ou si les autres r�gles de placement
     * ne sont pas respect�es.
     */
    void placer(bool pionBlanc, Position pos) throw (std::logic_error);

    /*!
     * \brief Accesseur en lecture du nombre de cases inoccup�es
     * de l'othellier.
     *
     * \return Le nombre de cases inoccup�es.
     */
    unsigned casesVides() const;

    /*!
     * \brief Accesseur en lecture du nombre de pions blancs sur l'othellier.
     *
     * \return Le nombre de pions blancs.
     */
    unsigned pionsBlancs() const;

    /*!
     * \brief Accesseur en lecture du nombre de pions noirs sur l'othellier.
     *
     * \return Le nombre de pions noirs.
     */
    unsigned pionsNoirs() const;

    /*!
     * \brief Accesseur en lecture du nombre de rang�es de l'othellier.
     *
     * \return Le nombre de rang�es.
     */
    unsigned rangees() const;

    /*!
     * \brief Accesseur en lecture du nombre de colonnes de l'othellier.
     *
     * \return Le nombre de colonnes.
     */
    unsigned colonnes() const;

    /*!
     * \brief M�thode donnant une repr�sentation du jeu sous la forme
     * d'un string. Ce string repr�sente l'othellier, donne le nombre de pions
     *  de chaque couleur pr�sents sur l'othellier, ainsi que le nombre de
     *  cases vides. Il annonce �galement � qui c'est le tour de jouer.
     *  � la fin, il donne le vainqueur.
     *
     * \return La repr�sentation du jeu Othello en string.
     */
    std::string toString() const;

    /*!
     * \brief M�thode permettant de conna�tre le contenu d'une case de
     * l'othellier.
     *
     * \param pos La position � analyser.
     *
     * \return L'�tat de la case analys�e (BLANC, NOIR ou VIDE).
     *
     * \exception std::logic_error Si la position donn�e est en dehors
     * l'othellier.
     *
     */
    Etat at(Position pos) const throw (std::logic_error);

private:

    class ImpOthello * handle;

};

#endif /* OTHELLO_H_ */
