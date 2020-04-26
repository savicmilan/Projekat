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
    Prodavac(int v, int d, int j, int c, int k): proizvod(v,d,j)
    {
        cena= c;
        koliko= k;
    }

};

class Misija: public Prodavac;
{
protected:
    Prica pric;
public:
    Misija(int v, int d, int j, int c, int k, stirng s): Prodavac(v,d,j,c,k),pric(s)
    {

    }

};

#endif // PRODAVAC_HPP_INCLUDED
