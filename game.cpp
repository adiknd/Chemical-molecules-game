
// POP 2016-12-12 projekt 1 Konkel Adrian EIT 3 165170 / Xcode Version 8.1 (8B62)

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct atom{
    char tab[3][3];
    int x;
    int y;
};

void tworzenie_mapa(char** &mapa, int plansza);
void tworzenie_atomy(atom* &atomy, int &il_atomow, char** &czasteczka, int wys_czasteczki, int szer_czasteczki, int plansza);
void wstawianie_atomow(char** &mapa, atom* &atomy, int il_atomow);
void wypisz_mapa(char** &mapa, int wys_mapy, int szer_mapy, char** &czasteczka, int wys_czasteczki, int szer_czasteczki);
void ruch_atomow(char** &mapa, int wys_mapy, int szer_mapy, atom atomy[], int il_atomow, char** &czasteczka, int wys_czasteczki, int szer_czasteczki,int plansza);
void rezewrwuj_pamiec(char** &mapa, int wys_mapy, int szer_mapy, atom* &atomy, int il_atomow, char** &czasteczka, int wys_czasteczki, int szer_czasteczki);
void zwolnij_pamiec(char** &mapa, int wys_mapy, atom* &atomy, char** &czasteczka, int wys_czasteczki);
void wyswietl_pomoc();
void wybierz_plansze(int &wys_mapy, int &szer_mapy, int &il_atomow, int &wys_czasteczki, int &szer_czasteczki, int &plansza);
bool sprawdzenie(char** &mapa, atom* atomy, int plansza);

bool sprawdzenie(char** &mapa, atom* atomy, int plansza)
{
    switch (plansza)                       //////////////////////////////SPRAWDZANIE CZY CZĄSTKA ZOSTAŁA UŁOŻONA
    {
        case 1:
        {
            if ( atomy[5].x==atomy[2].x-3 &&
                atomy[5].y==atomy[2].y+3 &&
            
                atomy[5].x==atomy[1].x-3 &&
                atomy[5].y==atomy[1].y &&
            
                atomy[0].x==atomy[8].x &&
                atomy[0].y==atomy[8].y-3 &&
            
                atomy[8].x==atomy[6].x-3 &&
                atomy[8].y==atomy[6].y-3 &&
            
                atomy[6].x==atomy[3].x+3 &&
                atomy[6].y==atomy[3].y-3 &&
            
                atomy[6].x==atomy[7].x-3 &&
                atomy[6].y==atomy[7].y &&
            
                atomy[7].x==atomy[4].x-3 &&
                atomy[7].y==atomy[4].y-3 &&
            
                atomy[7].x==atomy[5].x-3 &&
                atomy[7].y==atomy[5].y+3 )
            {
                return true;
            }
            
            break;
        }
        case 2:
        {
            if(atomy[0].x==atomy[1].x-3 &&
               atomy[0].y==atomy[1].y &&
               
               atomy[1].x==atomy[2].x &&
               atomy[1].y==atomy[2].y-3 &&
               
               atomy[2].x==atomy[3].x+3 &&
               atomy[2].y==atomy[3].y-3 &&
               
               atomy[2].x==atomy[4].x-3 &&
               atomy[2].y==atomy[4].y &&
               
               atomy[4].x==atomy[5].x &&
               atomy[4].y==atomy[5].y-3)
            {
                return true;
            }
            
            break;
        }
        case 3:
        {
            if(atomy[0].x==atomy[2].x-3 &&
               atomy[0].y==atomy[2].y-3 &&
               
               atomy[2].x==atomy[1].x+3 &&
               atomy[2].y==atomy[1].y-3 &&
               
               atomy[2].x==atomy[3].x-3 &&
               atomy[2].y==atomy[3].y &&
               
               atomy[3].x==atomy[4].x &&
               atomy[3].y==atomy[4].y-3 &&
               
               atomy[3].x==atomy[5].x &&
               atomy[3].y==atomy[5].y+3)
            {
                return true;
            }
            
            break;
        }
    }
    
    return false;
}
                                                            /////////////////////////////////////////////
