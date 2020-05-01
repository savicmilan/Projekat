#ifndef KARAKTER_HPP_INCLUDED
#define KARAKTER_HPP_INCLUDED

#include "moc";
#include "oruzije.hpp"
enum charclass {commner,noble,dancer}; // za sada imamo ovo jer me mrzi da dodajem jos 20+ koji se dobijaju na razlicite nacine

class Karakter
{
    private:
        int id;
        char ime[16];
        int pol;
        int hp;
        int level;
        int xp;
        int snaga;
        int magic;
        int range;
        charclass clasa;
        Oruzije orudje;
        Moc mocc;
    public:
        Karakter():Oruzije(),Moc()
        {
            id=1;
            ime="Djura";
            pol=0;
            hp= 30;
            level=1;
            xp=0;
            snaga=4+orudje.getJacina();
            magic=2+mocc.getPow();
            range=3;
        }
        void proveriOruzije()
        {
            int c=orudje.ProveriDur()
            if(c==0)
            {
                snaga=snaga-orudje.getJacina();
            }
        }
        void proveriMoc()
        {
            int cc=mocc.getDurMoc()
            if(cc==0)
            {
                magic=magic-mocc.getPow();
            }
        }
};

#endif // KARAKTER_HPP_INCLUDED
