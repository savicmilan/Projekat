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
        int idoruzije;
    public:
        Karakter()
        {
            id=1;
            ime="Djura";
            hp= 30;
            level=1;
            snaga=4;
            X=1;
            Y=1;

        }
        void setCords(int xx, int yy)
        {
            X=xx;
            Y=yy;
        }
        void powerUP(int x)
        {
            snaga=snaga+x;
        }
        void powerDown(int x)
        {
            snaga=snaga-x;
        }
        void smanjiHP(int hpminus)
        {
            hp=hp-hpminus;
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
        int getSnaga()const
        {
            return snaga;
        }

        friend ostream& operator<<(ostream& izlaz, Karakter& k)
        {
            izlaz<<k.id<<','<<k.ime<<','<<k.hp<<','<<k.level<<','<<k.snaga<<','<<k.X<<','<<k.Y<<','<<k.idoruzije<<endl;
            return izlaz;
        }
        int getHp()
        {
            return hp;
        }
        void setOrId(int x)
        {
            idoruzije=x;
        }
        int getVoidID()const
        {
            return idoruzije;
        }

        void ucitajKaratere(int BrojLinije)
        {
            BrojLinije++;
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
                            //cout<<"s"<<x<<"s";
                            id=x;
                            ime=(result[1]);
                            // cout<<result[1];
                            x=stoi(result[2]);
                            hp=x;
                            x=stoi(result[3]);
                            level=x;
                            x=stoi(result[5]);
                            X=x;
                            x=stoi(result[6]);
                            Y=x;
                            x=stoi(result[7]);
                            idoruzije=x;
                            //cout<<k.orudje;
                            // cout<<"z"<<x;
                            x=stoi(result[4]);
                            setJacina(x);
                    }
                    i++;
                }
            fajl.close();
        }
            else
                cout << "Error 1";
        }
};

#endif // KARAKTER_HPP_INCLUDED