void tworzenie_mapa(char** &mapa, int plansza)
{
    switch(plansza)
    {
        case 1:
        {
            strcpy(mapa[0], ".............................................");
            strcpy(mapa[1], "......r------------------------------7.r---7.");
            strcpy(mapa[2], "......|                              |.|   |.");
            strcpy(mapa[3], "......|                              |.|   |.");
            strcpy(mapa[4], "......|   r---7   r---7              |.|   |.");
            strcpy(mapa[5], ".r----j   |...|   |...|              |.|   |.");
            strcpy(mapa[6], ".|        |...|   L---j              |.|   |.");
            strcpy(mapa[7], ".|        L---j                      |.|   |.");
            strcpy(mapa[8], ".|                                   |.|   |.");
            strcpy(mapa[9], ".L--j                                |.|   |.");
            strcpy(mapa[10],"....|         r--7                   |.|   |.");
            strcpy(mapa[11],"....|         |..|                   L-j   |.");
            strcpy(mapa[12],"....|         L--j                         |.");
            strcpy(mapa[13],"....|                                      |.");
            strcpy(mapa[14],"....|                                      |.");
            strcpy(mapa[15],"....|                                r-7   |.");
            strcpy(mapa[16],"....|                   r--7         |.|   |.");
            strcpy(mapa[17],"....L--7                |..|         |.|   |.");
            strcpy(mapa[18],".......|                |..|         |.|   |.");
            strcpy(mapa[19],".......|                |..|         |.|   |.");
            strcpy(mapa[20],".......L----------------j..L---7   r-j.|   |.");
            strcpy(mapa[21],"...............................|   |...|   |.");
            strcpy(mapa[22],"...............................|   |...|   |.");
            strcpy(mapa[23],"...............................|   |...|   |.");
            strcpy(mapa[24],"...............................L---j...L---j.");
            strcpy(mapa[25],".............................................");
            
            break;
        }
        
        case 2:
        {
            strcpy(mapa[0], ".................................................");
            strcpy(mapa[1], ".r-----------------------------------------7.....");
            strcpy(mapa[2], ".|                                         |.....");
            strcpy(mapa[3], ".|                                         |.....");
            strcpy(mapa[4], ".|                                         |.....");
            strcpy(mapa[5], ".|   r-------7      r-----7                L---7.");
            strcpy(mapa[6], ".|   |.......|      |.....|     r-7            |.");
            strcpy(mapa[7], ".|   |...r---j      |.....|     |.|            |.");
            strcpy(mapa[8], ".|   |...|          |.....|     |.|            |.");
            strcpy(mapa[9], ".|   L---j          |.....|     |.|            |.");
            strcpy(mapa[10],".|                  L-----j     L-j     r------j.");
            strcpy(mapa[11],".|                                      |........");
            strcpy(mapa[12],".|                                      |........");
            strcpy(mapa[13],".|        r--7                          |........");
            strcpy(mapa[14],".|        |..|                          L------7.");
            strcpy(mapa[15],".|        |..|                                 |.");
            strcpy(mapa[16],".|        L--j                                 |.");
            strcpy(mapa[17],".L--7                                          |.");
            strcpy(mapa[18],"....|                                          |.");
            strcpy(mapa[19],"....|                                          |.");
            strcpy(mapa[20],"....L---------7                                |.");
            strcpy(mapa[21],"..............|                                |.");
            strcpy(mapa[22],"..............|          r------------7        |.");
            strcpy(mapa[23],"..............|          |............|        |.");
            strcpy(mapa[24],"..............L----------j............L--------j.");
            strcpy(mapa[25],".................................................");
            
            break;
        }
            
        case 3:
        {
            strcpy(mapa[0], "...................................................");
            strcpy(mapa[1], ".....r--------------------------------------7......");
            strcpy(mapa[2], ".....|                                      |......");
            strcpy(mapa[3], ".r---j                                      L----7.");
            strcpy(mapa[4], ".|                                               |.");
            strcpy(mapa[5], ".|           r-------------7                     |.");
            strcpy(mapa[6], ".|           |.............|                     |.");
            strcpy(mapa[7], ".|           L-------------j           r---7     |.");
            strcpy(mapa[8], ".|                                     |...|     |.");
            strcpy(mapa[9], ".|                                     |...|     |.");
            strcpy(mapa[10],".|                                     |...|     |.");
            strcpy(mapa[11],".|                 r-----7             |...|     |.");
            strcpy(mapa[12],".|                 |.r---j             |...|     |.");
            strcpy(mapa[13],".|        r--7     |.|                 L---j     |.");
            strcpy(mapa[14],".|        |..|     |.|                           |.");
            strcpy(mapa[15],".|        |..|     |.|                           |.");
            strcpy(mapa[16],".|        L--j     L-j                           |.");
            strcpy(mapa[17],".L--7                                            |.");
            strcpy(mapa[18],"....|                                            |.");
            strcpy(mapa[19],"....|                                            |.");
            strcpy(mapa[20],"....L---7                                        |.");
            strcpy(mapa[21],"....... |                                        |.");
            strcpy(mapa[22],".r------j                       r--7             |.");
            strcpy(mapa[23],".|                              |..|             |.");
            strcpy(mapa[24],".L------------------------------j..L-------------j.");
            strcpy(mapa[25],"...................................................");
            
            break;
        }
    }
}

