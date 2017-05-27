/** @file individu.hh
    @brief Especificació de la classe individu
*/

#ifndef CLASS_INDIVIDU_HH
#define CLASS_INDIVIDU_HH


#include "especie.hh"
#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <iostream>
#endif

using namespace std;

/*
 * Classe individu
 */


/** @class individu
    @brief Representa a un individu de la espècie i a totes les seves operacions pertinents.

    S'ofereixen les operacions consultores d'informació de l'individu a més de les d'escritura i lectura d'un individu i la seva informació genètica.

*/

class individu {
  // Descripció: conté la informació d'un individu del sistema i les operacions necessàries per a gestionar-lo.

private:
  /* Per a la bona gestió del sistema a simular, aquesta classe requereix guardar de manera separada diversos strings que són el pare i la mare de l'individu,
    dos booleans separats que indiquen el sexe o si té ascendència, un vector on hi ha tota la informació genètica organitzada, un struct utilitzat per facilitar
    el tracte de la informació donada en el canal estandar d'entrada en la reproducció sexual i una funció que retorna un booleà que consulta la informació genètica
    d'una ubicació en concret.*/

  /** @brief Nom pare

  si és buit és $$*/
  string pare;

  /** @brief Nom mare

  si és buit és $$*/
  string mare;

  /** @brief Sexe

  False és gènere femení i true és gènere masculí*/
  bool sexe;

  /** @brief Té ascendència */
  bool te_ascendencia;

  /** @brief Informació genètica

  Informació genètica disposada correctament, amb els cromosomes sexuals al capdavant i en parells que representen els parelles de cromosomes */
  vector < pair <vector<bool>, vector<bool> > >genotip;

  /** @brief Consultor d'informació genètica
    Si el booleà j és 0 és retorna la informació genètica del primer parell, en canvi si és 1 es retorna el segon
  	\pre <em> 0<=i<genotip.size() i 0<=j<mida del parell de cromosomes que estem mirant</em>
  	\post es retorna un booleà amb un 0 o un 1 depenent de la informació requerida en els paràmetres*/

  bool consultar_gen(int i, bool j, int x) const;
  //si es 0 retorna el del first i si es 1 el del second


  /** @brief Estructura d'informació per a la reproducció.
    Estructura conformada per dos booleans i un enter que ens és útil per a interpretar la informació
    donada en el canal estandar d'entrada de la reproducció sexual, el primer booleà indica quin parell
    de cromosomes agafar de la mare, el segon booleà del pare i el tercer enter ens indica el punt de tall
    per a barrejar la informació genètica*/

  struct  info{
    bool primer;
    bool segon;
    int puntall;
  };

public:

// Constructors

individu(string& dad, string& mum);

/** @brief Creador d'individus

	Permet declarar un individu nou.
	\pre <em> cert </em>
  \post El resultat és un individu amb el nom nom, sexe sexe, pare i mare buits.
 */
  individu(char& sexe);

  /** @brief Creador d'individus

    Permet declarar un individu nou buit.
    \pre <em> cert </em>
    \post El resultat és un individu buit.
   */
    individu();


 // Lectura
/** @brief Operació de lectura d'un genotip

        \pre <em> Al canal estandar d'entrada hi ha la informació del genotip de l'espècie</em>
	      \post  S'ha llegit la informació del genotip i s'ha guardat al p.i.*/

  void LlegirGenotip(const especie& e);

// Escriure

/** @brief Operació d'escritura d'un individu

        \pre <em> cert </em>
	      \post  Pel canal de sortida s'escriu tota la informació pertinent a l'individu */

  void escriure_individu() const;

 /** @brief Operació d'escritura d'un individu

          \pre <em> cert </em>
          \post s'escriu pel canal de sortida el genotip de l'individu per ordre creixent d'identificador de par de cromosomes*/

 void escribir_genotipo() const;


  // Consultors

/** @brief Consultor de si té ascendència

	\pre <em> cert </em>
	\post El resultat indica si el paràmetre ímplicit té o no pares */
  bool TePares() const;

/** @brief Consultor de sexe

	\pre <em> cert </em>
	\post El resultat indica si el paràmetre ímplicit és noi(true) o si és noia(false) */

  bool Sexe() const;

/** @brief Consultor del nom del pare

	\pre <em> cert</em>
	\post es retorna el nom del pare */

  string consultar_pare() const;

/** @brief Consultor del nom de la mare

	\pre <em> cert </em>
	\post es retorna el nom de la mare */
  string consultar_mare() const;


//Modificadors
  /** @brief Barrejar el genotip a partir dels dos indidivus

  	\pre <em> mum ha de ser femella i father mascle </em>
  	\post s'emplena la informació genètica del p.i. de l'individu en base a la informació genètica de mum i father */

  void barrejar_genotip(individu& mum, individu& father, const especie& e);

};
#endif
