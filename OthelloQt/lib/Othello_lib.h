/*
 * Othello.h
 *
 *  Created on: Février 2012
 *      Author: SMB
 */

/*!
 * \mainpage Othello
 *
 * Othello est une classe métier implémentant complètement la gestion d'une
 * partie du
 * <a href="https://fr.wikipedia.org/wiki/Othello_%28jeu%29" target="_blank">jeu d'Othello</a>.
 *
 * \author    S. Monbaliu
 * \date    Février 2012
 */

#ifndef OTHELLO_H_
#define OTHELLO_H_

#include <stdexcept>
#include <string>

/*!
 * \brief Structure représentant une position qui permettra de situer
 * une case de l'othellier, ou de passer d'une case à une autre.
 *
 * \author 	S. Monbaliu
 * \date 	Février 2012
 */

struct Position
{
    /*!
     * \brief Constructeur.
     *
     * \param r Le numéro de la rangée (0 pour la rangée du haut).
     *
     * \param c Le numéro de la colonne (0 pour la colonne la plus à gauche).
     */
    Position(int r = -1, int c = -1) :
            numR(r), numC(c)
    {
    }
    /*!
     * \brief Numéro de la rangée (à partir de 0).
     */
    int numR;
    /*!
     * \brief Numéro dans la rangée (à partir de 0).
     */
    int numC;
    /*!
     * \brief Surcharge de l'opérateur d'addition.
     *
     * \param p La position à ajouter.
     *
     * \return La position résultat de l'addition.
     */
    Position operator+(Position p) const
    {
        return Position(numR + p.numR, numC + p.numC);
    }
};

/*!
 * \brief Classe métier unique du jeu Othello.
 *
 * Cette classe offre ce qu'il faut pour permettre la réalisation d'une partie
 * d'Othello.
 *
 * \author 	S. Monbaliu
 * \date 	Février 2012.
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
        BLANC, /*!< Valeur traduisant la présence d'un pion blanc. */
        NOIR
    /*!< Valeur traduisant la présence d'un pion noir. */
    };

    /*!
     * Constructeur du jeu.
     *
     * \param nbRangees Nombre de rangées de l'othellier (8 par défaut).
     *
     * \param nbColonnes Nombre de colonnes de l'othellier (8 par défaut).
     *
     *
     * \exception std::logic_error si le nombre de rangées et/ou colonnes est
     * impair, si le nombre de rangées et/ou colonnes n'appartient pas
     * à [4,12].
     *
     */
    Othello(unsigned nbRangees = 8, unsigned nbColonnes = 8)
            throw (std::logic_error);

    /*!
     * \brief Destructeur.
     *
     * Il est rendu obligatoire par le masquage de l'implémentation.
     *
     */
    virtual ~Othello();

    /*!
     * \brief Constructeur par recopie.
     *
     * Il est rendu obligatoire par le masquage de l'implémentation.
     *
     * \param original L'Othello à cloner.
     */
    Othello(const Othello & original);

    /*!
     * \brief Surcharge de l'opérateur d'assignation.
     *
     * Il est rendu obligatoire par le masquage de l'implémentation.
     *
     * \param droite L'Othello à droite du signe égal.
     *
     * \return Une référence vers l'Othello à gauche du signe égal.
     */
    Othello & operator=(const Othello & droite);

    /*!
     * \brief Accesseur en lecture pour savoir à qui c'est le tour de jouer.
     *
     * \return la valeur désignant le joueur (BLANC ou NOIR) ou VIDE
     * si le jeu est fini.
     */
    Etat aQuiLeTour() const;

    /*!
     * \brief Accesseur en lecture de l'état fini ou non du jeu.
     *
     * \return <i>true</i> si le jeu est fini, <i>false</i> sinon.
     */
    bool estFini() const;

    /*!
     * \brief Accesseur en lecture pour savoir qui mène (si le jeu est en
     * cours) ou qui a gagné (si le jeu est fini).
     *
     * \return la valeur désignant le joueur (BLANC ou NOIR) ou VIDE
     * en cas de match nul.
     */
    Etat vainqueur() const;

    /*!
     * \brief Méthode permettant de placer un pion sur l'othellier.
     *
     * \param pionBlanc <i>true</i> si on place un pion blanc, <i>false</i>
     *  si on place un pion noir.
     *
     * \param pos La position où placer le pion.
     *
     * \exception std::logic_error Si le jeu est fini, si ce n'est pas
     * la bonne couleur à placer, si la position donnée est hors othellier,
     * ou est celle d'une case occupée, ou si les autres règles de placement
     * ne sont pas respectées.
     */
    void placer(bool pionBlanc, Position pos) throw (std::logic_error);

    /*!
     * \brief Accesseur en lecture du nombre de cases inoccupées
     * de l'othellier.
     *
     * \return Le nombre de cases inoccupées.
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
     * \brief Accesseur en lecture du nombre de rangées de l'othellier.
     *
     * \return Le nombre de rangées.
     */
    unsigned rangees() const;

    /*!
     * \brief Accesseur en lecture du nombre de colonnes de l'othellier.
     *
     * \return Le nombre de colonnes.
     */
    unsigned colonnes() const;

    /*!
     * \brief Méthode donnant une représentation du jeu sous la forme
     * d'un string. Ce string représente l'othellier, donne le nombre de pions
     *  de chaque couleur présents sur l'othellier, ainsi que le nombre de
     *  cases vides. Il annonce également à qui c'est le tour de jouer.
     *  À la fin, il donne le vainqueur.
     *
     * \return La représentation du jeu Othello en string.
     */
    std::string toString() const;

    /*!
     * \brief Méthode permettant de connaître le contenu d'une case de
     * l'othellier.
     *
     * \param pos La position à analyser.
     *
     * \return L'état de la case analysée (BLANC, NOIR ou VIDE).
     *
     * \exception std::logic_error Si la position donnée est en dehors
     * l'othellier.
     *
     */
    Etat at(Position pos) const throw (std::logic_error);

private:

    class ImpOthello * handle;

};

#endif /* OTHELLO_H_ */