void tworzenie_atomy(atom* &atomy, int &il_atomow, char** &czasteczka, int wys_czasteczki, int szer_czasteczki, int plansza)
{
    for(int i = 0; i < il_atomow; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                atomy[i].tab[j][k] = ' ';
            }
        }
    }
    
    switch(plansza)
    {
        case 1:                             ////////////////////////////// WYGLĄD POSZCZEGÓLNYCH ATOMÓW W TABLICY 3X3
        {
            atomy[0].tab[1][1]='O'; atomy[0].tab[2][1]='#';
            atomy[1].tab[1][1]='H'; atomy[1].tab[1][0]='-';
            atomy[2].tab[1][1]='H'; atomy[2].tab[2][0]='/';
            atomy[3].tab[1][1]='H'; atomy[3].tab[0][2]='/';
            atomy[4].tab[1][1]='H'; atomy[4].tab[0][0]='\\';
            atomy[5].tab[1][1]='C'; atomy[5].tab[0][2]='/';  atomy[5].tab[1][2]='-'; atomy[5].tab[2][0]='/';
            atomy[6].tab[1][1]='C'; atomy[6].tab[0][0]='\\'; atomy[6].tab[2][0]='/'; atomy[6].tab[1][2]='=';
            atomy[7].tab[1][1]='C'; atomy[7].tab[1][0]='=';  atomy[7].tab[0][2]='/'; atomy[7].tab[2][2]='\\';
            atomy[8].tab[1][1]='C'; atomy[8].tab[0][1]='#';  atomy[8].tab[2][2]='\\';
            
            atomy[0].x=3;                   /////////////////////////////////////// LOKALIZACJA ATOMÓW NA PLANSZY
            atomy[0].y=7;
            
            atomy[1].x=35;
            atomy[1].y=3;
            
            atomy[2].x=35;
            atomy[2].y=17;
            
            atomy[3].x=41;
            atomy[3].y=3;
            
            atomy[4].x=41;
            atomy[4].y=22;
            
            atomy[5].x=10;
            atomy[5].y=18;
            
            atomy[6].x=24;
            atomy[6].y=5;
            
            atomy[7].x=33;
            atomy[7].y=22;
            
            atomy[8].x=41;
            atomy[8].y=7;               ///////////////////////////////////////////////////////////////////////////
            
            strcpy(czasteczka[0], "                " );
            strcpy(czasteczka[1], " O0          H2 " );
            strcpy(czasteczka[2], " #          /   " );
            strcpy(czasteczka[3], " #         /    " );
            strcpy(czasteczka[4], " C8      5C--H1 " );
            strcpy(czasteczka[5], "  \\      /      ");
            strcpy(czasteczka[6], "   \\    /       ");
            strcpy(czasteczka[7], "   6C==C7       " );
            strcpy(czasteczka[8], "   /    \\       ");
            strcpy(czasteczka[9], "  /      \\      ");
            strcpy(czasteczka[10]," H3       H4    " );
            strcpy(czasteczka[11],"                " );
                                                                //atomy[7].x=atomy[4].x-3;
            break;                                              //atomy[7].y=atomy[4].y-3;
        }
            
                                                                //atomy[7].x=atomy[5].x-3;
        case 2:                                                 //atomy[7].y=atomy[5].y+3;
        {
            atomy[0].tab[1][1]='C'; atomy[0].tab[1][2]='=';
            atomy[1].tab[1][1]='H'; atomy[1].tab[2][1]='|'; atomy[1].tab[1][0]='=';
            atomy[2].tab[1][1]='C'; atomy[2].tab[1][2]='-'; atomy[2].tab[0][1]='|'; atomy[2].tab[2][0]='/';
            atomy[3].tab[1][1]='O'; atomy[3].tab[0][2]='/';
            atomy[4].tab[1][1]='O'; atomy[4].tab[1][0]='-'; atomy[4].tab[2][1]='#';
            atomy[5].tab[1][1]='H'; atomy[5].tab[0][1]='#';
          
            
            atomy[0].x=8;
            atomy[0].y=3;
            
            atomy[1].x=23;
            atomy[1].y=3;
            
            atomy[2].x=25;
            atomy[2].y=15;
            
            atomy[3].x=18;
            atomy[3].y=22;
            
            atomy[4].x=46;
            atomy[4].y=7;
            
            atomy[5].x=45;
            atomy[5].y=16;
            
            
            strcpy(czasteczka[0], "            " );
            strcpy(czasteczka[1], " C0==H1     " );
            strcpy(czasteczka[2], "     |      " );
            strcpy(czasteczka[3], "     |      " );
            strcpy(czasteczka[4], "     C2--O4 " );
            strcpy(czasteczka[5], "    /    #  " );
            strcpy(czasteczka[6], "   /     #  " );
            strcpy(czasteczka[7], "  O3     H5 " );
            strcpy(czasteczka[8], "            " );
            
            
            break;
        }
            
            
        case 3:
        {
            atomy[0].tab[1][1]='H'; atomy[0].tab[2][2]='\\';
            atomy[1].tab[1][1]='H'; atomy[1].tab[0][2]='/';
            atomy[2].tab[1][1]='C'; atomy[2].tab[0][0]='\\'; atomy[2].tab[2][0]='/'; atomy[2].tab[1][2]='=';
            atomy[3].tab[1][1]='O'; atomy[3].tab[1][0]='='; atomy[3].tab[0][1]='|'; atomy[3].tab[2][1]='|';
            atomy[4].tab[1][1]='H'; atomy[4].tab[0][1]='|';
            atomy[5].tab[1][1]='C'; atomy[5].tab[2][1]='|';
            
            
            atomy[0].x=10;
            atomy[0].y=3;
            
            atomy[1].x=4;
            atomy[1].y=15;
            
            atomy[2].x=17;
            atomy[2].y=14;
            
            atomy[3].x=35;
            atomy[3].y=12;
            
            atomy[4].x=40;
            atomy[4].y=22;
            
            atomy[5].x=40;
            atomy[5].y=5;
            
            
            strcpy(czasteczka[0], "           " );
            strcpy(czasteczka[1], " H0     C5 " );
            strcpy(czasteczka[2], "  \\     |   " );
            strcpy(czasteczka[3], "   \\    |   " );
            strcpy(czasteczka[4], "    C2==O3 " );
            strcpy(czasteczka[5], "   /    |  " );
            strcpy(czasteczka[6], "  /     |  " );
            strcpy(czasteczka[7], " H1     H4 " );
            strcpy(czasteczka[8], "           " );
            
            break;
        }


    }
}

