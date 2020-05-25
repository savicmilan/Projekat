#ifndef BOJNOPOLJE_HPP_INCLUDED
#define BOJNOPOLJE_HPP_INCLUDED

#include "karakter.hpp"

//0=prazno polje
//1= krakter je tu
//2=neprijatelj je tu
class Bojnopolje
{
protected:
    int id;
    int polje[11][11];
    int primljeni_dmg=5;
    int hpn=10;
public:

    void popuniMapu()
    {
        int i,j;
        for(i=0;i<11;i++)
        {
            for(j=0;j<11;j++)
            {
                polje[i][j]=0;
            }
        }
    }
    int pozicija(int x, int y)
    {
        return polje[x][y];
    }
    bool pomeriSe(int x,int y, int r,int xi, int yi)
    {
        //cout<<x<<y<<xi<<yi;
        if(((xi-x<=r)||(xi-x>=-r)) && ((yi-y<=r)||(yi-y>=-r)) && polje[x][y]==0)
        {
            polje[xi][yi]=0;
            polje[x][y]=1;
            //cout<<polje[xi][yi];
            //cout<<polje[x][y];
            return true;
        }
        else
        {
            return false;
        }
    }
    int Napadni(int x, int y, int r, int xi, int yi, int damage)
    {
        //cout<<x<<y<<xi<<yi<<damage<<endl;
        if(((xi-x<=r)||(xi-x<=-r)) && ((yi-y<=r)||(yi-y<=-r)) && polje[x][y]==2)
        {
            hpn=hpn-damage;
            cout<<hpn;
            if(hpn<=0)
            {
                polje[x][y]=0;
                //cout<<polje[x][y];
                hpn=10;
                return 0;
            }
            else
            {
                return primljeni_dmg;
            }
        }
            return 0;
    }
    int getID()const
    {
        return id;
    }
    void CharStartPlaceNivo1()
    {
        polje[5][5]=1;
        polje[1][1]=2;
        polje[1][9]=2;
        polje[9][1]=2;
        polje[9][9]=2;
    }
    void ispis()
    {
        int i, j=0;
        cout<<' ';cout<<' ';cout<<' ';
        for(i=0;i<11;i++)
        {
            cout<<i<<')';
        }
        cout<<endl;
        for(i=0;i<11;i++)
        {
            if(i<10)
            {
                cout<<' '<<i<<')';
            }
            else
            {
                cout<<i<<')';
            }
            for(j=0;j<11;j++)
            {
                if(polje[i][j]==0)
                {
                    cout<<" ,";
                }
                else
                    cout<<polje[i][j]<<',';
            }
            cout<<endl;
        }
    }
};

#endif // BOJNOPOLJE_HPP_INCLUDED
