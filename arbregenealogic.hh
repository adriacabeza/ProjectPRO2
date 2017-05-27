/** @file arbregenealogic.hh
    @brief Especificació de la classe arbre genealògic
*/

#ifndef CLASS_ARBREGENEALOGIC_HH
#define CLASS_ARBREGENEALOGIC_HH


#include "individu.hh"
#include "poblacio.hh"
#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include "Arbre.hh"
#include <iostream>
#endif
using namespace std;

/*
 * Classe arbregenealogic
 */

/** @class arbregenealogic
    @brief Representa a l'arbre genealògic i a les seves operacions pertinents


*/
class arbregenealogic {
  // Descripció: conté l'arbre genealògic d'individu organitzat de la següent manera: a l'arrel hi ha l'individu en si, llavors els seus ascendents apareixen com a fills de l'arbre. A més hi ha les operacions necessàries per a gestionar-lo

private:
  /* Per al bon funcionament d'un arbre genealògic, aquesta classe requereix guardar
     un arbre amb els noms dels familiars de l'individu . */

  /** @brief Arbre de familiars
      Ordenats de manera que els fills són els ascendents*/
  Arbre <string> familia;

  /** @brief Llegir Arbre Parcial
      \pre a es buit; el canal estandar d'entrada conté el recorregut en preordre d'un arbre binari A marcat amb $
      \post a= A*/
  void llegir_funcio(Arbre<string>& a);

  /** @brief Escriure Arbre genealògic
    S'escriu l'arbe genealògic complet
    \pre a no és buit
    \post s'ha escrit pel canal estandar de sortida l'arbre parcial complet. És a dir, conté el recorregut en inordre d'a.*/
  void escriure_funcio(Arbre<string>& a) const;

  /** @brief Immersió de completar arbre
      \pre a no és buit
      \post s'ha completat l'arbre a en el cas que fos parcial i el booleà h és true i en cas contrari h és false i s'ha parat de completar un cop trobat que no és parcial  */
  void completar_arbol_genealogico_funcio(const poblacio& s, bool& h, Arbre<string>& a, const string& nom);

public:

 // Constructors


 /** @brief Creadora per defecte
 	\pre <em> cert  </em>
 	\post el resultat és un arbre genealògic buit */

  arbregenealogic();



/** @brief Completar un arbre geneaològic
	\pre <em> cert  </em>
	\post si l'arbre geneaològic donat és parcial a algun altre de la població, es completa l'arbre indicant els nombres que falten i s'escriu
  al canal de sortida estandar el susdit, en cas contrari s'escriu el missatge "no és arbre parcial".*/

  void completar_arbol_genealogico(const poblacio& s);

};

#endif