void wstawianie_atomow(char** &mapa, atom* &atomy, int il_atomow)
{
    int y;
    int x;
    for(int i = 0; i < il_atomow; i++)
    {
        y = atomy[i].y;
        x = atomy[i].x;
        
        for(int w = -1; w <= 1; w++)                            ///// WSTAWIANIE ATOMÓW NA PLANSZE
        {
            for(int k = -1; k <= 1; k++)
            {
                if(mapa[y+w][x+k] == ' ')
                    mapa[y+w][x+k] = atomy[i].tab[w+1][k+1];
            }
        }
    }                                                       /////////////////////////////////////////////
}

void wypisz_mapa(char** &mapa, int wys_mapy, int szer_mapy, char** &czasteczka, int wys_czasteczki, int szer_czasteczki)
{
    for(int i=0; i <wys_mapy; i++)
    {
        for (int j=0; j<szer_czasteczki-1; j++) /////////////// WYSWIETLANIE CZASTECZKI PO LEWEJ STRONIE MAPY
        {
            if(i < wys_czasteczki)
                cout << czasteczka[i][j];
            else
                cout << " ";
        }
        
        for (int j=0; j<szer_mapy; j++)     //////////////////////////////WYSWIETLANIE MAPY
        {
            cout << mapa[i][j];
        }
        cout<<endl;
    }                                       ////////////////////////////////////////////////
}


