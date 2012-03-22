#ifndef __SUJETDOBSERVATION__H__
#define __SUJETDOBSERVATION__H__

#include <vector>

class Observateur;

/*!
 * 	\brief Classe de base de tout "sujet d'observation"
 *
 * Classe dont d�rive toute source d'�v�nement (ou "sujet d'observation")
 * du mod�le de conception "Observateur / SujetDObservation".
 *
 * \author GOF (?).
 * \sa Observateur.
 */
class SujetDObservation
{
public:

	/*!
	 * Destructeur impl�ment� � vide car il n'a rien � faire.
	 */
	virtual ~SujetDObservation()
	{
	}

	/*!
	 * M�thode permettant � un observateur de s'enregistrer comme
	 * �couteur du sujet d'observation.
	 *
	 * \param obs un pointeur vers le candidat observateur.
	 */
	virtual void attacher(Observateur * obs);

	/*!
	 * M�thode permettant � un observateur de se retirer de la liste
	 * des �couteurs patent�s du sujet d'observation.
	 *
	 * \param obs l'adresse de l'observateur d�sint�ress�.
	 */
	virtual void detacher(Observateur * obs);

protected:

	/*!
	 * Constructeur prot�g� pour �viter l'instanciation.
	 */
	SujetDObservation()
	{
	}

	/*!
	 * M�thode qui se charge de pr�venir les observateurs d'un changement
	 * d'�tat du sujet d'observatuion, en invoquant leur m�thode rafraichir.
	 *
	 * \sa Observateur::rafraichir(SujetDObservation *).
	 */
	virtual void notifierChangement();

protected:

	/*!
	 * Le vecteur d'observateurs enregistr�s.
	 */
	std::vector<Observateur *> mesObservateurs;
};

#endif
