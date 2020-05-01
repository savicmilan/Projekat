#ifndef BOJNOPOLJE_HPP_INCLUDED
#define BOJNOPOLJE_HPP_INCLUDED

#include "karakter.hpp"
typedef struct PozicijaKaraktera
{
    Karakter kaka;
    int x;
    int y;
} POZICIJAKARAKTERA;

class Bojnopolje
{
private:
    int polje[10][10];
    POZICIJAKARAKTERA karekteri;

public:
    //void PomeriSe()

};

#endif // BOJNOPOLJE_HPP_INCLUDED
