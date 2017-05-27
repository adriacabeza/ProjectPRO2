/** @file especie.hh
    @brief Especificació de la classe especie
*/


#ifndef ESPECIE_HH
#define ESPECIE_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#endif

 /*
  * Classe especie
  */


/** @class especie
    @brief Representa la informació de tota la espècie, és a dir la informació que comparteixen tots es individus de la mateixa espècie,

    Les seves operacions son les de lectura de la informació de la espècie i les diverses consultores per susdita informació.

*/
class especie{
  //Descripció:  conté la informació comú de la espècie i les operacions necessàries per a fer-la servir
  private:
    /* Per a la bona gestió del sistema a simular, aquesta classe requereix guardar de manera separada diversos enters que representen mesures diverses o el punt comú dels cromosomes sexuals present en la reproducció sexual.
    Per això podem veure a 4 enters separats que representen el número de cromosomes autosòmics, la grandària dels sexuals i el punt de tall anteriorment esmentat. A més, també usarem un vector d'ints que guardarà la llargada dels cromosomes autosòmics ja que depenent de quin parell de cromosoma és, té una mida o una altra.
  */
    /** @brief Número de cromosomes autosòmics.*/
    int n;
    /** @brief Llargada dels cromosomes sexuals X i Y*/
    int lx, ly;
    /** @brief Vector amb la llargada dels parells de cromosomes autosòmics*/
    vector<int> ln;
    /** @brief Punt comú per a la reproducció sexual.*/
    int puntdetall;



public:

//Constructora
/** @brief Es crea una espècie
	\pre <em> cert </em>
	\post  S'ha creat una espècia buida.
*/

especie();

//Lectura

/** @brief Operació de lectura del genotip
	\pre <em> Al canal estandàrd d'entrada la informació comuna a tota la espècie</em>
	\post  El paràmetre implícit conté la quantitat i el tamany dels gens de la espècie i el punt de tall per a la reproducció.
*/

  void LlegirEspecie();

//Consultors


/** @brief Consultar la llargada del cromosoma
	\pre <em> cert </em>
	\post Retorna l'enter que representa la mida del parell de cromosoma i .
*/
  int llargada_iessim(int i) const;



/** @brief Consultar la llargada del cromosoma X
	\pre <em> cert </em>
	\post Retorna la llargada del cromosoma sexual x.
*/

    int llargada_x() const;

/** @brief Consultar la llargada del cromosoma Y
	\pre <em> cert </em>
	\post Retorna la llargada del cromosoma sexual Y.
*/
    int llargada_y() const;

/** @brief Consultar la llargada del cromosoma
	\pre <em> cert </em>
	\post Retorna el número de cromosomes que té qualsevol individu de l'espècie.
*/
     int num_cromosomes() const;

/** @brief Consultar la llargada del cromosoma
	\pre <em> cert </em>
	\post Retorna el punt comú dels cromosomes sexuals.
*/
     int punt_tall() const;
};
#endif
