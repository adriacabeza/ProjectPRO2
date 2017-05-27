/** @file especie.cc
    @brief Codi de la classe especie
*/
#include "especie.hh"

especie::especie()
{ }

void especie::LlegirEspecie()
{
  cin >> n >> puntdetall;
  vector<int> aux(n);
  for(int i=0;i<n;++i)
  {
    cin >> aux[i];
  }
  ln = aux;
  cin >> lx >> ly;;
}

int especie::llargada_iessim(int i) const
{
  return ln[i];
}

int especie::llargada_x() const
{
    return lx;
}

int especie::llargada_y() const
{
  return ly;
}

int especie::num_cromosomes() const
{
  return n;
}
int especie::punt_tall() const
{
  return puntdetall;
}
