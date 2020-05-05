#ifndef KARAKTER_HPP_INCLUDED
#define KARAKTER_HPP_INCLUDED

#include "moci.hpp";
#include "oruzije.hpp"
enum charclass {commner,noble,dancer}; // za sada imamo ovo jer me mrzi da dodajem jos 20+ koji se dobijaju na razlicite nacine

class Karakter
{
    private:
        int id;
        string ime;
        int pol;
        int hp;
        int level;
        int xp;
        int snaga;
        int magic;
        int range;
        int X;
        int Y;
        charclass clasa;
        Oruzije orudje;
        Moc mocc;
    public:
        Karakter(),Oruzije(),Moc()
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
            X=1;
            Y=1;
        }
        void proveriOruzije()
        {
            int c=orudje.ProveriDur();
            if(c==0)
            {
                snaga=snaga-orudje.getJacina();
            }
        }
        void proveriMoc()
        {
            int cc=mocc.getDurMoc();
            if(cc==0)
            {
                magic=magic-mocc.getPow();
            }
        }
        int getX()
        {
            return X;
        }
        int getY()
        {
            return Y;
        }
        void setX(int xx)
        {
           X=xx;
        }
        void setY(int yy)
        {
            Y=yy;
        }
        int getRange()
        {
            return range;
        }
};

#endif // KARAKTER_HPP_INCLUDED
