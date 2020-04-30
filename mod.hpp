#ifndef MOD_HPP_INCLUDED
#define MOD_HPP_INCLUDED

enum Tezina (lako, normalno, tesko};

class Mod
{
    private:
        Tezina tez;
        bool smrtnost;
    public:
        Mod()
        {
            tez=1;
            smrtnost=false;
        }
        Mod(Tezina tezz, bool smrtnostt)
        {
            tez=tezz;
            smrtnost= smrtnostt;
        }

};
//ovo je skroz zavrseno
#endif // MOD_HPP_INCLUDED
