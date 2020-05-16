#ifndef FE_IGRICA_HPP_INCLUDED
#define FE_IGRICA_HPP_INCLUDED
#include <vector>
#include "bojnopolje.hpp"


class Igrica
{
protected:
    int pare;
    vector<Bojnopolje*> SaveFile;
public:
    void NovaIgra(Bojnopolje* b)
    {
        SaveFile.push_back(b);
    }
    void ispisiSaveFilove(){
        cout<<"Lista Filova: "<<endl;

        for (auto it=SaveFile.begin(); it<SaveFile.end(); it++)
        {
            (*it)->ispis();

        }
    }
    void Searchfor(){
        cout<<"Izaberi save file"<<endl;
        int x;
        cin>>x;

        for (auto it=SaveFile.begin(); it<SaveFile.end(); it++)
        {
                if ((*it)->getID()==x)
                    (*it)->ispis();

        }
    }
    void ToaletPapir(const Bojnopolje& t)
    {
        for (auto it=SaveFile.begin(); it<SaveFile.end(); it++){
            if (t.getID()==(*it)->getID())
                {
                SaveFile.erase(it);

            }
        }
    }


};

#endif // FE_IGRICA_HPP_INCLUDED
