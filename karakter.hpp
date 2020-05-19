#ifndef KARAKTER_HPP_INCLUDED
#define KARAKTER_HPP_INCLUDED

using namespace std;

#include "oruzije.hpp"

class Karakter
{
    protected:
        int id;
        string ime;
        int hp;
        int level;
        int snaga;
        static int range;
        int X;
        int Y;

    public:
        Oruzije orudje;
        Karakter()
        {
            id=1;
            ime="Djura";
            hp= 30;
            level=1;
            snaga=4+orudje.getJacina();
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
        void setId(int idd)
        {
            id=idd;
        }
        void setIme(string cx)
        {
            ime=cx;
        }
        void setLVL(int lvl)
        {
            level=lvl;
        }
        void setSnaga(int pow)
        {
            snaga=pow;
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
        void setHP(int h)
        {
            hp=h;
        }
        void setJacina(int pow)
        {
            snaga=pow;
        }
};
void ucitajKaratere(Karakter& k, int BrojLinije)
{
        string n="Karater.txt";
        string linija;
        vector<string> result;
        ifstream fajl (n);
        int i=0;
        int x;
        if (fajl.is_open())
        {
            while ( getline (fajl,linija) && i<BrojLinije) //you need to refine this its not finished yet
            {
                if (linija!="")
                {
                    result = splitSen(linija);
                    x=stoi(result[0]);
                    k.setId(x);
                    k.setIme(result[1]);
                    x=stoi(result[2]);
                    k.setHP(x);
                    x=stoi(result[3]);
                    k.setLVL(x);
                    x=stoi(result[4]);
                    k.setJacina(x);
                    x=stoi(result[5]);
                    k.setX(x);
                    x=stoi(result[6]);
                    k.setY(x);
                    x=stoi(result[7]);
                    ucitajOruzije(k.orudje,x,k.orudje.mo);
                }
                i++;
            }
            fajl.close();
        }
        else
            cout << "Error 1";
}
#endif // KARAKTER_HPP_INCLUDED