void ruch_atomow(char** &mapa, int wys_mapy, int szer_mapy, atom atomy[], int il_atomow, char** &czasteczka, int wys_czasteczki, int szer_czasteczki, int plansza)
{
    bool koniec = true;
    cout<<"Podaj ruch: ";
    char akcja;
    int czymruszyc = 0;
    bool zlyruch = false;
    bool wyboratomu = false;
    cin>>akcja;
    
    while(koniec)
    {
        zlyruch = false;
        wyboratomu = false;
        
        switch(akcja)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                czymruszyc = (int)(akcja-'0');
                if(czymruszyc < il_atomow)
                {
                    wyboratomu = true;
                }
                else
                {
                    cout << "Bledny nr atomu: " << czymruszyc << endl;
                    czymruszyc = -1;
                }
                
                break;
            }
            case 'w':
            {
                if(czymruszyc == -1)
                {
                    cout << "Podaj prawidlowy nr atomu: " << endl;
                    break;
                }
                    
                if(mapa[atomy[czymruszyc].y-2][atomy[czymruszyc].x-1] == ' ' && mapa[atomy[czymruszyc].y-2][atomy[czymruszyc].x] == ' ' && mapa[atomy[czymruszyc].y-2][atomy[czymruszyc].x+1] == ' ')
                {
                    atomy[czymruszyc].y--;
                    if(sprawdzenie(mapa, atomy, plansza))
                    {
                        break;
                    }
                }
                else
                    zlyruch = true;
                break;
            }
            case 's':
            {
                if(czymruszyc == -1)
                {
                    cout << "Podaj prawidlowy nr atomu: " << endl;
                    break;
                }
                
                if(mapa[atomy[czymruszyc].y+2][atomy[czymruszyc].x-1] == ' ' && mapa[atomy[czymruszyc].y+2][atomy[czymruszyc].x] == ' ' && mapa[atomy[czymruszyc].y+2][atomy[czymruszyc].x+1] == ' ')
                {
                    atomy[czymruszyc].y++;
                    if(sprawdzenie(mapa, atomy, plansza))
                    {
                        koniec = false;
                    }
                }
                else
                    zlyruch = true;
                break;
            }
            case 'd':
            {
                if(czymruszyc == -1)
                {
                    cout << "Podaj prawidlowy nr atomu: " << endl;
                    break;
                }
                
                if(mapa[atomy[czymruszyc].y-1][atomy[czymruszyc].x+2] == ' ' && mapa[atomy[czymruszyc].y][atomy[czymruszyc].x+2] == ' ' && mapa[atomy[czymruszyc].y+1][atomy[czymruszyc].x+2] == ' ')
                {
                    atomy[czymruszyc].x++;
                    if(sprawdzenie(mapa, atomy, plansza))
                    {
                        koniec = false;
                    }
                }
                else
                    zlyruch = true;
                break;
            }
            case 'a':
            {
                if(czymruszyc == -1)
                {
                    cout << "Podaj prawidlowy nr atomu: " << endl;
                    break;
                }
                
                if(mapa[atomy[czymruszyc].y-1][atomy[czymruszyc].x-2] == ' ' && mapa[atomy[czymruszyc].y][atomy[czymruszyc].x-2] == ' ' && mapa[atomy[czymruszyc].y+1][atomy[czymruszyc].x-2] == ' ')
                {
                    atomy[czymruszyc].x--;
                    if(sprawdzenie(mapa, atomy, plansza))
                    {
                        koniec = false;
                    }
                }
                else
                    zlyruch = true;
                break;
            }
            case 'K':
            {
                exit(0);
                break;
            }
            case '?':
            {
                wyswietl_pomoc();
                break;
            }
            default:
            {
                cout << "zly kawisz: " << akcja << endl;
                break;
            }
        }
        
        if(!wyboratomu)
        {
            if(zlyruch)
            {
                cout << "Ruch niemozliwy!" << endl;
            }
            else
            {
                tworzenie_mapa(mapa, plansza);
                wstawianie_atomow(mapa, atomy, il_atomow);
                wypisz_mapa(mapa, wys_mapy, szer_mapy, czasteczka, wys_czasteczki, szer_czasteczki);
            }
        }
        
        if(!koniec)
        {
            cout << "WYGRANA" << endl;
            break;
        }
        
        cin>>akcja;
    }
}

void rezewrwuj_pamiec(char** &mapa, int wys_mapy, int szer_mapy, atom* &atomy, int il_atomow, char** &czasteczka, int wys_czasteczki, int szer_czasteczki)
{
    mapa = new char* [wys_mapy];
    for(int i = 0; i < wys_mapy; i++)
        mapa[i] = new char [szer_mapy];
    
    atomy = new atom [il_atomow];
    
    czasteczka = new char* [wys_czasteczki];
    for(int i = 0; i < wys_czasteczki; i++)
        czasteczka[i] = new char [szer_czasteczki];
}

