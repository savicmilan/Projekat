#ifndef FE_IGRICA_HPP_INCLUDED
#define FE_IGRICA_HPP_INCLUDED
#include <vector>
#include "bojnopolje.hpp"

using namespace std;

class Igrica
{
protected:
    int pare;
    vector<Bojnopolje*> SaveFile;
public:
    Igrica()
    {
        pare=0;
    }
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
    void Searchfor()
    {
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
        for (auto it=SaveFile.begin(); it<SaveFile.end(); it++)
        {
            if (t.getID()==(*it)->getID())
            {
                SaveFile.erase(it);

            }
        }
    }
};

void PressEnterToContinue()
{
    cout<<"Press any key plus enter to continue"<<endl;
    char x;
    cin>>x;
}
int MainMenu()
{
    cout<<"1.-start game"<<endl;
    cout<<"2.-end game"<<endl;
    int x;
    cin>>x;
    return x;
}
int chooseSavefile()
{
    cout<<"choose savefile 1,2 or 3"<<endl;
    int x;
    cin>>x;
    return x;
}



void zapocniIgricu()
{
    Igrica projeka;
    Bojnopolje SaveFile1;
    Bojnopolje SaveFile2;
    Bojnopolje SaveFile3;
    SaveFile1.popuniMapu();
    SaveFile2.popuniMapu();
    SaveFile3.popuniMapu();
    projeka.NovaIgra(&SaveFile1);
    projeka.NovaIgra(&SaveFile2);
    projeka.NovaIgra(&SaveFile3);
    int SAVEFILENB=MainMenu();
    system("cls");
    if(SAVEFILENB==2)
    {
        return;
    }
    SAVEFILENB=chooseSavefile();
    system("cls");
    PressEnterToContinue();
    system("cls");

}
#endif // FE_IGRICA_HPP_INCLUDED
