#ifndef FE_IGRICA_HPP_INCLUDED
#define FE_IGRICA_HPP_INCLUDED
#include <vector>
#include "bojnopolje.hpp"
#include <iostream>
using namespace std;

class Igrica
{
protected:
    int pare;
public:
    vector<Bojnopolje*> SaveFile;
    vector<Karakter> Charcter;
    vector<Oruzije> Weapon;
    vector<Moc> Power;
    Igrica()
    {
        pare=0;
    }
    void NovaIgra(Bojnopolje* b)
    {
        SaveFile.push_back(b);
    }
    void NewChar(Karakter c)
    {
        Charcter.push_back(c);
    }
    void NewWepon(Oruzije o)
    {
        Weapon.push_back(o);
    }
    void NewPower(Moc m)
    {
        Power.push_back(m);
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
void upisisve(Karakter &k,Oruzije &o, Moc &m,int i)
{
    ofstream fajl;
    if(i==0)
    {
        fajl.open("Karater.txt");
        fajl<<k;
        fajl.close();

        fajl.open("Oruzije_lista.txt");
        fajl<<o;
        fajl.close();

        fajl.open("Moc_Lista.txt");
        fajl<<m;
        fajl.close();
    }
    else
    {
        fajl.open("Karater.txt", ios_base::app);
        fajl<<k;
        fajl.close();

        fajl.open("Oruzije_lista.txt", ios_base::app);
        fajl<<o;
        fajl.close();

        fajl.open("Moc_Lista.txt", ios_base::app);
        fajl<<m;
        fajl.close();
    }
}

void zapocniIgricu()
{
    int rad,i,pomm;
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
    Karakter Kara1;
    Karakter Kara2;
    Karakter Kara3;
    projeka.NewChar(Kara1);
    projeka.NewChar(Kara2);
    projeka.NewChar(Kara3);
    Oruzije Or1;
    Oruzije Or2;
    Oruzije Or3;
    projeka.NewWepon(Or1);
    projeka.NewWepon(Or2);
    projeka.NewWepon(Or3);
    Moc Mo1;
    Moc Mo2;
    Moc Mo3;
    projeka.NewPower(Mo1);
    projeka.NewPower(Mo2);
    projeka.NewPower(Mo3);
    for(i=0;i<3;i++)
    {
        projeka.Charcter[i].ucitajKaratere(i);
        projeka.Power[i].ucitajMoci(i);
        projeka.Weapon[i].ucitajOruzije(i);

    }
    int SAVEFILENB=MainMenu();
    system("cls");
    if(SAVEFILENB==2)
    {
        return;
    }
    chooseSavefile(SAVEFILENB);
    cout<< SAVEFILENB;
    //SAVEFILENB-=1;
    system("cls");
    PressEnterToContinue();
    system("cls");
    int test=projeka.Weapon[SAVEFILENB].getJacina();
    projeka.Charcter[SAVEFILENB].powerUP(test);
    projeka.SaveFile[SAVEFILENB]->CharStartPlaceNivo1();
    projeka.Charcter[SAVEFILENB].setCords(5,5);
    int hpkara=projeka.Charcter[SAVEFILENB].getHp();
    cout<<hpkara;
    int pozicija1,pozicija2,uspesno2,pom=0,brm=0;
    bool uspesno,pokvareno;
    do
    {
        projeka.SaveFile[SAVEFILENB]->ispis();
        cout<<"Informacije o karakteru"<<endl;
        cout<<"id: Ime: HP: LVL: Attack: X: Y:"<<endl;
        cout<<projeka.Charcter[SAVEFILENB];
        cout<<projeka.Weapon[SAVEFILENB];
        cout<<projeka.Power[SAVEFILENB]<<endl;
        cout<<"izaberi radnju"<<endl<<"1) Pomeranje"<<endl<<"2) napad"<<endl<<"3) Iskoristi moc"<<endl;
        cin>>rad;
        //cout<<rad;
        /*pokvareno=projeka.Weapon[SAVEFILENB].ProveriDur();
        if(pokvareno==false)
        {
            projeka.Charcter[SAVEFILENB].powerDown(test);
        }*/
        switch(rad)
        {
            case 1:
                {
                    cout<<"Unesi koordinate x i y"<<endl;
                    cin>>pozicija1;
                    cin>>pozicija2;
                    int xi=projeka.Charcter[SAVEFILENB].getX();
                    int yi=projeka.Charcter[SAVEFILENB].getY();
                    int r= projeka.Charcter[SAVEFILENB].getRange();
                    //cout<< xi <<yi;
                    pomm=projeka.SaveFile[SAVEFILENB]->pozicija(pozicija1,pozicija2);
                    uspesno=projeka.SaveFile[SAVEFILENB]->pomeriSe(pozicija1,pozicija2,r,xi,yi);
                    //cout<<pomm;
                    if(pomm==0)
                    {
                        projeka.Charcter[SAVEFILENB].setCords(pozicija1,pozicija2);
                    }
                    break;
                }
            case 2:
                {
                    cout<<"Unesi koordinate x i y"<<endl;
                    cin>>pozicija1;
                    cin>>pozicija2;
                    int xi=projeka.Charcter[SAVEFILENB].getX();
                    int yi=projeka.Charcter[SAVEFILENB].getY();
                    int r= projeka.Charcter[SAVEFILENB].getRange();
                    int snaga=projeka.Charcter[SAVEFILENB].getSnaga();
                    int nemaviseimena;
                    nemaviseimena=projeka.SaveFile[SAVEFILENB]->Napadni(pozicija1,pozicija2,r,xi,yi,snaga);
                    projeka.Charcter[SAVEFILENB].smanjiHP(nemaviseimena);
                    projeka.Weapon[SAVEFILENB].smanjiDur();
                    break;
                }
            case 3:
                {
                    cout<<"Unesi koordinate x i y"<<endl;
                    cin>>pozicija1;
                    cin>>pozicija2;
                    int xi=projeka.Charcter[SAVEFILENB].getX();
                    int yi=projeka.Charcter[SAVEFILENB].getY();
                    int r= projeka.Charcter[SAVEFILENB].getRange();
                    int snaga=projeka.Power[SAVEFILENB].getPow();
                    int nemaviseimena;
                    nemaviseimena=projeka.SaveFile[SAVEFILENB]->Napadni(pozicija1,pozicija2,r,xi,yi,snaga);
                    projeka.Charcter[SAVEFILENB].smanjiHP(nemaviseimena);
                    int mocdurdown=projeka.Power[SAVEFILENB].getDurDown();
                    projeka.Weapon[SAVEFILENB].smanjiDurZA(mocdurdown);
                    projeka.Power[SAVEFILENB].IskoristiMoc();
                    break;
                }
        }
        system("cls");
    }while(rad!=0 && hpkara>0 && pom<4);
    brm=brm+pom;
    ofstream fajl;
    fajl.open("Izlaz.txt");
    fajl<<brm;
    fajl.close();
    int j=0;
    for(j=0;j<3;j++)
    {
        upisisve(projeka.Charcter[j],projeka.Weapon[j],projeka.Power[j],j);
    }
}
#endif // FE_IGRICA_HPP_INCLUDED
