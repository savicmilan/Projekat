#ifndef MOCI_HPP_INCLUDED
#define MOCI_HPP_INCLUDED

#include "oruzije.hpp"

enum vrstaMoci{fizicka,belaMagija,crnaMagija};

class Moc
{
    Oruzije o;
    int power; //ponestalo mi je srpskih reci za snagu/jacuni
    vrstaMoci vrsta;
};

#endif // MOCI_HPP_INCLUDED
