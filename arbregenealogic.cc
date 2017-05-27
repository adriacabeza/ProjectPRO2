/** @file arbregenealogic.cc
    @brief Codi de la classe arbregenealogic
*/
#include "arbregenealogic.hh"

arbregenealogic::arbregenealogic()
{}


void arbregenealogic::llegir_funcio(Arbre<string>& a)
{
    string s;
    cin >> s;
    if (s != "$")
    {
        Arbre<string> fe, fd;
        llegir_funcio(fe);
        llegir_funcio(fd);
        a.plantar(s,fe,fd);
      }
}


void arbregenealogic::escriure_funcio(Arbre<string>& a) const
{
  if(a.es_buit()) cout <<  " $";
  else
  {
    Arbre <string> fd, fe;
    string arrel= a.arrel();
    a.fills(fe,fd);
    cout << " " << arrel;
    escriure_funcio(fe);
    escriure_funcio(fd);
  }
}


void arbregenealogic::completar_arbol_genealogico(const poblacio& s)
{
  llegir_funcio(familia);
  bool h=true;
  pair<bool,individu> p=s.existeix(familia.arrel());
  if(p.first)
  {
    completar_arbol_genealogico_funcio(s,h,familia,familia.arrel());
    cout << familia.arrel() << endl;
    if(h)
    {
      cout << " ";
      escriure_funcio(familia);
      cout << endl;
    } else cout << "  no es arbol parcial" << endl;
  }
  else cout << familia.arrel() << endl << "  no es arbol parcial" << endl;
}



void arbregenealogic::completar_arbol_genealogico_funcio(const poblacio& s, bool& h, Arbre<string>& a, const string& nom)
{
  if(a.es_buit() and h)
  {
    Arbre<string> fd, fe;
    pair<bool,individu> p =s.existeix(nom);
    string l= "*";
    l+=nom;
    l+="*";
    //li fico els asteriscos als que faltaven al parcial
    if(p.second.TePares())
    {
        string subpare = p.second.consultar_pare();
        string submare= p.second.consultar_mare();
        completar_arbol_genealogico_funcio(s,h,fe,subpare);
        completar_arbol_genealogico_funcio(s,h,fd,submare);
    }
  if(p.first) a.plantar(l,fe,fd);
  }

    else if(h)
    {
      Arbre<string> fe,fd;
      string arrel=a.arrel();
      a.fills(fe,fd);
      pair<bool,individu> p=s.existeix(arrel);


      if(fe.es_buit())
      { //EL DE LA ESQUERRA QUE ES EL PARE ME'L DONEN BUIT, SHA D EMPLENAR
        string pare=p.second.consultar_pare();
        completar_arbol_genealogico_funcio(s,h,fe,pare);
        }


      else if (not fe.es_buit())
      { //SI EL PARE NO ES BUIT, COMPROVAR-LO
         string pare = fe.arrel();
         h= (p.second.consultar_pare()==pare);
         if(h)
         {
           completar_arbol_genealogico_funcio(s,h,fe,pare);
         }
       }

    if(fd.es_buit())
    { //EL DE LA DRETA QUE ES LA MARE ME L DONEN BUIT
        string mare=p.second.consultar_mare();
        completar_arbol_genealogico_funcio(s,h,fd,mare);
      }

      else if (not fd.es_buit())
      { //SI EL MARE NO ES BUIT, COMPROVAR-LA
        string mare= fd.arrel();
        h=(p.second.consultar_mare()==mare);
        if(h)
        {
          completar_arbol_genealogico_funcio(s,h,fd,mare);
          }
      }
     a.plantar(arrel,fe,fd);
    }
  }
