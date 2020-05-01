#ifndef MOCI_HPP_INCLUDED
#define MOCI_HPP_INCLUDED



enum vrstaMoci{fizicka,belaMagija,crnaMagija};

class Moc
{
protected:
    int power; //ponestalo mi je srpskih reci za snagu/jacuni
    vrstaMoci vrsta;
    int durMoc;
    int durDown;
public:
    Moc()
    {
        power=10;
        vrsta=fizicka;
        durMoc=5;
        durDown=5;
    }
    Moc(int p, vrstaMoci v,int dM,int dD)
    {
        power=p;
        vrsta=v;
        durMoc=dM;
        durDown=dD;
    }
    int getDurDown()const
    {
        return durDown;
    }
    int IskoristiMoc()
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
};

#endif // MOCI_HPP_INCLUDED
