#include <iostream>

using namespace std;

// pna je da  bude karakter koji se seta po mapi i ubija druge likove, ponekad one ubiju i njega
#include "moci.hpp"
#include "fe_igrica.hpp"
#include "bojnopolje.hpp"
#include "karakter.hpp"
#include "oruzije.hpp"
#include "mod.hpp"
#include "prica.hpp"
#include "prodavac.hpp"

int Karakter::range=2;

int main()
{
    PressEnterToContinue();
    system("cls");
    zapocniIgricu();
    return 0;
}
