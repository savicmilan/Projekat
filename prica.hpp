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
};

#endif // PRICA_HPP_INCLUDED
