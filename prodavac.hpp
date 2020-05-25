#ifndef PRODAVAC_HPP_INCLUDED
#define PRODAVAC_HPP_INCLUDED

#include "oruzije.hpp"
#include "prica.hpp"

class Prodavac
{
protected:
    Oruzije proizvod;
    int cena;
public:
    Prodavac()
    {
        cena=1000;
    }
    Prodavac(string v, int d, int j, int c, int mm): proizvod(v,d,j,mm)
    {
        cena= c;
    }
    int getCena()
    {
        return cena;
    }
    friend ostream& operator<<(ostream& izlaz, Prodavac& p)
    {
        izlaz<<p.cena<<endl;
        izlaz<<p.proizvod<<endl;
        return izlaz;
    }
};

class Misija: public Prodavac
{
protected:
    Prica pric;
public:
    Misija(string v, int d, int j, int c,int mm,string s): Prodavac(v,d,j,c,mm),pric(s)
    {

    }

};

#endif // PRODAVAC_HPP_INCLUDED
