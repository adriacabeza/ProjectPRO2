/** @file individu.cc
    @brief Codi de la classe individu
*/
#include "individu.hh"

individu::individu(char& sex)
{
  if(sex == 'X') sexe = false;
  else sexe = true;
  te_ascendencia = false;
  pare = "$";
  mare = "$";
}

individu::individu()
{
   te_ascendencia = false;
   pare = "$";
   mare = "$";
   sexe = false;
 }


 // Constructors
individu::individu(string& dad, string& mum)
{
   mare=mum;
   pare=dad;
   te_ascendencia=true;
   sexe = false;
}

bool individu::consultar_gen(int i,bool j, int x) const
{
  if(not j) return  genotip[i].first[x];
  else return genotip[i].second[x]; }


void individu::barrejar_genotip(individu& mum, individu& dad, const especie& e)
{
//per emplenar el seu genotip
  sexe=true;
  vector < pair <vector<bool>, vector<bool> > > genotipaux (e.num_cromosomes()+1);
  vector<info> informacio(e.num_cromosomes()+1);
  for(int i=0;i<e.num_cromosomes()+1;++i)
  {
    cin>>informacio[i].primer>>informacio[i].segon>>informacio[i].puntall;
  }

  //SEXUAL
  //PRIMER EL X
    for(int t=0;t<e.llargada_x();++t)
    {
      if(t >= informacio[0].puntall and t<e.punt_tall())
      {
        genotipaux[0].first.push_back(dad.consultar_gen(0,informacio[0].segon,t));
      }
      else
      {
        genotipaux[0].first.push_back(mum.consultar_gen(0,informacio[0].primer,t));
      }
    }

  //DESPRÉS MIRO SI EL X O EL Y
    if(informacio[0].segon==0)
    {
      sexe = false;
    for(int t=0;t<e.llargada_x();++t)
    {
      if(t>=informacio[0].puntall and t<e.punt_tall())
      {
        genotipaux[0].second.push_back(mum.consultar_gen(0,informacio[0].primer,t));
        }
      else
      {
        genotipaux[0].second.push_back(dad.consultar_gen(0,informacio[0].segon,t));
        }
      }
    }
    else
    {
      for(int t=0;t<e.llargada_y();++t)
      {
        if(t>=informacio[0].puntall and t<e.punt_tall())
        {
          genotipaux[0].second.push_back(mum.consultar_gen(0,informacio[0].primer,t));
          }
        else
        {
          genotipaux[0].second.push_back(dad.consultar_gen(0,informacio[0].segon,t));
          }
        }
    }

//AUTOSOMES

  for(int j=1;j<e.num_cromosomes()+1;++j)
  {
    for(int x=0;x<e.llargada_iessim(j-1);++x)
    {
      if(x<informacio[j].puntall)
      {
        genotipaux[j].first.push_back(mum.consultar_gen(j,informacio[j].primer,x));
        genotipaux[j].second.push_back(dad.consultar_gen(j,informacio[j].segon,x));
      }
      else
      {
        genotipaux[j].first.push_back(dad.consultar_gen(j,informacio[j].segon,x));
        genotipaux[j].second.push_back(mum.consultar_gen(j,informacio[j].primer,x));
      }
    }
  }
  genotip=genotipaux;
}


void individu::LlegirGenotip(const especie& e)
{
  vector < pair <vector<bool>, vector<bool> > > genotipaux (e.num_cromosomes()+1);
  bool gen;
    for(int i=0;i<e.llargada_x();++i)
    {
      cin >> gen;
      genotipaux[0].first.push_back(gen);
    }

    if(not sexe)
    {
      for(int i=0;i<e.llargada_x();++i)
      {
        cin >> gen;
        genotipaux[0].second.push_back(gen);
      }
    }
    else
    {
    for(int i=0;i<e.llargada_y();++i)
    {
      cin>>gen;
      genotipaux[0].second.push_back(gen);
    }
  }

      //sexuals incialitzats
  for(int j=0;j<e.num_cromosomes();++j)
  {

      for(int i=0;i<e.llargada_iessim(j);++i)
      {
        cin>>gen;
        genotipaux[j+1].first.push_back(gen);
      }

      for(int i=0;i<e.llargada_iessim(j);++i)
      {
        cin>>gen;
        genotipaux[j+1].second.push_back(gen);
      }
    }
    genotip=genotipaux;

  }

void individu::escriure_individu() const
{
  cout << " X";
  if(sexe==true) cout << "Y";
  else cout << "X";
  cout << " " << "(" << pare << "," << mare << ")" << endl;
}


 void individu::escribir_genotipo() const
 {
   //ARREGLAR LA MANERA DE TRUERE LES COSES
   cout << endl;
   if(not genotip.empty())
   {
     for(int i=0;i<genotip[0].first.size();++i)
     {
       if(i==0)
       { cout << "  X:";}
       cout << " " << genotip[0].first[i];
     }
     cout << endl;
     for(int i=0;i<genotip[0].second.size();++i)
     {
       if(i==0 and sexe==true)
       {cout << "  Y:";}
       else if(i==0 and sexe==false) cout << "  X:";
       cout << " " << genotip[0].second[i];
     }
     cout << endl;
     int count=1;
     for(int e=1;e<genotip.size();++e)
     {
       for(int j=0;j<genotip[e].first.size();++j)
       {
         if(j==0)
         { cout << "  " << count << "." << 1 << ":";}
         cout << " " << genotip[e].first[j];

       }
       cout << endl;
        for(int t=0;t<genotip[e].second.size();++t)
        {
           if (t==0) cout << "  " << count << "." << 2 << ":";
           cout << " " << genotip[e].second[t];
        }
        cout << endl;
        ++count;
        }
    }
}

  bool individu::TePares() const
  {
    return te_ascendencia;
  }

  bool individu::Sexe() const
  {
    return sexe;
  }

  string individu::consultar_pare() const
  {
    return pare;
  }

  string individu::consultar_mare() const
  {
    return mare;
  }
