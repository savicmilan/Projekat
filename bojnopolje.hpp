#ifndef BOJNOPOLJE_HPP_INCLUDED
#define BOJNOPOLJE_HPP_INCLUDED

#include "karakter.hpp"

//0=prazno polje
//1= krakter je tu
//2=zid je tu

class Bojnopolje
{
private:
    int polje[10][10];
    Karakter kaka;
public:
    void popuniMapu()
    {
        int i,j;
        for(i=0;i<20;i++)
        {
            for(j=0;j<20;j++)
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
        r=kaka.getRange();
        if(((xi-x<=r)||(xi-x<=-r)&&((yi-y<=r)||(yi-y<=-r))&&polje[x][y]==0))
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


};

#endif // BOJNOPOLJE_HPP_INCLUDED
