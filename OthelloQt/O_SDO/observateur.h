#ifndef __OBSERVATEUR__H__
#define __OBSERVATEUR__H__

class SujetDObservation;

/*!
 * 	\brief Classe abstraite de base de tout observateur
 *
 * Classe dont d�rive tout �couteur (ou "observateur") du mod�le de
 * conception "Observateur / SujetDObservation".
 *
 * \author GOF (?).
 * \sa SujetDObservation.
 */

class Observateur
{
public:

	/*!
	 * M�thode virtuelle pure que chaque observateur concret doit impl�menter :
	 * c'est cette m�thode qu'appelle le sujet observ� lors d'une notification.
	 *
	 * \param sdo le sujet d'observation qui notifie un changement.
	 * \see SujetDObservation::notifierChangement().
	 */
	virtual void rafraichir(SujetDObservation * sdo) = 0;

	/*!
	 * Destructeur impl�ment� � vide car il n'a rien � faire.
	 */
	virtual ~Observateur()
	{
	}
};

#endif
