#ifndef MOCI_HPP_INCLUDED
#define MOCI_HPP_INCLUDED
#include <fstream>
using namespace std;

#include "splitsen.hpp"

class Moc
{
protected:
    int id;
    string ime;
    int power; //ponestalo mi je srpskih reci za snagu/jacuni
    int durMoc;
    int durDown;
public:
    Moc()
    {
        id=0;
        ime="EXPUROSION";
        power=10;
        durMoc=5;
        durDown=5;
    }
    Moc(int idd, string s, int p,int dM,int dD)
    {
        id=idd;
        ime=s;
        power=p;
        durMoc=dM;
        durDown=dD;
    }
    int getID()const
    {
        return id;
    }
    int getDurDown()const
    {
        return durDown;
    }
    void IskoristiMoc()
    {
        if(durMoc!=0)
            durMoc--;
    }
    int getPow()const
    {
        return power;
    }
    int getDurMoc()const
    {
        return durMoc;
    }
    void setID(int idd)
    {
        id=idd;
    }
    void setIme(string imee)
    {
        ime=imee;
    }
    void setPow(int pow)
    {
        power=pow;
    }
    void setDurMoc(int DM)
    {
        durMoc=DM;
    }
    void setDurDown(int DD)
    {
        durDown=DD;
    }

    friend ostream& operator<<(ostream& izlaz, Moc& m)
    {
        izlaz<<m.id<<','<<m.ime<<','<<m.power<<','<<m.durMoc<<','<<m.durDown<<endl;
        return izlaz;
    }
    void ucitajMoci(int BrojLinije)
    {
        string n="Moc_Lista.txt";
        string linija;
        vector<string> result;
        ifstream fajl (n);
        int i=0;
        if (fajl.is_open())
        {
            while ( getline (fajl,linija) && i<=BrojLinije) //you need to refine this its not finished yet
            {
                if (linija!="")
                {
                    result = splitSen(linija);
                    int x=stoi(result[0]);
                    id=(x);
                    ime=(result[1]);
                    x=stoi(result[2]);
                    power=(x);
                    x=stoi(result[3]);
                    durMoc=(x);
                    x=stoi(result[4]);
                    durDown=(x);
                }
                i++;
            }
            fajl.close();
        }
        else
            cout << "Error 1";
    }

};
void ucitajMoci(Moc& m, int BrojLinije)
{
        string n="Moc_Lista.txt";
        string linija;
        vector<string> result;
        ifstream fajl (n);
        int i=0;
        if (fajl.is_open())
        {
            while ( getline (fajl,linija) && i<=BrojLinije) //you need to refine this its not finished yet
            {
                if (linija!="")
                {
                    result = splitSen(linija);
                    int x=stoi(result[0]);
                    m.setID(x);
                    m.setIme(result[1]);
                    x=stoi(result[2]);
                    m.setPow(x);
                    x=stoi(result[3]);
                    m.setDurMoc(x);
                    x=stoi(result[4]);
                    m.setDurDown(x);
                }
                i++;
            }
            fajl.close();
        }
        else
            cout << "Error 1";
}
void citajFaijlMoci(Moc moc[])
{
    string ime="Moc_Lista.txt";
    string linija;
    string pomocna;
    ifstream fajl (ime);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << linija << '\n';

        }
        fajl.close();
    }

    else
        cout << "Error #1";

}
#endif // MOCI_HPP_INCLUDED
