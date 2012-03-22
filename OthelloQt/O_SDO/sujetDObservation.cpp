#include <algorithm>

#include "sujetDObservation.h"
#include "observateur.h"

using std::vector ;
using std::find ;

void SujetDObservation::attacher(Observateur * obs)
{
  if (mesObservateurs.size() != 0)
  {
    vector<Observateur *>::iterator it =
          find(mesObservateurs.begin(),mesObservateurs.end(),obs) ;

    if (it == mesObservateurs.end())
    {
      mesObservateurs.push_back(obs) ;
    }
  }
  else
  {
    mesObservateurs.push_back(obs) ;
  }
}

void SujetDObservation::detacher(Observateur * obs)
{
  vector<Observateur *>::iterator it =
    find(mesObservateurs.begin(),mesObservateurs.end(),obs) ;

  if (it != mesObservateurs.end())
  {
    mesObservateurs.erase(it) ;
  }
}

void SujetDObservation::notifierChangement()
{
  for (unsigned i = 0 ; i < mesObservateurs.size() ; ++i)
  {
    mesObservateurs.at(i)->rafraichir(this);
  }
}