void zwolnij_pamiec(char** &mapa, int wys_mapy, atom* &atomy, char** &czasteczka, int wys_czasteczki)
{
    delete [] atomy;
    atomy = NULL;
    
    for(int i = 0; i < wys_czasteczki; i++)
    {
        delete [] czasteczka[i];
        czasteczka[i] = NULL;
    }
    delete [] czasteczka;
    czasteczka = NULL;
    
    for(int i = 0; i < wys_mapy; i++)
    {
        delete [] mapa[i];
        mapa[i] = NULL;
    }
    delete [] mapa;
    mapa = NULL;
}

void wyswietl_pomoc()
{
    cout << "POMOC:" << endl;
    cout << "Gra polega na prawidłowym ułożenia cząsteczki według wzoru po lewej stronie." << endl;
    cout << "Każdy atom ma przypisany indywidualny numer." << endl;
    cout << "Aby poruszyć atomem należy wpisać jego numer a następnie w/a/s/d w zależności od potrzeby." << endl;
    cout << "(W) - ruch w górę." << endl;
    cout << "(A) - ruch w lewo." << endl;
    cout << "(S) - ruch w dół." << endl;
    cout << "(D) - ruch w prawo." << endl;
    cout << "Akcje można łączyć, np. 1dd3ssss4ww." << endl;
}

void wybierz_plansze(int &wys_mapy, int &szer_mapy, int &il_atomow, int &wys_czasteczki, int &szer_czasteczki, int &plansza)
{
    cout << "Wybierz (?) aby wyświetlić pomoc. "<<endl;
    cout << "Wybierz (K) aby zakończyć grę."<<endl;
    cout << "WYBIERZ PLANSZE: (1-3) ";
    char wybor;
    cin >> wybor;
    
    switch(wybor)
    {
        case '1':
        {
            plansza = 1;
            wys_mapy = 26;
            szer_mapy = 46;
            il_atomow = 9;
            wys_czasteczki = 12;
            szer_czasteczki = 17;
            break;
        }
            
        case '2':
        {
            plansza = 2;
            wys_mapy = 26;
            szer_mapy = 50;
            il_atomow = 6;
            wys_czasteczki = 9;
            szer_czasteczki = 13;
            break;
        }
            
        case '3':
        {
            plansza = 3;
            wys_mapy = 26;
            szer_mapy = 52;
            il_atomow = 6;
            wys_czasteczki = 9;
            szer_czasteczki = 12;
            break;
        }
            
        case 'K':
        {
            exit(0);
            break;
        }
        case '?':
        {
            wyswietl_pomoc();
            wybierz_plansze(wys_mapy, szer_mapy, il_atomow, wys_czasteczki, szer_czasteczki, plansza);
            break;
        }
        default:
        {
            cout << "Zly klawisz" << endl;
            wybierz_plansze(wys_mapy, szer_mapy, il_atomow, wys_czasteczki, szer_czasteczki, plansza);
            break;
        }
    }
}

int main()
{
    int plansza = 0;
    int wys_mapy = 0;
    int szer_mapy = 0;
    int il_atomow = 0;
    int wys_czasteczki = 0;
    int szer_czasteczki = 0;
    
    char** mapa;
    atom* atomy;
    char** czasteczka;
    
    wybierz_plansze(wys_mapy, szer_mapy, il_atomow, wys_czasteczki, szer_czasteczki, plansza);
    
    rezewrwuj_pamiec(mapa, wys_mapy, szer_mapy, atomy, il_atomow, czasteczka, wys_czasteczki, szer_czasteczki);
    tworzenie_mapa(mapa, plansza);
    tworzenie_atomy(atomy, il_atomow, czasteczka, wys_czasteczki, szer_czasteczki, plansza);
    
    wstawianie_atomow(mapa, atomy, il_atomow);
    wypisz_mapa(mapa, wys_mapy, szer_mapy, czasteczka, wys_czasteczki, szer_czasteczki);
    ruch_atomow(mapa, wys_mapy, szer_mapy, atomy, il_atomow, czasteczka, wys_czasteczki, szer_czasteczki, plansza);
    
    zwolnij_pamiec(mapa, wys_mapy, atomy, czasteczka, wys_czasteczki);
    
    return 0;
    }
