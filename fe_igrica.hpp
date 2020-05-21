#ifndef FE_IGRICA_HPP_INCLUDED
#define FE_IGRICA_HPP_INCLUDED
#include <vector>
#include "bojnopolje.hpp"

using namespace std;

class Igrica
{
protected:
    int pare;
public:
    vector<Bojnopolje*> SaveFile;
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
void chooseSavefile(int& x)
{
    cout<<"choose savefile 1,2 or 3"<<endl;
    cin>>x;
    x--;
}
void upisisve(Karakter kaka, int i)
{
    ofstream fajl;
    cout<<"i am a pice of garbage";
    int x;
    if(i==0)
    {
    fajl.open("Karater.txt");
    x=kaka.orudje.getId();
    fajl<< kaka << x<<endl;
    fajl.close();

    fajl.open("Oruzije_lista.txt");
    x=kaka.orudje.mo.getID();
    fajl<< kaka.orudje << x<<endl;
    fajl.close();

    fajl.open("Moc_Lista.txt");
    fajl<< kaka.orudje.mo<<endl;
    fajl.close();
    }
    else
    {
    fajl.open("Karater.txt",ios_base::app);
    fajl<<kaka<<kaka.orudje.getId()<<endl;
    fajl.close();

    fajl.open("Oruzije_lista.txt",ios_base::app);
    fajl<<kaka.orudje<<kaka.orudje.mo.getID()<<endl;
    fajl.close();

    fajl.open("Moc_Lista.txt",ios_base::app);
    fajl<<kaka.orudje.mo<<endl;
    fajl.close();
    }
}


void zapocniIgricu()
{
    int rad,i;
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
    chooseSavefile(SAVEFILENB);
    //SAVEFILENB-=1;
    system("cls");
    //PressEnterToContinue();
    system("cls");
    ucitajKaratere(projeka.SaveFile[SAVEFILENB]->kaka,SAVEFILENB);
    projeka.SaveFile[SAVEFILENB]->CharStartPlaceNivo1();
    int hpkara=projeka.SaveFile[SAVEFILENB]->kaka.getHp();
    int pozicija1,pozicija2,uspesno2,pom=0,brm=0;
    bool uspesno;
    do
    {
        projeka.SaveFile[SAVEFILENB]->ispis();
        cout<<"Informacije o karakteru"<<endl;
        cout<<"id: Ime: HP: LVL: Attack: X: Y:"<<endl;
        cout<<projeka.SaveFile[SAVEFILENB]->kaka<<endl;
        cout<<"izaberi radnju"<<endl<<"1) Pomeranje"<<endl<<"2) napad"<<endl<<"3) Iskoristi moc"<<endl;
        cin>>rad;
        switch(rad)
        {
        case 1:
            {
                cin>>pozicija1;
                cin>>pozicija2;
                uspesno=projeka.SaveFile[SAVEFILENB]->pomeriSe(pozicija1,pozicija2);
                break;
            }
        case 2:
            {
                cin>>pozicija1;
                cin>>pozicija2;
                uspesno2=projeka.SaveFile[SAVEFILENB]->Napadni(pozicija1,pozicija2);
                if(uspesno2==1)
                {
                    pom++;
                }
                hpkara=projeka.SaveFile[SAVEFILENB]->kaka.getHp();
                break;
            }
        case 3:
            {
                cin>>pozicija1;
                cin>>pozicija2;
                uspesno2=projeka.SaveFile[SAVEFILENB]->NapadniSMoc(pozicija1,pozicija2);
                if(uspesno2==1)
                {
                    pom++;
                }
                hpkara=projeka.SaveFile[SAVEFILENB]->kaka.getHp();
                break;
            }
        }
        //system("cls");
    }while(rad!=0 && hpkara>0 && pom<4);
    brm=brm+pom;
    for(i=0;i<SAVEFILENB;i++)
    {
        upisisve(projeka.SaveFile[i]->kaka,i);
    }
    ofstream fajl;
    fajl.open("Izlaz.txt");
    fajl<<brm;
    fajl.close();

}
#endif // FE_IGRICA_HPP_INCLUDED
