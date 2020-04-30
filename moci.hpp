#ifndef MOCI_HPP_INCLUDED
#define MOCI_HPP_INCLUDED



enum vrstaMoci{fizicka,belaMagija,crnaMagija};

class Moc
{
protected:
    int power; //ponestalo mi je srpskih reci za snagu/jacuni
    vrstaMoci vrsta;
    int durDown;
public:
    Moc()
    {
        power+10;
        vrsta=fizicka;
        durDown=5;
    }
    Moc(int p, vrstaMoci v,int dD)
    {
        power=p;
        vrsta=v;
        durDown=dD;
    }
    int getDurDown()const
    {
        return durDown;
    }
};

#endif // MOCI_HPP_INCLUDED
