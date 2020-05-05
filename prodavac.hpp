#ifndef PRODAVAC_HPP_INCLUDED
#define PRODAVAC_HPP_INCLUDED

#include "oruzije.hpp"
#include "prica.hpp"

class Prodavac
{
protected:
    Oruzije proizvod;
    int cena;
    int koliko;
public:
    Prodavac(vrsta v, int d, int j, int c, int k): proizvod(v,d,j)
    {
        cena= c;
        koliko= k;
    }
    int getCena()
    {
        return cena;
    }

};

class Misija: public Prodavac
{
protected:
    Prica pric;
public:
    Misija(vrsta v, int d, int j, int c, int k, string s): Prodavac(v,d,j,c,k),pric(s)
    {

    }

};

#endif // PRODAVAC_HPP_INCLUDED
