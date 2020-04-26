#ifndef ORUZIJE_HPP_INCLUDED
#define ORUZIJE_HPP_INCLUDED

enum vrsta {mac,luk,sekira,koplje,magija};

class Oruzije
{
private:
    vrsta oruzijee;
    int durability;
    int jacina;
public:
    Oruzije()
    {
        oruzijee=0;
        durability=40;
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
};

#endif // ORUZIJE_HPP_INCLUDED
