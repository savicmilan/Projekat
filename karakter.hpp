#ifndef KARAKTER_HPP_INCLUDED
#define KARAKTER_HPP_INCLUDED

#include "moc";

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
        int speeed;
        int def;
        int range;
        charclass clasa;
        Oruzije orudje;
        Moc mocc;
};

#endif // KARAKTER_HPP_INCLUDED
