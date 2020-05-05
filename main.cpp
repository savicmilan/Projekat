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



int main()
{
    cout << "Hello world!" << endl;
    Moc djuro[3];
    citajMoci(djuro);
    return 0;
}
