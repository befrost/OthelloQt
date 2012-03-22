#ifndef __OBSERVATEUR__H__
#define __OBSERVATEUR__H__

class SujetDObservation;

/*!
 * 	\brief Classe abstraite de base de tout observateur
 *
 * Classe dont dérive tout écouteur (ou "observateur") du modèle de
 * conception "Observateur / SujetDObservation".
 *
 * \author GOF (?).
 * \sa SujetDObservation.
 */

class Observateur
{
public:

	/*!
	 * Méthode virtuelle pure que chaque observateur concret doit implémenter :
	 * c'est cette méthode qu'appelle le sujet observé lors d'une notification.
	 *
	 * \param sdo le sujet d'observation qui notifie un changement.
	 * \see SujetDObservation::notifierChangement().
	 */
	virtual void rafraichir(SujetDObservation * sdo) = 0;

	/*!
	 * Destructeur implémenté à vide car il n'a rien à faire.
	 */
	virtual ~Observateur()
	{
	}
};

#endif
