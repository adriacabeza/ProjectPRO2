/** @mainpage
  Aquí trobareu organitzada la documentació <b> completa </b> (incloent privats i codi) de la pràctica.

  El programa principal es troba en el mòdul programa.cc.
  Atenent als tipus de dades suggerits en l'enunciat, necessitarem un mòdul per a representar la poblacio on es desenvoluparan els experiments, un altre pel tipus individu,
  un altre pel tipus especie i finalment un altre per al tipus arbregenealogic.

*/
/** @file program.cc


    @brief Programa principal

    Estic suposant que les dades inicials són correctes ja que no s'incloeixen comprovacions al respecte. ¡

    */
#include "poblacio.hh"
#include "individu.hh"
#include "especie.hh"
#include "arbregenealogic.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif

using namespace std;

int main(){
    especie e;
    e.LlegirEspecie();
    int inic;
    cin >> inic;
    poblacio r;
    for(int i=0;i<inic;++i){
        r.anadir_individuo(e,0);
    }
    string instruccio;
    bool acabar=false;
    while(not acabar){
      cin  >>  instruccio;
      if(instruccio == "anadir_individuo") {cout <<"anadir_individuo"; r.anadir_individuo(e,1);}
      else if(instruccio == "escribir_poblacion") {cout <<"escribir_poblacion"; r.escribir_poblacion();}
      else if(instruccio == "reproduccion_sexual") r.reproduccion_sexual(e);
      else if(instruccio == "escribir_arbol_genealogico"){
        string nom;
        cin >> nom;
        cout <<"escribir_arbol_genealogico " <<nom <<endl;
        r.escribir_arbol_genealogico(nom);
      }
      else if(instruccio == "completar_arbol_genealogico"){
        cout <<"completar_arbol_genealogico ";
          arbregenealogic a;
           a.completar_arbol_genealogico(r);
        }
      else if(instruccio == "escribir_genotipo") {
      		string nom;
      		cin >>  nom;
          cout <<"escribir_genotipo " <<nom;
          pair <bool, individu > p= r.existeix(nom);
      		if(p.first){
      			 (p.second).escribir_genotipo();
      		}
          else cout <<endl <<"  error" <<endl;
      }
      else if(instruccio=="acabar"){cout <<"acabar" <<endl; acabar=true;}
   }
 }
