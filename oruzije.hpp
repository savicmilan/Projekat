#ifndef ORUZIJE_HPP_INCLUDED
#define ORUZIJE_HPP_INCLUDED

#include "moci.hpp"
#define MAXX 40

class Oruzije
{
private:
    int id;
    string oruzijee;
    int durability;
    int jacina;
public:
    Moc mo;
    Oruzije()
    {
        oruzijee="mac";
        durability=MAXX;
        jacina=6;
    }
    Oruzije(string oruz, int dd, int jj)
    {
        oruzijee=oruz;
        durability=dd;
        jacina=jj;
    }
    Oruzije(const Oruzije& o)
    {
        oruzijee=o.oruzijee;
        durability=o.durability;
        jacina=o.jacina;
    }

    void smanjiDur()
    {
        if(durability!=0)
            durability--;
    }
    //kada se iskoristi oruzije ovaj broj se smanjuje jer duravility predstavlja broj preostalih koriscenja
    void popraviOruzije()
    {
        if(durability!=MAXX)
            durability=40;
    }
    //ovo popravlja oruzije ako je korisceno i ako zatreba
    void pojacajOruzije()
    {
        jacina++;
    }
    //ovo ostri oruzije da bi ono bilo jace
    void pojacajOruzijeZA(int x)
    {
        jacina=jacina+x;
    }
    //ovo ostri oruzije ali malo bolje nego ono ranije, ovo bi trebalo da se otkljuca kasnije u igrici
    void MocDown()
    {
        int c=mo.getDurDown();
        durability=durability-c;
    }
    int getJacina()const
    {
        return jacina;
    }
    int getDur()const
    {
        return durability;
    }
    int ProveriDur()
    {
        if(durability==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    void setDur(int d)
    {
        durability=d;
    }
    void setIme(string v)
    {
        oruzijee=v;
    }
    void setJacina(int j)
    {
        jacina=j;
    }
    void setId(int idd)
    {
        id=idd;
    }
    Moc getMoc()const
    {
        return mo;
    }
    friend ostream& operator<<(ostream& izlaz, Oruzije& o)
    {
        izlaz<<o.id<<','<<o.oruzijee<<','<<o.durability<<','<<o.jacina<<',';
        return izlaz;
    }
    void ispisi()
    {
        cout<<id<<oruzijee<<durability<<jacina;
    }
    int getId()
    {
        return id;
    }
};


void ucitajOruzije(Oruzije& o, int BrojLinije)
{
        string n="Oruzije_lista.txt";
        string linija;
        vector<string> result;
        ifstream fajl (n);
        int i=0;
        int x;
        if (fajl.is_open())
        {
            while ( getline (fajl,linija) && i<=BrojLinije) //you need to refine this its not finished yet
            {
                if (linija!="")
                {
                    result = splitSen(linija);
                    x=stoi(result[0]);
                    o.setId(x);
                    o.setIme(result[1]);
                    x=stoi(result[2]);
                    o.setDur(x);
                    x=stoi(result[3]);
                    o.setJacina(x);
                    x=stoi(result[4]);
                    ucitajMoci(o.mo,x);
                }
                i++;
            }
            fajl.close();
        }
        else
            cout << "Error 1";
}
#endif // ORUZIJE_HPP_INCLUDED
