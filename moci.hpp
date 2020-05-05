#ifndef MOCI_HPP_INCLUDED
#define MOCI_HPP_INCLUDED
#include <fstream>
using namespace std;

enum vrstaMoci{fizicka,belaMagija,crnaMagija};

class Moc
{
protected:
    int id;
    string ime;
    int power; //ponestalo mi je srpskih reci za snagu/jacuni
    vrstaMoci vrsta;
    int durMoc;
    int durDown;
public:
    Moc()
    {
        int id=0;
        ime="EXPUROSION";
        power=10;
        vrsta=crnaMagija;
        durMoc=5;
        durDown=5;
    }
    Moc(int idd, string s, int p, vrstaMoci v,int dM,int dD)
    {
        id=idd;
        ime=s;
        power=p;
        vrsta=v;
        durMoc=dM;
        durDown=dD;
    }
    int getDurDown()const
    {
        return durDown;
    }
    void IskoristiMoc()
    {
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
    void setVrsta(vrstaMoci vrstaa)
    {
        vrsta=vrstaa;
    }
    void setDurMoc(int DM)
    {
        durMoc=DM;
    }
    void setDurDown(int DD)
    {
        durDown=DD;
    }
};

void citajMoci(Moc moc[])
{
    string ime="Moc_Lista.txt";
    string linija;
    string pomocna;
    ifstream fajl (ime);
    int i=0,k=0,j=0;
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << linija << '\n';
            moc[i].setID(linija[0]-'0');

            for(k=2; linija[k]!=',';k++ && j++)
            {
                pomocna[j]=linija[k];
            }
            moc[i].setIme(pomocna);
            k=k+1;
            moc[i].setPow(linija[k]-'0');
            k=k+2;
            for(j=0;linija[k]!=',';k++ && j++)
            {
                pomocna[j]=linija[k];
            }
            k++;
            moc[i].setDurMoc(linija[k]-'0');
            k=k+2;
            moc[i].setDurDown(linija[k]-'0');
            i++;
        }
        fajl.close();
    }

    else
        cout << "Error #1";

}

#endif // MOCI_HPP_INCLUDED
