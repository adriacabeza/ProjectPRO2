/** @file poblacio.hh
    @brief Especificació de la classe població
*/

#ifndef CLASS_POBLACIO_HH
#define CLASS_POBLACIO_HH

#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#include <map>
#endif

#include "individu.hh"
using namespace std;


/*
 * Classe poblacio
 */

/** @class poblacio
    @brief Representa a tot el conjunt d'individus d'una espècie

	La població és el conjunt d'individus de la mateixa espècie. Ofereix les operacions d'afegir un individu, escriure el seu arbre genealògic, FALTA ESCRIURE ASCENDeNTS PRIVAT comprovar si un individu existeix, entre d'altres.
*/

class poblacio {
  // Descripció: conté als individus que estan presents en el sistema i les operacions necessàries per a gestionar-los

private:
  /* Per a la bona gestió del sistema a simular, aquesta classe requereix guardar un diccionari amb el nom de l'individu i en el seu contingut hi ha l'individu amb tota la seva informació.*/

  /**@brief Diccionari de tots els individus de la espècie*/

  map<string, individu> t;

  /** @brief Comprovació d'ascendència
          \pre <em>individua i individub són dos individus presents en la població</em>
          \post  es comprova si l'individu b és ascendent de l'individu a i es retorna el resultat */


  bool son_ascendents(string individua, string individub) const;

  /** @brief Immersió per a la recursió d'escriure arbre genealògic
          \pre <em> nivell representa el nivell d'ascendència en el que estem, i familia on s'emmagatzema </em>
          \post  s'escriu a familia els noms dels diversos ascendents dependent del nivell d'ascendència mitjançant el codi d'enters de familia */

  void escriure_familia_funcio(int nivell, map<int,vector<string> >& familia, const string& x);


public:

// Constructor

/** @brief Crea una població buida
        \pre <em> cert </em>
        \post  Es crea una poblacio buida.
*/
    poblacio();


 // Modificadors

/** @brief Afegeix un individu a la població
	      \pre <em>cert</em>
        \post  s'afegeix un individu i en el cas de que l'individu ja existeixi a la població es dóna un missatge amb error*/

  void anadir_individuo(const especie& e,bool b);

/** @brief Reproduir dos individus per a crear un de nou
	      \pre <em> cert </em>
        \post Si existeix un pare pare, una mare mare i no hi ha cap individu nom, els pares cumpleixen els següents requísits:
        ·el pare és mascle i la mare femella
        ·els progenitors no són germans ni un és ascendent de l'altre
         es crea i s'afegeix un individu amb un genotip basat en el dels seus progenitors pare i mare, en cas contrari es dóna un missatge d' error.
         El booleà ens indica si pel canal de sortida s'han de treure els individus afegits o no.*/

  void reproduccion_sexual(const especie&);

//Escritura

/** @brief Escriure un arbre genealògic
	\pre <em> la persona existeix </em>
	\post s'escriu al canal estàndard de sortida l'arbre genealògic de l'individu en preordre */

  void escribir_arbol_genealogico(const string& x);

/** @brief Escriure població
	\pre <em> cert </em>
	\post s'escriu la població*/

  void escribir_poblacion() const;


// Consultors

  /** @brief Consultor d'existència
  	      \pre <em>cert</em>
          \post El resultat indica en el booleà existeix si en el paràmetre ímplicit existeix l'individu amb nom x i en la segona part del pair hi retorna l'individu */

  pair <bool, individu> existeix(const string& x) const;


};
#endif
