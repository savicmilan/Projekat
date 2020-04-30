#ifndef ORUZIJE_HPP_INCLUDED
#define ORUZIJE_HPP_INCLUDED

#include "moci.hpp"
#define MAXX=40;
enum vrsta {mac,luk,sekira,koplje,magija};

class Oruzije
{
private:
    Moc mo;
    vrsta oruzijee;
    int durability;
    int jacina;
public:
    Oruzije(): Moc();
    {
        oruzijee=0;
        durability=MAXX;
        jacina=6;
    }
    Oruzije(vrsta or, int dd, int jj)
    {
        oruzijee=or;
        durability=dd;
        jacina=jj;
    }
    Oruzije(const Oruzije o)
    {
        oruzijee=o.oruzijee;
        durability=o.durability;
        jacina=o.jacina;
    }

    void smanjiDur()
    {
        if(durability!=0)
            durability--;
    }
    //kada se iskoristi oruzije ovaj broj se smanjuje jer duravility predstavlja broj preostalih koriscenja
    void popraviOruzije()
    {
        if(durability!=MAXX)
            durability=40;
    }
    //ovo popravlja oruzije ako je korisceno i ako zatreba
    void pojacajOruzije()
    {
        jacina++;
    }
    //ovo ostri oruzije da bi ono bilo jace
    void pojacajOruzijeZA(int x)
    {
        jacina=jacina+x;
    }
    //ovo ostri oruzije ali malo bolje nego ono ranije, ovo bi trebalo da se otkljuca kasnije u igrici
    void MocDown()
    {
        int c=mo.getDurDown();
        durability=durability-c;
    }

};

#endif // ORUZIJE_HPP_INCLUDED
