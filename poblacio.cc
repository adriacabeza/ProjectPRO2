/** @file poblacio.cc
    @brief Codi de la classe població
*/

#include "poblacio.hh"

  poblacio::poblacio()
  {}



  void poblacio::anadir_individuo(const especie& e, bool b)
  {
    string nom;
    char sex;
    cin >> nom >> sex;
    if(b) cout << " " << nom << endl;
    individu individuo(sex);
    if(not (this->existeix(nom).first))
    {
        individuo.LlegirGenotip(e);
        t.insert(make_pair(nom,individuo));
    }
    else cout << "  error" << endl;

}


  void poblacio::reproduccion_sexual(const especie& e)
  {
    string mare, pare, nom;
    cin >> mare >> pare >> nom;
    cout << "reproduccion_sexual " << mare << " " << pare << " " << nom << endl;
    pair<bool,individu> pairpare = this->existeix(pare);
    pair<bool,individu> pairmare = this->existeix(mare);
    pair<bool, individu> pairfill = this->existeix(nom);
    if(not pairpare.first or not pairmare.first or pairfill.first) cout << "  error" << endl;
    else if ((pairmare.second).Sexe() or (not (pairpare.second).Sexe()) or
        ((pairpare.second).consultar_pare() != "$" and (pairpare.second).consultar_pare() == (pairmare.second).consultar_pare()) or
        ((pairpare.second).consultar_mare() != "$" and (pairpare.second).consultar_mare() == (pairmare.second).consultar_mare()) or
        son_ascendents(pare,mare) or son_ascendents(mare,pare))
        cout << "  no es posible reproduccion" << endl;
    else
    {
      individu fill(pare,mare); //individu crear
      fill.barrejar_genotip(pairmare.second, pairpare.second, e);
      t.insert(make_pair(nom, fill));
   }
  }



bool poblacio::son_ascendents(string individua, string individub) const
{
    pair<bool,individu> p=this->existeix(individua);
    if(individub == p.second.consultar_pare()) return true;
    else if(individub ==p.second.consultar_mare()) return true;
    else if(not p.second.TePares()) return false;
    else
    {
      bool b=son_ascendents(p.second.consultar_pare(),individub);
      if(not b) b= son_ascendents(p.second.consultar_mare(),individub);
      return b;
    }
  }

// Escritura


void poblacio::escriure_familia_funcio(int nivell, map<int, vector<string> >& familia, const string& x)
{
  pair<bool, individu> p =this->existeix(x);
  if(p.first) familia[nivell].push_back(x);

  if(p.second.TePares())
  {
          ++nivell;
          escriure_familia_funcio(nivell,familia,((p.second).consultar_pare()));
          escriure_familia_funcio(nivell,familia,((p.second).consultar_mare()));
  }
}

  void poblacio::escribir_arbol_genealogico(const string& x)
  {
    if (not this->existeix(x).first) cout << "  error" << endl;
    else
    {
      map<int,vector<string> > familia;
      int nivell=0;
      escriure_familia_funcio(nivell,familia,x);
      for(map<int,vector<string> >::const_iterator it1=familia.begin(); it1 != familia.end();++it1)
      {
        cout <<  "  Nivel " << it1->first << ":";
        for(int i=0;i<(it1->second).size();++i)
        {
          cout << ' ' << (it1->second)[i];
        }
        cout << endl;
      }
    }
}




  void poblacio::escribir_poblacion() const
  {
    cout << endl;
    for(map<string, individu>::const_iterator i=t.begin(); i!= t.end();++i)
    {
      cout << "  " << i->first ;
      i->second.escriure_individu();
    }
}




pair <bool, individu > poblacio::existeix(const string& x) const
{
  pair <bool, individu > p;
  map<string,individu>::const_iterator i = t.find(x);
  if(i == t.end())
  {
    p.first=false;
    individu buit;
    p.second= buit;
  }
  else
  {
   p.first=true;
   p.second = (i->second);
  }
  return p;
}
