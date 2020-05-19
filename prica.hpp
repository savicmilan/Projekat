#ifndef PRICA_HPP_INCLUDED
#define PRICA_HPP_INCLUDED

using namespace std;

class Prica
{
 protected:
     string prica; // stvarno ne znam kako cu ovo da izvedem
 public:
     Prica()
     {
         prica="Djuro je popio vodu";
     }
     Prica(string ss)
     {
         prica= ss;
     }
     friend ostream& operator<<(ostream& izlaz, const Prica& p)
     {
         izlaz<<p.prica<<endl;
         return izlaz;
     }
     virtual void Ispisi()
     {
         cout<<prica;
     }
};
class PricaMisija: public Prica
{
protected:
    bool uradjena;
public:
    void PiracMisija(bool bb)
    {
        uradjena=bb;
    }
    void Ispisi()
    {
        if(uradjena==true)
        {
            cout<<"Misija je uradjena";
        }
        else
        {
            cout<<"Treba uraditi misiju: "<<endl<<prica;
        }
    }
};

#endif // PRICA_HPP_INCLUDED
