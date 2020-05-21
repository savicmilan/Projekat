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
    Karakter kaka;
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
    Karakter getKaka()
    {
        return kaka;
    }
    bool pomeriSe(int x,int y)
    {
        int xi,yi,r;
        xi=kaka.getX();
        yi=kaka.getY();
        r=kaka.getRange();//OVDE SE KORISTI STATICKO POLJE
        if(((xi-x<=r)||(xi-x<=-r)) && ((yi-y<=r)||(yi-y<=-r)) && polje[x][y]==0)
        {
            polje[xi][yi]=0;
            kaka.setX(x);
            kaka.setY(y);
            polje[x][y]=1;
            return true;
        }
        else
        {
            return false;
        }
    }
    int Napadni(int x, int y)
    {
        int xi,yi,r,c;
        xi=kaka.getX();
        yi=kaka.getY();
        r=kaka.getRange();//OVDE SE KORISTI STATICKO POLJE
        if(((xi-x<=r)||(xi-x<=-r)) && ((yi-y<=r)||(yi-y<=-r)) && polje[x][y]==2)
        {
            hpn=hpn-kaka.getSnaga();
            kaka.orudje.smanjiDur();
            cout<<hpn;
            //cout<<kaka.getSnaga();
            //cout<<kaka.getHp();
            if(hpn<=0)
            {
                polje[x][y]=0;
                hpn=10;
                return 1;
            }
            else
            {
                c=kaka.getHp();
                //cout<<c;
                c=c-primljeni_dmg;
                //cout<<c;
                kaka.setHP(c);
                return 2;
            }
        }
        else
        {
            return 3;
        }
    }
    int NapadniSMoc(int x, int y)
    {
    int xi,yi,r,c;
        xi=kaka.getX();
        yi=kaka.getY();
        r=kaka.getRange();//OVDE SE KORISTI STATICKO POLJE
        //cout<<hpn;
        if(((xi-x<=r)||(xi-x<=-r)) && ((yi-y<=r)||(yi-y<=-r)) && polje[x][y]==2)
        {
            hpn=hpn-kaka.orudje.mo.getPow();
            //cout<<hpn;
            kaka.orudje.mo.IskoristiMoc();
            c=kaka.orudje.getDur();
            c=c-kaka.orudje.mo.getDurDown();
            kaka.orudje.setDur(c);
            if(hpn<=0)
            {
                polje[x][y]=0;
                hpn=10;
                return 1;
            }
            else
            {
                c=kaka.getHp();
                //cout<<c;
                c=c-primljeni_dmg;
                //cout<<c;
                kaka.setHP(c);
                return 2;
            }
        }
        else
        {
            return 3;
        }
    }
    int getID()const
    {
        return id;
    }
    void CharStartPlaceNivo1()
    {
        polje[5][5]=1;
        kaka.setX(5);
        kaka.setY(5);
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
