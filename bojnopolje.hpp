#ifndef BOJNOPOLJE_HPP_INCLUDED
#define BOJNOPOLJE_HPP_INCLUDED

#include "karakter.hpp"

//0=prazno polje
//1= krakter je tu
//2=zid je tu

class Bojnopolje
{
protected:
    int id;
    int polje[11][11];
    Karakter kaka;
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
    bool pomeriSe(int x,int y)
    {
        int xi,yi,r;
        xi=kaka.getX();
        yi=kaka.getY();
        r=kaka.getRange();//OVDE SE KORISTI STATICKO POLJE
        if(((xi-x<=r)||(xi-x<=-r)) && ((yi-y<=r)||(yi-y<=-r)) && polje[x][y]==0)
        {
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
    int getID()const
    {
        return id;
    }
    void CharStartPlace()
    {
        polje[5][5];
        kaka.setX(5);
        kaka.setY(5);
    }
    void ispis()
    {
        int i, j;
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                cout<<polje[i][j]<<',';
            }
            cout<<endl;
        }
    }
};

#endif // BOJNOPOLJE_HPP_INCLUDED
