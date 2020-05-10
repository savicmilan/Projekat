#ifndef MOD_HPP_INCLUDED
#define MOD_HPP_INCLUDED

using namespace std;

enum Tezina{lako, normalno, tesko};

class Mod
{
    private:
        Tezina tez;
        bool smrtnost;
    public:
        Mod()
        {
            tez=normalno;
            smrtnost=false;
        }
        Mod(Tezina tezz, bool smrtnostt)
        {
            tez=tezz;
            smrtnost= smrtnostt;
        }
        Tezina getTez()
        {
            return tez;
        }
        bool getSmrt()
        {
            return smrtnost;
        }
        friend ostream& operator<<(ostream& izlaz, Mod& m)
        {
            izlaz<<m.smrtnost<<endl<<m.tez<<endl;
            return izlaz;
        }
};
//ovo je skroz zavrseno
#endif // MOD_HPP_INCLUDED
