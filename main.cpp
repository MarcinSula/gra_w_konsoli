#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>

using namespace std;
string PL( const char * text ) //Polskie znaki
{
 string result;
 for(; * text; text++ )
 switch( * text )
 {
 case '�': result += static_cast < char >( 0xa5 ); break;
 case '�': result += static_cast < char >( 0x86 ); break;
 case '�': result += static_cast < char >( 0xa9 ); break;
 case '�': result += static_cast < char >( 0x88 ); break;
 case '�': result += static_cast < char >( 0xe4 ); break;
 case '�': result += static_cast < char >( 0xa2 ); break;
 case '�': result += static_cast < char >( 0x98 ); break;
 case '�': result += static_cast < char >( 0xbe ); break;
 case '�': result += static_cast < char >( 0xab ); break;
 case '�': result += static_cast < char >( 0xa4 ); break;
 case '�': result += static_cast < char >( 0x8f ); break;
 case '�': result += static_cast < char >( 0xa8 ); break;
 case '�': result += static_cast < char >( 0x9d ); break;
 case '�': result += static_cast < char >( 0xe3 ); break;
 case '�': result += static_cast < char >( 0xe0 ); break;
 case '�': result += static_cast < char >( 0x97 ); break;
 case '�': result += static_cast < char >( 0xbd ); break;
 case '�': result += static_cast < char >( 0x8d ); break;
 default: result += * text; break;
 }
 return result;
}
void cl()
{
    getch();
    system("cls");
}

string nick;

int hp=30, str=20, lvl=1, exp=0, dex=20;//G��wny
int dm, hp_goblin1=5,hps=50,dms,dmg,hps1=40,sila=30;//Przeciwnicy
int hpn=30, fn=40, strn=30; //Wilk
int wybor[20],d=0,d1=0, historia=0,d2=0;//Historia
int ahp=100, af=50, asl=50,dma=10;//Alucard

int main()
{
    system("color 07");
    HANDLE hOut;
 hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    cout << PL ("Witaj! Aby zacz�� gr� podaj nazw� gracza:  "); cin>>nick;

    fstream plik; //�adowanie danych gracza do pliku
    plik.open("Dane.txt", ios::out);
    plik<<nick<<endl;
    system("cls");

    cout<<PL("Par� informacji na start:")<<endl; //Startowe informacje

    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );

    cout<<PL("Takim kolorem b�d� oznaczone wypowiedzi podczas kt�rych musisz dokona� wyboru.")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

    cout<<PL("Takim kolorem b�d� oznaczone twoje wypowiedzi.")<<endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    cout<<PL("Takim kolorem oznaczony jest skok czasu akcji.")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<PL("W zdaniach oznaczonych *...* zawarty jest opis akcji/czynno�ci.")<<endl;



    cout<<PL("A wi�c nazywasz si� ")<<nick<<PL("?Mi�o ci� pozna�! B�de twoim przewodnikiem podczas kr�tkiego wst�pu.")<<endl;
    cout<<PL("Skoro ju� si� znamy czas na wybranie klasy twojej postaci. Masz do wyboru: ")<<endl;
    klasa:
    cout<<PL("1.�ucznik")<<endl;
    cout<<"2.Rycerz"<<endl;
    cout<<"3.Zielarz"<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<PL("Kt�r� klas� wybierasz?")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cin>>wybor[0];
        switch( wybor[0] ) //Wyb�r klasy
        {
        case 1:
                cout << PL("A wi�c jeste� �ucznikiem! Twoje obecne statystki: ")<<endl;
        break;
        case 2:
                cout <<PL("A wi�c jeste� rycerzem! Twoje obecne statystki: ")<<endl;
        break;
        case 3:
                cout <<PL("A wi�c jeste� zielarzem! Twoje obecne statystki: ")<<endl;
        break;
        default:
                cout<<PL("Nie ma wi�cej dost�pnych postaci. Wybierz jeszcze raz.")<<endl;
                Sleep(1500);
                system("cls");
                goto klasa;
        break;
        }

    cout<<PL("Poziom: ")<<lvl<<endl; //Pocz�tkowe statystyki
    cout<<PL("�ycie: ")<<hp<<endl;
    cout<<PL("Si�a: ")<<str<<endl;
    cout<<PL("Zr�czno��: ")<<dex<<endl;


    if (wybor[0]==1)
    {
        cout<<PL("Twoimi przedmiotami startowymi s� �uk i strza�y.")<<endl;
    }
    else if(wybor[0]==2)
    {
            cout<<PL("Twoimi przedmiotami startowymi s� miecz i tarcza.")<<endl;
    }
    else if (wybor[0]==3)
    {
            cout<<PL("Twoimi przedmiotami startowymi s� zio�a lecznicze i wype�niona zielonym p�ynem fiolka.")<<endl;
    }


    cout<<PL("Skoro jeste� juz wyposa�ony i znasz swoje statystki oraz podstawy,")<<endl;
    cout<<PL("mo�e czas na walk� pr�bna zanim zacznie si� twoja przygoda?")<<endl;

    cl();

    cout<<PL("*Nagle przed ")<<nick<<PL(" pojawia si� goblin.*")<<endl; //Pierwszy przeciwnik,system obra�e�
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );//Kolor tekstu,obrazek ascii //DO POPRAWY
    cout<<R"(             ,      ,
            /(.-""-.)\
        |\  \/      \/  /|
        | \ / =.  .= \ / |
        \( \   o\/o   / )/
         \_, '-/  \-' ,_/
           /   \__/   \
           \ \__/\__/ /
         ___"\ \|--|/ /___
       /`    \      /    `\
      /       '----'       \

    )"<<endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    srand(time(NULL));
    dm=rand()%5;
    cout<<PL("A�a!")<<nick<<PL(" zosta� uderzony przez przeciwnika.")<<endl;
    hp=hp-dm;
    cout<<"HP="<<hp<<endl;


        if (wybor[0]==1)
        {
        cout<<PL("*Wkurzony wyci�gasz �uk i strzelasz do potwora.*")<<endl;
        }
        else if(wybor[0]==2)
        {
            cout<<PL("*Wkurzony wyci�gasz miecz i atakujesz potwora.*")<<endl;
        }
        else if (wybor[0]==3)
        {
            cout<<PL("*Wkurzony wyci�gasz dziwn� fiolk� i rzucasz ni� w potwora.*")<<endl;
        };
        hp_goblin1=hp_goblin1-5;
        if (hp_goblin1==0)
        {
            cout<<PL("Tw�j atak by� skuteczny, pozby�e� sie wroga!EXP+75")<<endl;
        }
    exp=exp+75;


    cout<<PL("�wietnie, pokona�e� pierwszego goblina. Mo�esz w takim razie zacz�� prawdziw� rozgrywk�.")<<endl;
    cout<<PL("Od teraz b�dzie tylko trudniej, powodzenia!")<<endl;
    cout<<PL("*Nagle wszytko staje si� ciemne, kiedy otwierasz oczy znajdujesz sie na ogromnym zat�oczonym rynku.*")<<endl;


    lokacje:
        cout<<endl;
    cout<<PL("1.Ulice miasta(od lvl'u 1)")<<endl;//Wyb�r lokacji,label
    cout<<PL("2.Las za miastem(od lvl'u 2)")<<endl;
    cout<<PL("3.Opuszczona kopalnia(od lvl'u 3)")<<endl;
    cout<<PL("4.Kaplica(od lvl'u 4)")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<PL("Gdzie teraz chcesz si� uda�?")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cin>>wybor[1];

        if (wybor[1]>4)
        {
            cout<<PL("Nie ma wi�cej dost�pnych lokacji. Wybierz jeszcze raz: ")<<endl;
            Sleep(1500);
            system("cls");
            goto lokacje;
        }
        else if ( wybor[1]<=4);
        {
            goto test;
        }

    test:
        switch ( wybor[1])
    {
        case 1://Alejka
            if ((lvl>=1)&&(historia==0))
             {
                 system("cls");
            cout<<PL("*Przeszed�e� na drug� stron� rynku, w mi�dzy czasie obserwuj�c ludzi kr�c�cych si� wok�. Przechadzaj�c sie bez celu")<<endl;
            cout<<PL(" ulicami zagapi�e� sie i wpad�e� na kogo�.*")<<endl;
            rozmowa0:
            cout<<PL("1.UGH UWA�AJ JAK �AZISZ!")<<endl;
            cout<<PL("2.Najmocniej przepraszam zagapi�em si�...")<<endl;
            cout<<PL("3.*Nic nie m�wisz.*")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Co wybierasz?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cin>>wybor[2];
                switch (wybor[2])
                {
                case 1:
                    cout<<PL("Nieznajoma - Sam patrz na drog� palancie. *Kobieta na kt�r� wpad�e� spogl�da na Ciebie zdenerwowanym spojrzeniem.*")<<endl;
                break;
                case 2:
                    cout<<PL("Nieznajoma - Nie to ja Pana przepraszam zamy�li�am si�...*Kobieta na kt�r� wpad�e� spogl�da na Ciebie �agodnym spojrzeniem.*")<<endl;
                break;
                case 3:
                    cout<<PL("Nieznajoma - J�zyka w g�bie nie masz? Wypada przeprosi� kiedy wpadasz na kogo�. *Kobieta na kt�r� wpad�e� spogl�da")<<endl;
                    cout<<PL("na ciebie oboj�tnym wzrokiem.*")<<endl;
                break;
                default:
                    cout<<PL("Nie ma wi�cej opcji dialogowych. Wybierz jeszcze raz.")<<endl;

                    goto rozmowa0;
                break;
                }
SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
            cout<< R"(
                /((   ))
               ( )6  6( )
               (_)  l (_)
                 \ <> )
              ____) (_____
             (   \____/   )
             ) (   )(   ) (
            / / \      / \ \
           / /   \    /   \ \
           \ \    )==(    / /
            \ \  /    \  / /
             '\\/      \//'
              '|\`    '|\`
                \      /
                 \    /
                 )    (
       	        /      \
               /        \
              /          \
             /            \
            /              \
           /                \
           `-....,      ,..-'
                  `-..-'
                  )"<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

            cout<<PL("*Jej wzrok pada na Twoje ramie* Ah wi�c to ty jeste� tym nowym ")<<"";
            if (wybor[0]==1)
            {
                cout<<PL("�ucznikiem. *Kierujesz swoje spojrzenie na rami� i widzisz znami� w kszta�cie �uku.*")<<endl;
            }
            else if(wybor[0]==2)
            {
                cout<<PL("rycerzem. *Kierujesz swoje spojrzenie na rami� i widzisz znami� w kszta�cie miecza.*")<<endl;
            }
            else if (wybor[0]==3)
            {
                cout<<PL("zielarzem. *Kierujesz swoje spojrzenie na rami� i widzisz znami� w kszta�cie kwiatu.*")<<endl;
            }

            cout<<PL("Nieznajoma - Mimo wszystko dobrze �e cie spotka�am. Przyda mi si� twoja pomoc...")<<endl;
            rozmowa2:
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Czy chcesz pom�c nieznajomej?1.Tak 2.Nie")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cin>>wybor[3];
            if (wybor[3]==1)
            {
                system("cls");
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
                cout<<PL("Dobrze wys�ucham ci�.")<<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            }
            else if (wybor[3]==2)
            {
                system("cls");
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
                cout<<PL("Nie mam zamiaru ci pom�c.")<<"";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                cout<<PL("*Chcesz odej�� ale nieznajoma �apie ci� za r�k�.*")<<endl;
                cout<<PL("Nieznajoma - B�agam hojnie ci� wynagrodz� obiecuj�...")<<endl;
            }
            else if (wybor[3]>2)
            {
                cout<<PL("Mo�esz wybra� tylko tak lub nie.")<<endl;
                Sleep(1000);
                system("cls");
                goto rozmowa2;
            }
                cout<<PL("Mam problem z chochlikami w moim domu...Posiadasz znami�, powiniene� sobie z nimi poradzi�.")<<endl;
                cout<<PL("Obiecuj� jak tylko si� ich pozb�dziesz dostaniesz naprawd� przydatn� rzecz.")<<endl;


                rozmowa1:
                cout<<PL("1.Kim tak w�a�ciwie jeste�?")<<endl;
                cout<<PL("2.Opowiedz mi wi�cej o tych chochlikach.")<<endl;
                cout<<PL("3.Wi�c ruszajmy do twojego domu.")<<endl;
                cout<<PL("4.*Nic nie m�wisz*")<<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
                cout<<PL("Wybierz opcj� dialogow�: ");
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                cin>>wybor[4];
                    switch (wybor[4])
                    {
                    case 1:
                        cout<<PL("Anna - Nazywam si� Anna, jestem nauczycielka w pobliskiej szkole.")<<endl;
                        Sleep(2500);
                        system("cls");
                        goto rozmowa1;
                    break;
                    case 2:
                        cout<<PL("Anna - To lubi�ce psoty istoty, zazwyczaj nie robi� A� takich szk�d jak teraz i nie zbli�aj� si� do ludzi.")<<endl;
                        Sleep(2000);
                        cout<<PL("Ale odk�d w kaplicy zacz�y dzia� si� dziwne rzeczy...wszystkie stwory powariowa�y i si� zmieni�y.")<<endl;
                        Sleep(2500);
                        system("cls");
                        goto rozmowa1;
                    break;
                    case 3:
                        cout<<PL("Anna - A wi�c chod� za mn�. To niedaleko st�d.")<<endl;
                        system("cls");
                    break;
                    case 4:
                        cout<<PL("Anna - Ma�om�wny jeste�...Chod� wi�c po prostu za mn�.")<<endl;
                        system("cls");
                    break;
                    default:
                        cout<<PL("Nie ma wi�cej opcji dialogowych. Wybierz jeszcze raz.")<<endl;
                        Sleep(1000);
                        system("cls");
                        goto rozmowa1;
                        break;
                    }
               cout<<PL("*Ruszasz za kobiet�, po kilku minutach drogi w�skimi i kr�tymi alejkami stajesz przed star� kamienic�.*")<<endl;
               cout<<PL("Anna - To tutaj...Musisz wej�� sam ja mam ju� tego serdecznie do��.")<<endl;
               cout<<PL("*Spogl�dasz podejrzanie na kobiet�.* Po prostu si� boj� ok?Eh id� to za�atw.")<<endl;
               cout<<PL("Ale zanim tam wejdziesz, zdradzisz mi Twoje imi�...?")<<endl;
               SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
               cout<<nick<<endl;
               SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
               cout<<PL("*Nie czekaj�c d�u�ej wchodzisz do kamiennicy, wsz�dzie widzisz rozwalone �ciany oraz pe�no zniszczonych przedmiot�w.")<<endl;
               cout<<PL("W trakcie przechadzki po domu nagle zauwa�asz ruch w k�cie.*")<<endl;
               cl();
               cout<<R"(
        ,
        |\     ____
        | \.-./ .-'
         \ _  _(
         | .)(./
         |   \(
         |     \   |
         |  \vvv   |
         |  |__    |
        /      `-. |
                       )"<<endl;
            cout<<PL("By� to dziwnie wygl�daj�cy ma�y stworek, kt�ry zaraz po zorientowaniu si� �e zosta� odkryty wyda� przera�liwy pisk i w kilka ")<<endl;
            cout<<PL("sekund nie by� ju� on sam. Otoczy�o cie ogrom takich stworze�.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("B�dzie ci�ej ni� s�dzi�em...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            opcje0:
            if (wybor[0]==1)
            {
                cout<<PL("1.Wyci�gasz sw�j �uk i celujesz do chochlika kt�rego zauwa�y�e� pierwszego.")<<endl;
            }
            else if(wybor[0]==2)
            {
                cout<<PL("1.Wyci�gasz miecz oraz tarcz� przyjmuj�c poz� do obrony.")<<endl;
            }
            else if (wybor[0]==3)
            {
                cout<<PL("1.Wyjmujesz kolejn� dziwn� buteleczk� i kierujesz z powrotem wzrok do chochlika kt�rego zauwa�y�e� pierwszego.")<<endl;
            }
            cout<<PL("2.Wycofujesz si� powoli do wyj�cia.")<<endl;
            cout<<PL("3.Kopiesz najbli�szego chochlika.")<<endl;
            cout<<PL("4.Mo�e si� jako� dogadamy...?*Nie ruszasz si�.*")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Co robisz?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cin>>wybor[5];
            system("cls");
            switch (wybor[5])
            {
                case 1:
                    cout<<PL("Wszystkie chochliki rzucaj� si� na Ciebie zadaj�c niewielkie obra�enia, starasz si� broni� i atakowa� stworki ale te s� zbyt")<<endl;//Sleep(2000);
                    cout<<PL("szybkie i wi�kszo�ci cios�w unikaj�.")<<endl;
            break;
                case 2:
                    cout<<PL("Chochliki szybko zagrodzi�y ci drzwi uniemo�liwiaj�c ucieczk�.")<<endl;

            break;
                case 3:
                    cout<<PL("Rozw�cieczy�o to tylko pozosta�e, kt�re rzuci�y sie na ciebie atakuj�c.")<<endl;

            break;
            case 4:
                    cout<<PL("Chochliki obserwuj� ci� nie wykonuj�c �adnego ruchu.")<<endl;

            break;
                default:
                    cout<<PL("Nie ma wi�cej opcji, wybierz jeszcze raz.")<<endl;
                    Sleep(1000);
                    system("cls");
                    goto opcje0;
            break;
            }

            if ((wybor[5]==1)||(wybor[5]==3))
            {
                srand(time(NULL));
                dm=rand()%5;
                hp=hp-dm;
                cout<<"HP= "<<hp<<endl;
                cout<<PL("Odpychasz je od siebie i uciekasz na pi�tro po drodze likwiduj�c kilka szkodnik�w przy u�yciu broni, padaj� po jednym ciosie.")<<endl;
                exp=exp+100;
                cout<<PL("Zauwa�asz star� komod� stoj�ca idealnie na rogu schod�w, zrzucasz j� na wszystkie stwory kt�re sta�y na schodach.")<<endl;
                cout<<PL("Oficjalnie pozby�e� sie wszystkich pozosta�ych jednym trafieniem! EXP+100")<<endl;
                cout<<PL("Wracasz na do� i wychodzisz na ulic� gdzie czeka Anna zaniepokojona wcze�niejszymi odg�osami walki.")<<endl;
                cout<<PL("Widz�c �e jeste� ca�y oddycha z ulg�.")<<endl;
                cout<<PL("*Sama wchodzi do kamiennicy a po chwili wraca.* ")<<endl;
                cout<<PL("Anna - A wi�c naprawd� uda�o ci sie ich pozby�...nie wiem jak ci dzi�kowa�,obieca�am ci zap�at� oto ona.")<<endl;
                cout<<PL("Kobieta podaje ci ma�a skrzynk� w kt�rej znajdujesz naszyjnik, zak�adasz go. *Wszystkie statystyki podnosz� si� o 10 punkt�w.")<<endl;
                hp=hp+10;
                cout<<"HP="<<hp<<endl;
                str=str+10;
                cout<<PL("Si�a=")<<str<<endl;
                dex=dex+10;
                cout<<PL("Zr�czno�c=")<<dex<<endl;
                if (exp==150);
                {
                    lvl++;

                    cout<<PL("Gratulacje uzyska�e� kolejny level!Poziom: ")<<lvl<<endl;
                    exp=0;
                    cl();
                    cout<<PL("Chcesz odej��, ale odwracaj�c si� wpadasz na kogo�.")<<endl;
                    cout<<PL("Nieznajomy - Oh najmocniej przepraszam, widz� �e uporali�cie si� ju� z problemem, wi�c py� nie b�dzie potrzebny.")<<endl;
                    cout<<PL("*Nieznajomy chowa jak�� sakiewk� do kieszeni.*")<<endl;
                    cout<<PL("Anna - ")<<nick<<PL(" poznaj burmistrza naszego miasta.")<<endl;
                    cout<<PL("*Nieznajomy spogl�da na twoje rami�.* Ah teraz rozumiem jeste� kolejnym pseudo wybra�cem. Zapowiadasz si� obiecuj�co,")<<endl;
                    cout<<PL("a� jestem ciekaw jak ci p�jdzie z Alucardem. Cho� po twojej minie widz� �e nikt nic ci nie wyt�umaczy�.")<<endl;
                }
            }
            else if ((wybor[5]==2)||(wybor[5]==4))
            {
                cout<<PL("Do mieszkania wchodzi Anna wraz z jakim� m�czyzn�, widz�c twoj� beznadziejn� sytuacj� nowa posta� rusza w twoim kierunku.")<<endl;
                cout<<PL("Kiedy chochliki chc� si� do niego zbli�y� zostaj� posypane jakim� py�em przez kt�ry padaj� nieprzytomne na ziemi�. Pozosta�e na ten widok szybko si� ulotni�y.")<<endl;
                cout<<PL("Anna - jednak si� co do Ciebie przeliczy�am...")<<endl;
                cout<<PL("Nieznajomy m�czyzna - A m�wi�em aby� poczeka�a, teraz nie powinny wr�ci�.")<<endl;
                cout<<PL("*Rozsypa� owy py� po ca�ym pomieszczeniu. A nast�pnie spogl�da na twoje rami�.*")<<endl;
                cout<<PL("Ah teraz rozumiem jeste� kolejnym pseudo wybra�cem. Pfi nawet chochliki ci� pokona�y,")<<endl;
                cout<<PL("a� strach pomy�le� co zrobi z tob� Alucard. Jestem burmistrzem, a po twojej minie widz� �e nikt nic ci nie wyt�umaczy�.")<<endl;
            }
            rozmowa3:
                cout<<PL("1.Co to by� za py�?")<<endl;
                cout<<PL("2.O co ci chodzi z tym pseudo wybra�cem?")<<endl;
                cout<<PL("3.Kim jest ten Alucard?")<<endl;
                if ((wybor[5]==2)||(wybor[5]>=4))
                {
                    cout<<PL("4.Co z tym wynagrodzeniem?")<<endl;
                }
                else if ((wybor[5]==1)||(wybor[5]==3))
                {
                    cout<<PL("4.Co to za naszyjnik?")<<endl;
                }
                cout<<PL("5.Nie mam wi�cej pyta�.")<<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
                cout<<PL("Masz do mnie jakie� pytania?")<<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                cin>>wybor[7];
                switch (wybor[7])
                {
                case 1:
                    cout<<PL("Burmistrz - Py� z kwiat�w maku zebranych podczas pe�ni, te ma�e mendy nienawidz� tych kwait�w. Najlepsza forma na ich odstraszenie.")<<endl;
                    Sleep(3000);
                        system("cls");
                    goto rozmowa3;
                break;
                case 2:
                    cout<<PL("Burmistrz - Stara legenda m�wi o przybyciu wybra�ca z znamieniem na ramieniu, kt�ry ma nam pom�c uwolni� si� od Alucarda.")<<endl;
                    Sleep(1000);
                    cout<<PL("Wielu ju� si� takich pojawi�o, wszystkich mo�esz znale�� na cmentarzu obok kaplicy.")<<endl;
                    Sleep(3000);
                        system("cls");
                    goto rozmowa3;
                break;
                case 3:
                    cout<<PL("Burmistrz - Wampir przebywaj�cy w kaplicy, wybudzi� si� z stu letniego odpoczynku i terroryzuje miasto.")<<endl;
                    Sleep(1000);
                    cout<<PL("Wed�ug starej legendy ma przyby� wybraniec z znamieniem na ramieniu i z powrotem wys�a� go na kolejn� drzemk�.")<<endl;
                    Sleep(1000);
                    cout<<PL("Wielu ju� si� takich pojawi�o, ka�dy sko�czy� jako jego posi�ek.")<<endl;
                    Sleep(1000);
                    Sleep(3000);
                        system("cls");
                    goto rozmowa3;
                break;
                case 4:
                    if ((wybor[5]==2)||(wybor[5]>=4))
                    {
                    cout<<PL("Anna - Wybacz lecz nie wywi�za�e� si� z obowi�zku...nie mog� ci zap�aci�.")<<endl;
                    Sleep(2500);
                        system("cls");
                    goto rozmowa3;
                    }
                    else if ((wybor[5]==1)||(wybor[5]==3))
                    {
                        cout<<PL("Anna - Nale�a� do poprzedniego burmistrza, mojego ojca. M�wi� �e mam go da� wybra�cowi aby pom�c mu pozby� si� z�a...")<<endl;
                        Sleep(2500);
                        system("cls");
                        goto rozmowa3;
                    }
                break;
                case 5:
                    cout<<PL("*�egnasz si� z burmistrzem i Ann� odchodz�c w przeciwnym kierunku.*")<<endl;
                    Sleep(2000);
                        system("cls");
                    break;
                default:
                    cout<<PL("Nie ma wi�cej opcji, wybierz jeszcze raz.")<<endl;
                    Sleep(1000);
                        system("cls");
                    goto rozmowa3;
                break;
                }//Koniec pierwszej po�owy historii


    cout<<PL("Rozmy�laj�c o wampirze i przepowiedni w��czy�e� si� bez celu po mie�cie, nie maj�c zielnego poj�cia co ze sob� teraz zrobi�.")<<endl;
    cout<<PL("Ju� dawno zasz�o s�o�ce, a na ulicach by�o coraz mniej ludzi. Id�c tak bez celu zaw�drowa�e� pod karczm�.")<<endl;
    cout<<PL("Przeszuka�e� kieszenie, na szcz�cie znalaz�e� troch� z�otych monet. Bior�c g�eboki oddech pchn��e� drzwi i wszed�e� do �rodka.")<<endl;
    cout<<R"(      .======================================.
      | ___ ___ ___               _   _   _  |
      | \_/ \_/ \_/ C|||C|||C||| |-| |-| |-| |
      | _|_ _|_ _|_  ||| ||| ||| |_| |_| |_| |
      '======================================'

           .:.
          C|||'
        ___|||______________________________
       [____________________________________]
        |   ____    ____    ____    ____   |
        |  (____)  (____)  (____)  (____)  |
        |  |    |  |    |  |    |  |    |  |
        |  |    |  |    |  |    |  |    |  |
        |  |    |  |    |  |    |  |    |  |
        |  |____|  |____|  |____|  |____|  |
        |  I====I  I====I  I====I  I====I  |
        |  |    |  |    |  |    |  |    |  |
        )"<<endl;
        cout<<PL("*Podszed�e� do baru, po�o�y�e� na stole monety prosz�c m�czyzn� stoj�cego za lad� o posi�ek i co� do picia.*")<<endl;
        cout<<PL("Ten wzi�� monety i kaza� ci poczeka�, kilka minut p�niej siedzia�e� jedz�c ciep�� zupe i popijaj�c j� piwem.")<<endl;
        cout<<PL("W mi�dzy czasie nas�uchiwa�e� rozm�w ludzi wok�, jednak nic nie zwr�ci�o twojej szczeg�lnej uwagi.")<<endl;
        cout<<PL("Kiedy ju� mia�e� wychodzi� do karczmy wpad� zdyszany m�czyzna, krzykn�� do kelnera aby ten poda� mu kufel piwa")<<endl;
        cout<<PL("po czym usadowi� si� na krze�le obok Ciebie.")<<endl;
        cout<<PL("Zauwa�y�e� �e owa osoba ma poszarpane ca�e ramie z kt�rego s�czy si� krew.")<<endl;
        rozmowa4:
            cout<<PL("1.Jest Pan ranny...")<<endl;
            cout<<PL("2.Co si� Panu sta�o?")<<endl;
            cout<<PL("3.*Nic nie m�wisz, wpatrujesz si� tylko w ran�.*")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Co m�wisz?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cin>>wybor[8];
                    switch (wybor[8])
                    {
                    case 1:
                        system("cls");
                        cout<<PL("M�czyzna - Do wesela si� zagoi. *Wypija na raz kufel piwa podany przez kelnera.*")<<endl;
                    break;
                    case 2:
                        system("cls");
                            cout<<PL("M�czyzna - Nie tw�j interes m�ody.")<<endl;
                    break;
                    case 3:
                        system("cls");
                            cout<<PL("M�czyzna - Co si� tak lampisz?")<<endl;
                    break;
                    default:
                            cout<<PL("Nie ma wi�cej opcji dialogowych. Wybierz jeszcze raz.")<<endl;
                            Sleep(2000);
                            system("cls");
                            goto rozmowa4;
                    break;
                    }

            cout<<PL("Ch�odny ton oraz podej�cie s�siada sprawi�o �e jeszcze szybciej chcia�e� opu�ci� karczm�.")<<endl;
            cout<<PL("Jednak zacisn��e� z�by i wyci�gn��e� z kieszeni opatrunek.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Je�li Pan pozwoli mog� Pana opatrzy�...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Ten widocznie wkurzony twoim natr�ctwem odwr�ci� si� prosto do Ciebie chc�c kaza� Ci si� odwali�. Lecz dostrzeg� znami�.")<<endl;
            cout<<PL("Pyrchn�� tylko i odpowiedzia� aby� robi� co chcesz.")<<endl;
            cout<<PL("Prze�kn��e� gul� w gardle i zabra�e� si� do opatrywania.")<<endl;
            cl();
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("KILKA MINUT PӏNIEJ")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("*Sko�czy�e� opatrywanie ramienia nieznajomego.*")<<endl;
            cout<<PL("M�czyzna - Jestem Iwan, wybacz za tak ch�odny pocz�tek i dzi�ki za pomoc. EXP+75")<<endl;
            exp=exp+75;
            if ((wybor[5]==2)||(wybor[5]==4))
            {
                if (exp==150);
                {
                    lvl++;
                    cout<<PL("Gratulacje uzyska�e� kolejny level!Poziom: ")<<lvl<<endl;
                    exp=0;
                }
            }
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("W takim razie Iwan powiesz mi kto ci� tak za�atwi�?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Iwan - Wilki. W lesie za miastem jest ich pe�no. Chcia�em na nie zapolowa�, ale zawsze chodz� ca�ym stadem. Cudem im uciek�em.")<<endl;
            cout<<PL("*Do rozmowy do��czy� si� kelner, kt�ry przechodzi� obok.*")<<endl;
            cout<<PL("Kelner - Pff tak o wilki ci na pewno chodzi�o. Wcale nie o to aby podliza� si� tej elfce.")<<endl;
            cout<<PL("Iwan - Nie wtr�caj nosa w nie swoje sprawy kelnerzyku.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("W tym lesie mieszkaj� elfy?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Kelner - Kiedy� mo�e i tak, ale gobliny i wilki si� ich pozby�y, teraz zosta�a tylko Elen.*Ch�opak zebra� puste naczynia i znikn��.*")<<endl;
            cout<<PL("Iwan - Zgaduje �e jeste� tu pierwszy dzie�, jak chcesz mo�esz przenocowa� u mnie panie wybraniec.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Jestem ")<<nick<<PL(". M�w mi po imieniu. I z ch�ci� skorzystam z twojej oferty.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("*Iwan zap�aci� za piwo i wyszli�cie z karczmy. Po paru minutach drogi w ciszy doszli�cie na skraj miasta.")<<endl;
            cout<<PL("Nowy znajomy otworzy� drzwi do starego drewnianego domu, wszed�e� do niego zaraz po nim.*")<<endl;
            cout<<PL("Iwan - to nie luksusowy pa�ac, ale chyba jako podzi�kowanie za opatrunek ujdzie?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Jak najbardziej, ratujesz mnie przed noc� pod go�ym niebem.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Gospodarz u�miechn�� si� w odpowiedzi i wskaza� ��ko na k�rym dane by�o ci odpocz��.")<<endl;
            cout<<PL("Kiedy tylko si� po�o�y�e� zmorzy� ci� sen.")<<endl;
            cl();
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("RANEK")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
             cout<<PL("Obudzi�o mnie pianie kogut�w. Wsta�em leniwie z ��ka i spostrzeg�em �e Iwan jeszcze �pi na kanapie obok.")<<endl;
             cout<<PL("Wczorajsza rozmowa o lesie i elfach podsun�a mi pomys� gdzie mog� znale�� rad� co mam robi� jako wybraniec.")<<endl;
             cout<<PL("Znalaz�em kawa�ek kartki z atramentem i zapisa�em gospodarzowi wiadomo��, �e wybieram si� do lasu porozmawia� z Elen.")<<endl;
            cl();
            cout<<PL("GRATULACJE UKO�CZY�E� PIERWSZY ROZDZIA� HISTORII!")<<endl;
            historia++;
            goto lokacje;
            }
            if (historia>0)
            {
                cout<<PL("Ju� uko�czy�e� ten rozdzia�.")<<endl;
                goto lokacje;
            }
            break;

     case 2:
        if ((lvl>=2)&&(historia==1))
        {
            cout<<PL("Jak najciszej opu�ci�e� lokum Iwana i skierowa�e� swoje kroki w stron� lasu.")<<endl;
            cout<<PL("Podczas drogi obserwowa�e� jak miasto budzi si� do �ycia.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Pӣ GODZINY PӏNIEJ")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Doszed�e� wreszcie do lasu, wsz�dzie by�y tabliczki ostrzegaj�ce przed watah�.")<<endl;
            cout<<PL("Zacz��e� si� zastanawia� jak wielki jest ten las.")<<endl;
            cout<<PL("Westchn��e� tylko i zacz��e� i�� przed siebie maj�c nadziej� �e szybko odnajdziesz elfk�.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cl();
            cout<<PL("JAKI� CZAS PӏNIEJ")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Chodzi�e� po lesie szukaj�c jakichkolwiek �lad�w elfki, ale nic nie mog�e� znale��.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("A mog�em zapyta� Iwana o drog� lub cokolwiek...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("*Usiad�e� zrezygnowany pod najbli�szym drzewem odk�adaj�c bro� na bok, pusty �o��dek zacz�� dawa� o sobie znak.*")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Mog�em te� i�� co� kupi� na �niadanie...Eh chyba lepiej b�dzie wraca�...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("*Kiedy chcia�e� si� podnie�� k�tem oka wy�apa�e� ruch w pobliskich krzakach.*")<<endl;
            getch();
            if (wybor[0]==1)
            {
                cout<<PL("*Wstaj�c chwyci�e� za �uk i wymierzy�e� strza�� w krzaki.*")<<endl;
            }
            else if(wybor[0]==2)
            {
                cout<<PL("*Wstaj�c chwyci�e� za miecz i tarcz� przyjmuj�c pozycj� do obrony.*")<<endl;
            }
            else if (wybor[0]==3)
            {
                cout<<PL("*Jakim� cudem w kieszeni mia�e� kolejne fiolki. Wyci�gn��e� jedn� celuj�c w krzaki.*")<<endl;
            }
            cout<<PL("Serce bi�o ci jak szalone, lecz stara�e� si� zachowa� spok�j.")<<endl;
            cout<<PL("Po chwili krzaki zn�w si� poruszy�y i zobaczy�e� par� oczu skupionych na Tobie.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED );
            cout<< R"(
                    _
       / \      _-'
     _/|  \-''- _ /
__-' { |          \
    /             \
    /       "o.  |o }
    |            \ ;
                  ',
       \_         __\
         ''-_    \.//
           / '-____'
          /
        _'
      _-
)"<<endl;
SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Powoli z opuszczonym �bem szczerz�c k�y z zaro�li wyszed� wilk.")<<endl;
        cout<<PL("Ca�y czas oboje bacznie si� obserwowali�cie oczekuj�c jakiegokolwiek ruchu przeciwnika.")<<endl;
        cout<<PL("Musia�e� przyzna� �e zwierz� wygl�da�o napraw� ol�niewaj�co, pierwszy raz widzia�e� wilka z tak ciekawym ubarwieniem futra i bystrymi oczami.")<<endl;
        cout<<PL("Badaj�c jego wygl�d spostrzeg�e� rann� �ap� zwierz�cia. Najpewniej po k�usowniczej pu�apce. Mimo wszystko zrobi�o ci si� go szkoda.")<<endl;
        cout<<PL("Niestety opu�ci�e� przez to lekko gard�, wilk widz�c to nastroszy� si� warcz�c.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Chwila...Iwan m�wi� �e chodzicie stadem...Zostawili ci� przez ran�?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Zwierz� zdawa�o si� rozumie� co m�wisz i przesta�o warcze�.")<<endl;
        cout<<PL("Nie chcia�e� go zabija�...strach i niepok�j te� odesz�y, chcia�e� mu pom�c.")<<endl;
        cl();
        if (wybor[0]==1)
            {
                cout<<PL("*Opu�ci�e� �uk i powoli usiad�e� z powrotem pod drzewem.*")<<endl;
            }
            else if(wybor[0]==2)
            {
                cout<<PL("*Powoli od�o�y�e� tarcze i tak samo ostro�nie usiad�e� ponownie pod drzewem.*")<<endl;
            }
            else if (wybor[0]==3)
            {
                cout<<PL("*Schowa�e� fiolk� i powoli usiad�e� pod drzewem.*")<<endl;
            }
            cout<<PL("Zwierz� uwa�nie obserwowa�o twoje ruchy szukaj�c w nich podst�pu.")<<endl;
            cout<<PL("Odnalaz�e� w kieszeni ostatni kawa�ek banda�a.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Nie chc� ci� skrzywdzi�...chce ci tylko pom�c...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Wilk przechyli� �eb w lewo chowaj�c k�y.")<<endl;
            cout<<PL("Odrzuci�e� bro� jeszcze dalej i wyci�gn��e� przed siebie d�o�.")<<endl;
            cout<<PL("Zwierz� zacz�o nieufnie podchodzi�, kiedy stan�� przed twoj� d�oni� serce ci stan�o my�l�c, �e zaraz j� stracisz.")<<endl;
            cout<<PL("Jednak wilk poliza� ci� tylko po niej i usiad� naprzeciwko Ciebie wysuwaj�c do przodu rann� �ap�.")<<endl;
            cout<<PL("Najdelikatniej jak tylko umai�e� zaj��e� si� opatrywaniem jej, ca�y czas jednak maj�c si� na baczno�ci.")<<endl;
            cl();
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("CHWILA PӏNIEJ")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Kiedy sko�czy�e�, poczu�e� �e kto� cie obserwuj�. Dyskretnie zbada�e� wzrokiem teren. Za jednym z drzew dostrzeg�e� posta�.")<<endl;
            cout<<PL("Wilk nagle wsta� i rzuci� si� na Ciebie, przewracaj�c ci� na ziemi�.")<<endl;
            cout<<PL("Szykowa�e� si� poczu� b�l, ale za to zwierz� zacz�o ci� liza� po twarzy.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Nastraszy�e� mnie...a chcia�e� tylko podzi�kowa�.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Pog�aska�e� wilka po grzbiecie, ten zszed� z Ciebie i usiad� obok.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("A ty kimkolwiek jeste� mo�esz sie pokaza�, wiem �e nas obserwujesz.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Z krzak�w na �rodek ma�ej polanki na kt�rej byli�cie wysz�a zakapturzona posta�.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
            cout<< R"(
             ..-.--..
           ,','.-`.-.`.
          :.',;'     `.\.
          ||//----,-.--\|
        \`:|/-----`-'--||'/
         \\|:    |:'   ||
          `||      \   |!
          |!|          ;|
          !||:.   --  /|!
         /||!||:.___.|!||\
        /|!|||!|    |!||!\\:.
     ,'//!||!||!`._.||!||,:\\\
    : :: |!|||!|    |!||! |!::
    | |! !||!|||`---!|!|| ||!|
    | || |!|||!|    |!||! |!||
)"<<endl;
SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("? - Jestem Elena, wiatr przekaza� mi �e ci� tu znajd�...My�la�am �e b�dziesz kolejnym podrabia�cem, ale nie...")<<endl;
        cout<<PL("Jeste� prawdziwym wybra�cem...Cho� za mn�, drzewa maj� uszy. Wszystko ci wyja�ni� obiecuj�.")<<endl;
        cl();
        cout<<PL("Wsta�e� z ziemi, Elena odwr�ci�a si� i zacz�a odchodzi�. Spojrza�e� na wilka, ten trwa� przy twoim boku.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Czyli co..zostajesz moim kompanem?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Wilk pokiwa� �bem w g�r� i w d� i ruszy� za Elen�. Zebra�e� swoj� bro� z ziemi i r�wnie� ruszy�e� w �lad za elfk�.")<<endl;
        cout<<PL("Po kilku minutach drogi przez zaro�la doszli�cie nad rzek�. Elena podesz�a do wielkiego kamienia le��cego na brzegu.")<<endl;
        cout<<PL("Nakre�li�a r�k� jakie� znaki i nagle pojawi�y si� drzwi.")<<endl;
        cout<<PL("Elena - Zapraszam.")<<endl;
        cout<<PL("Wraz z nowym towarzyszem spojrzeli�cie na siebie i weszli�cie do �rodka.")<<endl;
        cout<<PL("Wewn�trz by�o naprawd� przytulnie, jak w zwyk�ym domu. Elena zamkn�a za wami drzwi, kt�re w momencie zamkni�cia znikn�y.")<<endl;
        cout<<PL("Elena - �rodki bezpiecze�stwa, a teraz siadajcie zrobi� wam co� do jedzenia.")<<endl;
        cout<<PL("Usiad�e� przy stole a wilk po�o�y� si� pod twoim krzes�em.")<<endl;
        cout<<PL("Elena krz�ta�a si� po ma�ej kuchni robi�c sa�atk� i zio�ow� herbat�.")<<endl;
        cout<<PL("Elena - Wybra�e� ju� imi�?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("S�ucham?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Elena - No imi�, dla niego. *Wskaza�a na odpoczywaj�cego wilka.*")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Ah nie...jeszcze nie.")<<"";
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("*Spojrza�e� na zwierzaka zastanawiaj�c si� co tu si� dzieje.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Nero, nazw� go Nero.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Elena - �wietnie, jemu te� zdaje si� pasowa�. *M�wi�c to po�o�y�a przed Nero misk� z mi�sem.*")<<endl;
        cout<<PL("Przed Tob� pojawi�a si� miska pe�na sa�atki i kubek gor�cej herbaty* Jedzcie, musicie nabra� si�. ")<<endl;
        cout<<PL("*M�wi�c to usiad�a naprzeciwko Ciebie u�miechaj�c si�.* Oh spokojnie zaraz ci wszystko wyja�ni�.")<<endl;
        cout<<PL("By�e� naprawd� g�odny, po 5 minutach po sa�atce nie by�o �ladu. Nero te� sko�czy� swoj� porcj�.")<<endl;
        cout<<PL("Pusta miska i talerz znikn�y, a Elena w ko�cu mog�a rozwia� wszystkie w�tpliwo�ci.")<<endl;

        cout<<PL("Elena - Z tego co mi wiadomo znasz ju� przepowiedni� i wiesz kim jest Alucard, prawda?")<<endl;
        rozmowa5:
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Czy chcesz jeszcze raz us�ysze� przepowiedni�?1.Tak 2.Nie")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cin>>wybor[9];
            if (wybor[9]==1)
            {
                system("cls");
                cout<<PL("Alucard, wampir kt�ry spa� pod naszym miastem przebudzi� si� jaki� czas temu.")<<endl;
                cout<<PL("Zacz�� terroryzowa� wiosk� i mieszka�c�w, potwory przez niego zacze�y szale�.")<<endl;
                cout<<PL("Legenda o wampirze jednak zawiera te� element o wybra�cu, kt�ry go pokona.")<<endl;
                cout<<PL("Nosi on na ramieniu znami� swojej profesji.")<<endl;
            }
            else if (wybor[9]==2)
            {
                system("cls");
             cout<<PL("Dobrze, wi�c mog� przej�� do dalszej cz�ci.")<<endl;
            }
            else if (wybor[9]>2)
            {
                cout<<PL("Mo�esz wybra� tylko tak lub nie.")<<endl;
                Sleep(1000);
                system("cls");
                goto rozmowa5;
            }
            cout<<PL("Jednak nikt nie wie, �e wersja og�lnie znana to nie ca�a przepowiednia...Poprzedni burmistrz zatai� najwa�niejsz� cz��.")<<endl;
            cout<<PL("Aby umie� rozr�ni� podr�bki od prawdziwego wybra�ca.")<<endl;
            cout<<PL("Wybraniec musi mie� czyste serce, wedle przepowiedni kiedy spotka na swej drodze rannego czy to wroga czy przyjaciela zawsze go opatrzy.")<<endl;
            cout<<PL(R"(*Elena przenios�a wzrok na Nero. *Ka�dy poprzedni ,,wybraniec" chcia� skrzywdzi� rannego wilka, kt�rego los mu zsy�a�.)")<<endl;
            cout<<PL("Jeste� pierwszym kt�ry pom�g�...jeste� prawdziwym wybra�cem. Nie podr�bk� szukaj�ca chwa�y.")<<endl;
            exp=exp+250;
            if (exp==250);
                {
                    lvl++;
                    cout<<PL("Gratulacje uzyska�e� kolejny level!Poziom: ")<<lvl<<endl;
                    exp=0;
                }
            cout<<PL("*Nero po�o�y� g�ow� na twoich kolanach widocznie szcz�liwy.*")<<endl;
            cout<<PL("Elena - Gdyby� go zabi�, musia�by� si� zmierzy� z ca�a watah�. Inaczej nie zdoby�by� tego czego potrzebujesz do walki.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("A czego potrzebuj�?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Ponownie pojawi�y si� drzwi przez kt�re teraz wszed� Iwan...lecz z jedn� r�nic�, mia� elfie uszy.")<<endl;
            cout<<PL("Iwan - Mam nadziej� �e nie gniewasz si� �e nie powiedzia�em nic o byciu elfem?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Nie no, rozumiem �e chcieli�cie mnie sprawdzi�.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Elfy u�miechn�y si� w odpowiedzi, Iwan wyci�gn�� zza plec�w wielki miecz.")<<endl;
            cout<<PL("Elena - Skarb, kt�rego strze�e wataha. Musia�by� odebra� to si�� jak reszta, ale pomog�e� przyw�dcy. Wataha wi�c oddaje ci to jako prezent.")<<endl;
            cl();
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Przyw�dcy?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Elena - Tak, Nero to alfa stada a teraz te� tw�j towarzysz w dalszej wyprawie.")<<endl;
            cout<<PL("Nie zostawili go bo by� ranny jak za�o�y�e�.")<<endl;
            cout<<PL("Kaza� reszcie pilnowa� skarbu a sam wyszed� skonfrontowa� si� z Tob�.")<<endl;
            cout<<PL("*Pog�aska�e� wilka i odebra�e� przedmioty od Iwana.*")<<endl;
            hp=hp+15;
            cout<<"HP="<<hp<<endl;
            str=str+20;
            cout<<PL("Si�a=")<<str<<endl;
            dex=dex+10;
            cout<<PL("Zr�czno�c=")<<dex<<endl;
            cout<<PL("Elena - Jeste� teraz gotowy na starcie z potworami kopalni.")<<endl;
            cout<<PL("Po podwy�szeniu waszych umiej�tno�ci w trakcie walki z nimi b�dziecie w stanie walczy� z Alucardem.")<<endl;
            cout<<PL("Jest tam te� przedmiot kt�ry musisz obowi�zkowo zabra�.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Jaki przedmiot?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Elena - Dowiesz si� kiedy go odnajdziesz,szukaj skrzyni z znakiem jak twoje znami�.")<<endl;
            cout<<PL("A teraz ruszajcie, aby dotrze� do niej zanim zajdzie s�o�ce.")<<endl;
            cout<<PL("*Elena da�a ci pe�no jedzenia oraz banda�y.*")<<endl;
            cout<<PL("Po�egna�e� si� z elfami i razem z Nero opu�ci�e� mieszkanie w g�azie.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("No to teraz czeka nas d�ugi spacer, co towarzyszu?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Nero tylko pomacha� ogonem i ruszy� przodem prowadz�c ci� do kolejnej lokalizacji.")<<endl;
            cl();
            cout<<PL("GRATULACJE UKO�CZY�E� DRUGI ROZDZIA� HISTORII!")<<endl;
            cout<<PL("Zdoby�e� r�wnie� kompana.")<<endl;
            cout<<PL("Statystki Nero: ")<<endl;
            cout<<PL("�ycie=")<<hpn<<endl;
            cout<<PL("Si�a=")<<strn<<endl;
            cout<<PL("Szybko��=")<<fn<<endl;
            historia++;
            goto lokacje;
        }
        else if(lvl<2)
        {
            cout<<PL("Nie mo�esz wej��, za ma�y poziom. Wybierz jeszcze raz.")<<endl;
            goto lokacje;
        }
        else if (historia>1)
            {
                cout<<PL("Ju� uko�czy�e� ten rozdzia�.")<<endl;
                goto lokacje;
            }
        break;//Koniec 2 rozdzia�u

    case 3:
        if ((lvl>=3)&&(historia==2))
        {
          cout<<PL("Na miejsce dotarli�cie po zmroku, okaza�o si� �e kr�tka drzemka w po�owie drogi okaza�a si� d�u�sz� przerw�.")<<endl;
          cout<<PL("Zebra�e� patyki aby rozpali� ognisko na pobliskiej polanie, nie chcia�e� wchodzi� do kopalni noc�.")<<endl;
          cout<<PL("Nero pilnowa� torby z zapasami, ca�y czas obserwuj�c twoje pr�by rozpalenia ognia, kt�re nie sz�y za dobrze.")<<endl;
          cout<<PL("Wilk wsta�, poszed� w kierunku krzak�w a po chwili wr�ci� z patykiem w pysku.")<<endl;
          cout<<PL("Bez s�owa wzi��e� go od towarzysza i magicznie dzi�ki niemu uda�o si� w ko�cu rozpali� ogie�.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cout<<PL("Dzi�ki, zas�u�y�e� na co� dobrego na kolacje.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("*Pog�aska�e� wilka i poda�e� mu z torby kawa�ek mi�sa.* Elena u�y�a jaki� tam czary mary aby nie popsu�o si� w trakcie drogi.")<<endl;
          cout<<PL("Wilk ucieszony zabra� jedzenie i usadowi� si� w bezpiecznej odleg�o�ci od ogniska zaczynaj�c je��.")<<endl;
          cout<<PL("Poszed�e� w �lady towarzysza i wyj��e� bochenek chleba.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cl();
          cout<<PL("RANEK")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("Nero obudzi� cie warczeniem, nawet nie wiedzia�e� kiedy poprzedniego wieczora zasn��e�.")<<endl;
          cout<<PL("Chwyci�e� za bro� i szybko wsta�e�...jednak polana by�a pusta.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cout<<PL("Chcia�e� mnie tylko obudzi�?")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("Zwierz� ruchami �ba potwierdzi�o twoje stwierdzenie.")<<endl;
          cout<<PL("Westchn��e� tylko i zacz��e� zbiera� rzeczy aby wyruszy�.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cout<<PL("TIME SPEEK")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("Stan�li�cie przed wej�ciem do opuszczonej kopalni. Zacz�y nachodzi� ci� w�tpliwo�ci czy to aby na pewno dobry pomys�...")<<endl;
          cout<<PL("Lecz teraz nie by�o ju� odwrotu. Wzi��e� g��boki oddech i przekroczy�e� stary drewniany pr�g.")<<endl;
          cout<<PL("Na pod�odze le�a�y stare lampy naftowe, wzi��e� jedn� i nape�ni�e� naft� od Eleny.")<<endl;
          cout<<PL("Teraz ju� w 100% gotowi mogli�cie ruszy� dalej.")<<endl;
          cl();
          cout<<PL("Po kilku minutach podr�y w d� g��wnym korytarzem doszli�cie do rozwidlenia.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cout<<PL("W kt�r� stron�?")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("Nero wystrzeli� jak z procy w prawo. Pobieg�e� za nim nie rozumiej�c co go ugryz�o i nagle tak si� zachowa�.")<<endl;
          cout<<PL("Niestety ale zaraz po tym Nero znikn�� w d�ugim ciemnym korytarzu.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cout<<PL("NERO!!")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("Nawo�ywa�e� wilka lecz ten ju� dawno znikn�� z twojego pola widzenia.")<<endl;
          cout<<PL("Po chwili dotar�e� do kolejnego rozwidlenia.")<<endl;
          korytarze1:
          SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("W kt�r� stron� chcesz si� uda�?1.Lewy korytarz 2.Prawy korytarz")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cin>>wybor[10];//labirynt
          if(wybor[10]==1)
          {
              system("cls");
              cout<<PL("Poszed�e� w lewo, po kilku minutach drogi prostym korytarzem nagle nast�pi�e� na dziwny kamie�, kt�ry pod ci�arem ")<<endl;
              cout<<PL("twojego nacisku ods�oni� wielk� zapadni� w ziemi z kolcami na dnie.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
              cout<<PL("Elena nie m�wi�a o pu�apkach...oby Nero w �adn� nie wpad�.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
              cout<<PL("Kiedy zabra�e� nog� z kamienia zapadnia si� zamkn�a.")<<endl;
              cout<<PL("Powoli i ostro�nie przeszed�e� na drugi koniec uwa�nie teraz obserwuj�c gdzie stajesz.")<<endl;
              cout<<PL("Po d�u�szej chwili drogi doszed�e� do kolejnego rozwidlenia.")<<endl;
          }
          else if (wybor[10]==2)
          {
              system("cls");
              cout<<PL("Poszed�e� w prawo, po d�u�szej chwili drogi prostym korytarzem doszed�e� do kolejnego rozwidlenia.")<<endl;
          }
        else if (wybor[10]>2)
        {
            cout<<PL("Mo�esz wybra� tylko lewo lub prawo.")<<endl;
            Sleep(1000);
            system("cls");
            goto korytarze1;
        }
        korytarze2:
          SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("Gdzie teraz?1.Lewy korytarz 2.Prawy korytarz")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cin>>wybor[11];
          if(wybor[11]==1)
          {
              system("cls");
              cout<<PL("Poszed�e� w lewo, po d�u�szej chwili drogi stwierdzi�e� �e czas na kr�tk� przerw�.")<<endl;
          }
          else if (wybor[11]==2)
          {
              system("cls");
              cout<<PL("Szed�e� spokojnie prawym korytarzem, a� us�ysza�e� czyje� kroki.")<<endl;
              cout<<PL("Z ka�d� chwil� stawa�y si� one coraz g�o�niejsze, odstawi�e� lamp� na ziemi� i wyci�gn��e�")<<endl;
              cout<<PL("miecz od Iwana przyjmuj�c pozycj� do ataku. ")<<endl;
              smok: //walka
              SetConsoleTextAttribute( hOut, FOREGROUND_RED );
              cout<<R"(                                             ,--,  ,.-.
               ,                   \,       '-,-`,'-.' | ._
              /|           \    ,   |\         }  )/  / `-,',
              [ ,          |\  /|   | |        /  \|  |/`  ,`
              | |       ,.`  `,` `, | |  _,...(   (      .',
              \  \  __ ,-` `  ,  , `/ |,'      Y     (   /_L\
               \  \_\,``,   ` , ,  /  |         )         _,/
                \  '  `  ,_ _`_,-,<._.<        /         /
                 ', `>.,`  `  `   ,., |_      |         /
                   \/`  `,   `   ,`  | /__,.-`    _,   `\
               -,-..\  _  \  `  /  ,  / `._) _,-\`       \
                \_,,.) /\    ` /  / ) (-,, ``    ,        |
               ,` )  | \_\       '-`  |  `(               \
              /  /```(   , --, ,' \   |`<`    ,            |
             /  /_,--`\   <\  V /> ,` )<_/)  | \      _____)
       ,-, ,`   `   (_,\ \    |   /) / __/  /   `----`
      (-, \           ) \ ('_.-._)/ /,`    /
      | /  `          `/ \\ V   V, /`     /
   ,--\(        ,     <_/`\\     ||      /
  (   ,``-     \/|         \-A.A-`|     /
 ,>,_ )_,..(    )\          -,,_-`  _--`
(_ \|`   _,/_  /  \_            ,--`
 \( `   <.,../`     `-.._   _,-`
          )"<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED) ;
        while ((hp>=0)||(hps>=0))
    {
        if (d==0) {cout<<PL("Nagle z ciemno�ci wy�oni�a si� posta� przypominaj�ca smoka, rzuci�a si� na ciebie.")<<endl;
        cout<<PL("Statystyki przeciwnika:")<<endl;
        cout<<PL("�ycie: ")<<hps<<endl;
        cout<<PL("Si�a: ")<<sila<<endl;}
        srand(time(NULL));
        dms=rand()%10;
        hp=hp-dms;
        cout<<PL("Zdrowie: ")<<hp<<endl;
        cout<<PL("Otrzymane obra�enia: ")<<dms<<endl;
        Sleep(1000);
        cout<<endl;
        if (hp<0)
        {
            cout<<PL("Nie �yjesz.")<<endl;
            goto death;
        }
        if (d==0)
        {
            cout<<PL("Oberwa�e� w rami�, monstrum wbi�o ci w nie szpony.")<<endl;
            cout<<PL("U�y�e� miecza i wbi�e� go za to w bok potwora.")<<endl;
            Sleep(2000);
            d++;
        }

        else if(d==1)
        {
            cout<<PL("Monstrum chwyci�o drug� r�k� za ostrze miecza wyci�gaj�c go z rany i odrzucaj�c na bok.")<<endl;
            cout<<PL("Straci�e� miecz, pozosta�a ci tylko walka na pie�ci.")<<endl;
            Sleep(2000);
            d++;
        }
        else if(d==2)
        {
            cout<<PL("Starcie by�o teraz tylko unikami i wymiana cios�w mi�dzy wami.")<<endl;

            d++;
        }
        srand(time(NULL));
        dmg=rand()%15;
        hps=hps-dmg;
        cout<<endl;
        cout<<PL("Zdrowie przeciwnika: ")<<hps<<endl;
        cout<<PL("Zadane obra�enia: ")<<dmg<<endl;
        if (hps<0)
        {
            cout<<PL("Zabi�e� potwora.")<<endl;
            goto fab;
        }
        cout<<endl;
        getch();
        system ("cls");
        goto smok;

    }


    fab:
        exp=exp+100;
        cout<<"Za pokonanie potwora dostajesz 100 exp'a."<<endl;
        cout<<PL("Omijasz martwego przeciwnika, zbierasz z ziemi sw�j miecz i siadasz pod �cian�.")<<endl;
        cout<<PL("Wyci�gasz z torby banda�e od Elen i opatrujesz rany.")<<endl;
        hp=hp+25;
        cout<<"Zdrowie: "<<hp<<endl;
          }
           else if (wybor[11]>2)
        {
            cout<<PL("Mo�esz wybra� tylko lewo lub prawo.")<<endl;
            goto korytarze2;
        }
        if (wybor[11]==2)
    {
        cout<<PL("Ponownie s�yszysz �e kto� biegnie w twoj� stron�. Wstajesz szybko z ziemi b�d�c gotowy do kolejnej walki.")<<endl;
        cout<<PL("Lecz z ciemno�ci korytarza wy�ania si� Nero.")<<endl;
        cout<<PL("Opuszczasz bron i wzdychasz. ")<<endl;
        cl();
    }
        else if (wybor[11]==1)
    {
        cout<<PL("S�yszysz �e kto� biegnie w twoj� stron�. Wstajesz szybko z ziemi wyci�gaj�c miecz.")<<endl;
        cout<<PL("Lecz z ciemno�ci korytarza wy�ania si� Nero.")<<endl;
        cout<<PL("Opuszczasz bron i wzdychasz.")<<endl;
    }
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Najpierw mnie zostawiasz a teraz nagle wracasz, tak si� nie robi stary.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Wilk jednak ochoczo podchodzi do Ciebie trzymaj�c co� w pysku.")<<endl;
        cout<<PL("Przyjmujesz przedmiot od towarzysza, okazuje si� �e to mapa!")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("HAHA, �wietnie nie b�dziemy musieli b��dzi� po tych korytarzach.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Na mapie by�y zar�wno oznaczone pu�apki jak i skr�ty dzi�ki kt�rym b�dzie mo�na omija� korytarze z potworami. ")<<endl;
        cout<<PL("Wyci�gn��e� z torby ostatni kawa�ek mi�sa i da�e� Nero.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Dobrze si� spisa�e� przyjacielu, wybacz za wcze�niej.")<<endl;
        cout<<PL("Skoro mamy map� my�l�, �e mo�emy chwil� odpocz��.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Jaki� czas p�niej")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Dzi�ki mapie wasza podr� przez kopalnie posz�a o wiele szybciej, omin�li�cie wszystkie pu�apki oraz potwory.")<<endl;
        cout<<PL("Obecnie szli�cie ostatnim prostym korytarzem, kt�ry mia� was zaprowadzi� do pomieszczenia w kt�rym znajduje si�")<<endl;
        cout<<PL("przedmiot wed�ug Elen bardzo ci potrzebny. Jednak stan�li�cie na kolejnym rozwidleniu.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Na mapie nie ma ju� �adnej drogi...Tu powinna by� wielka pusta sala.")<<endl;
        cout<<PL("Eh musimy ponownie wybra�...")<<"";
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("*Patrzysz na Nero. Ten skupiony raz spogl�da na lewo raz na prawo.*")<<endl;
        cout<<PL("Ostatecznie podchodzi do prawego korytarza, a potem spogl�da na Ciebie.")<<endl;
        korytarze3:
          SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("Kt�ry korytarz wybierasz?1.Lewy 2.Prawy")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cin>>wybor[12];
          if(wybor[12]==1)
          {
              system("cls");
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
              cout<<PL("Rozdzielmy si�, je�li kt�re� napotka pu�apk� albo przeciwnika wraca tutaj.")<<endl;
              cout<<PL("Jeden z nich musi by� dobry....")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
              cout<<PL("Ruszy�e� lewym korytarzem, mia�e� nadziej� �e Nero nie napotka nic w swoim korytarzu.")<<endl;
              cout<<PL("Po paru minutach drogi zacz��e� my�le� �e trafi�e� na pusty korytarz, jednak w momencie kiedy")<<endl;
              cout<<PL("chcia�e� zawr�ci� po wilka nast�pi�e� na jak�� p�ytk�.")<<endl;
              cout<<PL("Nagle w �cianach pojawi�y si� otwory, kt�re zasypa�y ci� atakiem strza�.")<<endl;
              hp=hp-10;
              cout<<"Zdrowie: "<<hp<<endl;
              cout<<PL("Oberwa�e� w udo oraz obojczyk, grad strza� po chwili usta�.")<<endl;
              cout<<PL("Ci�ko dysz�c siadasz na ziemi, mocno krwawisz. Chcesz opatrzy� rany lecz...")<<endl;
              cl();
              SetConsoleTextAttribute( hOut, FOREGROUND_RED );
              cout<<R"(                                             ,--,  ,.-.
               ,                   \,       '-,-`,'-.' | ._
              /|           \    ,   |\         }  )/  / `-,',
              [ ,          |\  /|   | |        /  \|  |/`  ,`
              | |       ,.`  `,` `, | |  _,...(   (      .',
              \  \  __ ,-` `  ,  , `/ |,'      Y     (   /_L\
               \  \_\,``,   ` , ,  /  |         )         _,/
                \  '  `  ,_ _`_,-,<._.<        /         /
                 ', `>.,`  `  `   ,., |_      |         /
                   \/`  `,   `   ,`  | /__,.-`    _,   `\
               -,-..\  _  \  `  /  ,  / `._) _,-\`       \
                \_,,.) /\    ` /  / ) (-,, ``    ,        |
               ,` )  | \_\       '-`  |  `(               \
              /  /```(   , --, ,' \   |`<`    ,            |
             /  /_,--`\   <\  V /> ,` )<_/)  | \      _____)
       ,-, ,`   `   (_,\ \    |   /) / __/  /   `----`
      (-, \           ) \ ('_.-._)/ /,`    /
      | /  `          `/ \\ V   V, /`     /
   ,--\(        ,     <_/`\\     ||      /
  (   ,``-     \/|         \-A.A-`|     /
 ,>,_ )_,..(    )\          -,,_-`  _--`
(_ \|`   _,/_  /  \_            ,--`
 \( `   <.,../`     `-.._   _,-`
          )"<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED) ;
              cout<<PL("Pojawia si� kolejny ,,smok'', nie masz czasu si� opatrzy� wstajesz pomimo b�lu i wyjmujesz miecz.")<<endl;
              cout<<PL("Statystyki przeciwnika:")<<endl;
                cout<<PL("�ycie: ")<<hps1<<endl;
                cout<<PL("Si�a: ")<<sila<<endl;
              while ((hp>=0)||(hps>=0))
    {

        if (d1==0)
        {
        srand(time(NULL));
        dms=rand()%10;
        hp=hp-dms;
        cout<<PL("Zdrowie: ")<<hp<<endl;
        cout<<PL("Otrzymane obra�enia: ")<<dms<<endl;
        Sleep(1000);
        cout<<endl;
        if (hp<0)
        {
            cout<<PL("Nie �yjesz.")<<endl;
            goto death;
        }
            cout<<PL("Przeciwnik wbieg� w Ciebie z impetem posy�aj�c ci� na najbli�sz� �cian�.")<<endl;
            cout<<PL("Zda�e� sobie spraw� �e nie masz szans...W tym starciu przegrasz.")<<endl;
            cout<<PL("Kiedy potw�r mia� zada� cios rzuci� si� na niego Nero, gryz�c go w �ydk�.")<<endl;

        }

        if(d1==1)
        {
            cout<<PL("Potw�r kompletnie straci� zainteresowanie Tob� skupi� si� na pozbyciu si� Nero.")<<endl;
            cout<<PL("Ten jednak by� szybszy i unika� cios�w przeciwnika, a w mi�dzy czasie go gryz�c")<<endl;
            cout<<PL("Da�o ci to czas na opatrzenie ran.")<<endl;
            hp=hp+10;
            cout<<PL("Zdrowie: ")<<hp<<endl;

        }
         if(d1==2)
        {
            cout<<PL("Jednak w ko�cu jeden z cios�w trafi� Nero, szpony bestii rozdar� ca�y grzbiet wilka.")<<endl;
            hpn=hpn-20;
            cout<<PL("Zdrowie Nero: ")<<hpn<<endl;
            cout<<PL("Widz�c to rzuci�e� si� w�ciek�y na przeciwnika odcinaj�c mu mieczem g�ow�.")<<endl;
            hps1=hps1-40;
            cout<<PL("Zdrowie przeciwnika: ")<<hps1<<endl;
            cl();
            goto potwor;
        }
        srand(time(NULL));
        dmg=rand()%15;
        hps1=hps1-dmg;
        cout<<endl;
        cout<<PL("Zdrowie przeciwnika: ")<<hps1<<endl;
        cout<<PL("Zadane obra�enia: ")<<dmg<<endl;
        potwor:
            if (hps1<0)
        {
            cout<<PL("Potw�r pada martwy na ziemi�.")<<endl;
            exp=exp+150;
            goto fab1;
        }
        d1++;
        cout<<endl;
        getch();
        system ("cls");
    }
    fab1:

        cout<< PL(" Podbiegasz do Nero, ranny ci�ko dyszy. Straci� du�o krwi.")<<endl;
        cout<< PL("Wyjmujesz banda�e z fiolkami od Elen i opatrujesz towarzysza.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("B�dzie dobrze, wyjdziesz z tego...")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<< PL("Na szcz�cie mieszanki zi� szybko zatamowa�y krwawienie, opatrzy�e� grzbiet Nero.")<<endl;
        cout<< PL("Ten tylko poliza� twoj� d�o� i chcia� wsta�.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Oj nie nie nie...zosta� tutaj, p�jd� po to cholerstwo i wr�c� do ciebie.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<< PL("Wilk skin�� �bem i z powrotem si� po�o�y�.")<<endl;
        cout<< PL("Pobieg�e� dalej korytarzem, chcia�e� jak najszybciej to zako�czy�.")<<endl;
        cout<<PL("Po paru minutach drogi dotar�e� do wielkiej skalnej sali, pe�nej skrzy�.")<<endl;
        cout<< PL("Nie mia�e� czasu, ruszy�e� w g��b sali szukaj�c skrzyni z znakiem takim jak twoje znami�.")<<endl;
          }
          else if (wybor[12]==2)
          {
              system("cls");
              cout<<PL("Postanawiasz zaufa� wilkowi, idziesz razem z nim w prawo.")<<endl;
              cout<<PL("Po paru minutach drogi wychodzicie w wielkiej skalnej sali. Pe�nej skrzy�.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
              cout<<PL("Znowu mia�e� racj� oraz ponownie mi pomog�e�, dzi�kuje.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
              cout<<PL("Wilk wyszczerzy� k�y jakby chcia� si� u�miechn�� i ruszy� w g��b sali.")<<endl;
              cout<< PL("Ruszy�e� za nim rozgl�daj�c si� za skrzyni� z znakiem takim jak twoje znami�.")<<endl;
              cout<<PL("Jednak twoje poszukiwania przerwa�o �a�osne wycie wilka, spojrza�e� w jego stron�")<<endl;
              cout<<PL("i dostrzeg�e� na pod�odze pe�no od�amk�w szk�a w kt�re niestety wszed� wilk. ")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
              cout<<PL("Kurde...poka� �apy.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
              cout<<PL("W �apach tw�j towarzysz ma pe�no od�amk�w. Wyci�gasz z torby banda�e z fiolkami od Elen i opatrujesz Nero.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
              cout<<PL("Nie ruszaj si�, znajd� czego potrzebujemy i wracamy.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
              cout<<PL("Rozgl�dasz si� ponownie po sali.")<<endl;

          }
        else if (wybor[12]>2)
        {
            cout<<PL("Mo�esz wybra� tylko lewo lub prawo.")<<endl;
            Sleep(1000);
            system("cls");
            goto korytarze3;
        }
        cout<<PL("Dostrzeg�e� j� cudem w rogu sali, podbiegasz do skrzyni.")<<endl;
        if (wybor[0]==1)
        {
        cout<<PL("*Na jej wieku widnieje symbol �uku. Otwierasz j� i znajdujesz ko�czan wype�nionymi srebrnymi strza�ami.*")<<endl;
        }
        else if(wybor[0]==2)
        {
        cout<<PL("*Na jej wieku widnieje symbol miecza. Otwierasz j� i znajdujesz srebrny sztylet.*")<<endl;
        }
        else if (wybor[0]==3)
        {
        cout<<PL("*Na jej wieku widnieje symbol ro�liny. Otwierasz j� i znajdujesz fiolk� wype�nion� czerwonym p�ynem.*")<<endl;
        }

        cout<<PL("Ko�o przedmiotu le�y zwini�ty pergamin, zabierasz go i chowasz do torby wraz z now� zdobycz�.")<<endl;
        exp=exp+100;

        if(wybor[12]==1)
        {
        cout<<PL("Zamykasz skrzynie i p�dem wracasz do Nero.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Jak si� trzymasz stary?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Pytasz kiedy dobiegasz na miejsce gdzie zostawi�e� wilka. Ten na tw�j widok si� o�ywi� i wsta�.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Czas wraca�, ale nie powiniene� jeszcze si� tak przem�cza�. Zio�a Elen zdzia�a�y cuda")<<endl;
        cout<<PL("ale musisz odpoczywa�.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("M�wi�c to bierzesz Nero na r�ce i ruszasz w drog� powrotn�.")<<endl;
        }
        else if (wybor[12]==2)
        {
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Czas wraca�.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("M�wi�c to bierzesz Nero na r�ce i ruszasz w drog� powrotn�.")<<endl;
        }
        cl();
        SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("JAKI� CZAS PӯNIEJ")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("W ko�cu doszli�cie do wyj�cia, zn�w by�a noc.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Straci�em w tej kopalni poczucie czasu.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
       cout<<PL("Wr�ci�e� z Nero na polane na kt�rej wcze�niej spali�cie.")<<endl;
       cout<<PL("Delikatnie od�o�y�e� go na ziemi� i ruszy�e� do lasu nazbiera� drewna.")<<endl;
       cout<<PL("Przy okazji uda�o ci si� upolowa� dwa zaj�ce, idealnie na kolacj�.")<<endl;
       SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
       cout<<PL("CHWILA POZNIEJ")<<endl;
       SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
       cout<<PL("W trakcie kiedy wasze zaj�ce si� piek�y w ognisku zmieni�e� zar�wno sobie jak i Nero banda�e.")<<endl;
       cout<<PL("Na szcz�cie rany dzi�ki przedmiot od Elen bardzo szybko si� goi�y.")<<endl;
       cout<<PL("Po zjedzonej kolacji wyci�gn��e� pergamin kt�ry znalaz�e� w skrzyni.")<<endl;
       cout<<PL(R"(
   __________________________________________________________________
 / \                                                                 \.
|   |1.Przedmiot kt�ry otrzyma�e� jest niezb�dny do zabicia Alucarda. |.
 \_ |2.Podnosi on twoje statystyki o 20 punkt�w.                      |.
    |3.Twoich towarzyszy w kampanii r�wnie�, lecz o 15 punkt�w.       |.
    |4.Musisz sprytnie go u�y�, Alucard nie wie o jego istnieniu.     |.
    |   ______________________________________________________________|___
    |  /                                                                 /.
    \_/_________________________________________________________________/.
               )")<<endl;
    cout<<PL("Na odwrocie widnia� ostatni punkt.")<<endl;
      if ((wybor[0]==1)||(wybor[0]==2))
        {
        cout<<PL("*5.Srebro rani wampiry, musisz trafi� w jego serce aby go zabi�.*")<<endl;
        }
        else if (wybor[0]==3)
        {
        cout<<PL("*5.Zatruta krew, musi j� wypi�.*")<<endl;
        }
        cout<<PL("Wiedzia�e� ju� co b�dziesz robi� jutro. Wraz z Nero po�o�yli�cie si� spa�.")<<endl;
        cout<<PL("Aby wypocz�� i by� gotowym na to co musi nadej��.")<<endl;
        cl();
        if (exp==300);
                {
                    lvl++;
                    cout<<PL("Gratulacje uzyska�e� kolejny level!Poziom: ")<<lvl<<endl;

                    exp=0;
                }
	    hp=hp+20;
            cout<<"HP="<<hp<<endl;
            str=str+20;
            cout<<PL("Si�a=")<<str<<endl;
            dex=dex+20;
	    cout<<PL("Zr�czno�c=")<<dex<<endl;
cout<<endl;
    cout<<PL("GRATULACJE UKO�CZY�E� TRZECII ROZDZIA� HISTORII!")<<endl;
cout<<endl;
            cout<<PL("Statystki Nero: ")<<endl;
		hpn=hpn+15;
            cout<<PL("�ycie=")<<hpn<<endl;
		strn=strn+15;
            cout<<PL("Si�a=")<<strn<<endl;
		fn=fn+15;
            cout<<PL("Szybko��=")<<fn<<endl;
            historia++;
            goto lokacje;
        }

        else if (lvl<3)
        {
            cout<<PL("Nie mo�esz wej��, za ma�y poziom. Wybierz jeszcze raz.")<<endl;
            goto lokacje;
        }
        else if (historia>2)
            {
                cout<<PL("Ju� uko�czy�e� ten rozdzia�.")<<endl;
                goto lokacje;
            }
    break;

    case 4:
        if (lvl>=4)
        {
            system("cls");
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("RANEK")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

            cout<<PL("Obudzi�o ci� lizanie po twarzy. Nero jak zawsze mia� ciekawe pomys�y na pobudk�.")<<endl;
            cout<<PL("Wsta�e� rozgl�daj�c si� woko�o, nadal byli�cie na polanie.")<<endl;
            cout<<PL("Zauwa�y�e� kosz obok ogniska. Na wierzchu le�a�a kartka.")<<endl;
            cout<<R"(
.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.
|                                                                       |
|   Gratulacj�! Uda�o si� wam, niestety ale teraz musicie radzi�        |
|     sobie sami. Alucard odkry� �e co� knujemy, wys�a� do lasu         |
|     gobliny. Musz� zosta� ukryta w domu, Iwan wr�ci� do miasta        |
|     jak gdyby nigdy nic lecz mia� przed tym dostarczy� wam to.        |
!     Skoro to czytasz to oboje jeste�my bezpieczni, a ty zapewne       !
:     masz to po co poszed�e� do kopalni. Mam nadziej� �e oby�o         :
:     si� bez wi�kszych problem�w.                                      :
.                                                                       .
.      Musicie si� po�pieszy�, je�li Alucard dowie si� gdzie jeste�cie  .
:      wy�le za wami gobliny, a wtedy nie b�d� mog�a wam pom�c.         :
:                                                                       :
!      Jego kaplica jest po drugiej stronie miasta, rzadko kiedy j�     !
|      opuszcza. Musicie odzyska� szybko si�y i ruszy� mu na spotkanie. |
|      Im szybciej tym lepiej. Powodzenia.                              |
|                                                                       |
|       PS.                                                             |
|       Mam nadziej� �e wszytko co wam da�am by�o przydatne.            |
|                                                                       |
|                                                  Elen                 |
|                                                                       |
`-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'
            )"<<endl;
            cl();
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Zrobi�a dla nas ju� tyle...musimy im jak najszybciej pom�c.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
             cout<<PL("Zagl�dasz do koszyka, pe�no w nim jedzenia, banda�y oraz kolejnych fiolek leczniczych.")<<endl;
             cout<<PL("Na szcz�cie ju� po wczorajszej dawce czujecie si� dobrze, a wasza regeneracja jest")<<endl;
             cout<<PL("przy�pieszona, dzi�ki temu odzyskujecie powoli zdrowie.")<<endl;
             hp=hp+15;
            cout<<"Twoje �ycie= "<<hp<<endl;
             hpn=hpn+15;
            cout<<PL("�ycie Nero= ")<<hpn<<endl;
            cout<<PL("Zmieni�e� opatrunki zar�wno sobie jak i wilkowi, po czym poda�e� �niadanie.")<<endl;
            cout<<PL("Ca�y czas jednak my�lami odbiega�e� do nieuniknionego starcia z wampirem.")<<endl;
            cout<<PL("Obawia�e� si� czy to co posiadasz na pewno da rad�.")<<endl;
            cout<<PL("Nero wyczu� fakt �e zamartwiasz si� przysz�o�ci�, usiad� naprzeciwko Ciebie")<<endl;
            cout<<PL("patrz�c ci prosto w oczy, jakby chcia� powiedzie�:")<<endl;
            cout<<PL("Hej, masz mnie. Damy sobie razem rad�.")<<endl;
            cout<<PL("U�miechn��e� si� i pog�aska�e� wilka po �bie.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Masz racj�, damy sobie rady.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Pozosta�� cz�� poranka rozmy�la�e� nad planem pokonania krwiopijcy...")<<endl;
            cl();

            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("WIECZ�R")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Znajdujesz si� przed wielk� star� kaplic�, wok� pe�no grob�w.")<<endl;
            cout<<PL("Niekt�re wida�, �e niedawno zosta�y zasypane �wie�� ziemi�.")<<endl;
            cout<<PL("Bierzesz g��boki oddech...i ruszasz, otwieraj� si� przed tob� ogromne wrota.")<<endl;
            cout<<PL("W �rodku, przed o�tarzem dostrzegasz posta�.")<<endl;
            cout<<PL("Bierzesz g��boki oddech i przekraczasz pr�g. Drzwi zamykaj� si� za Tob� z hukiem.")<<endl;
            cl();
            cout<<R"( ................OOOOOOOOOO.
 ............,OOOOOOOOOOOOOOOOO^
,]]]]]]]]]/=OOOOOOOOOOOOOOOOOOOOOOO/
,]]]]]]]OOOOOOOOOOOOOOOOOOOOOOOOOOOOO^
,]]]]]]]OOOOOOOOOOOOOOOOOOOOOOOOOOOOO^.
,]]]]]]OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO^
,]]]]]]OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO^
 .=O@.OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO^
 .=OO.OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO^=OO
 =OOO.OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO^=OO
=/OOO.OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO^=OOO
=OOOO.=OO/*o^=OOOOOOOOOOOOOOOO^=*`*O=O/`.OOO
=OOOOO=OOO^..,OO..`OOOOOO...=O^....OOO^.=OOO
=OOOOOOOOOO^..O..o=OOOOOO^..==^..^OOOOO=OOOO
=OOOOOOOOOOOOO.=OOOOOOOOOOOO^==OOOOOOOOOOOOO
=OOOOOOOOOOOOOOOOOO^]=O,[OOOOOOOOOOOOOOOOOOO
 =OOOOOOOOOOOOOOOOO^=OO..OOOOOOOOOOOOOOOOOOO
 =OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO.
 .=OO..OOO^..................=OOOOOOO^=OOO.
,[[[[[OOOO/,[[[[[[[[[[[[[[[[[[`\OOOOO/\^.
,[[[[[OOOOOOOO[OOOOOOOOOO[OOOOOOOOOO^^
,[[[[[OOOOOOOO[\OOOOOOOOO[\OOOOOOOOO^.
,[[[[[OOOOOOOOOOOOOOOOOOO[OOOOOOOOOO
,[[[[[[OOOO/\OOO[OOOOOOOOOOOO/\OOOO
 .......OOO^.=OO.OOOOOOO.OO^.=OOOO
 ........OOOOO.`.OOOOOOO.O..=OOOO
 .........=OOOO............OOOO^
 ..........=OOOOOOOOOOOOOOOOO^.
 ..........=OOOOOOOOOOOOOOOO^
 ...........,=OOOOOOOOOOOOO.

            )"<<endl;
            cout<<PL("|Statystyki Alucarda|")<<endl;
            cout<<PL("�ycie: ")<<ahp<<endl;
            cout<<PL("Szybko��: ")<<af<<endl;
            cout<<PL("Si�a: ")<<asl<<endl;
            Sleep(5000);
            system("cls");
            SetConsoleTextAttribute( hOut, FOREGROUND_RED );
            cout<<PL("Witaj wybra�cu, czeka�em na ciebie...haha m�wi� to ka�demu kretynowi kt�ry odwa�y si� do mnie przyj��.")<<endl;
            cout<<PL("Widzia�e� groby przed kaplic�? Jeden z nich stanie si� twoim grobem, hahaha.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Nie jestem podr�bk� jak wszyscy kt�rzy tu byli przedm�.")<<endl;
            cout<<PL("Jestem prawdziwym wybra�cem i pokonam ci�, aby w mie�cie znowu panowa� pok�j!")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

            cout<<PL("W jednej sekundzie straci�e� wampira z oczu, by� zbyt szybki.")<<endl;
            cout<<PL("Nagle znalaz� si� za Tob�, poczu�e� jego lodowat� d�o� na swoim karku.")<<endl;
            cout<<PL("Lecz zanim zd��y�e� cokolwiek zrobi�, ten rzuci� Tob� w jedn� z kolumn kaplicy.")<<endl;
            hp=hp-10;
            cout<<PL("Zdrowie: ")<<hp<<endl;
            if (wybor[0]==1)
    {
        cout<<PL("Kaszl�c podnosisz si� z ziemi, chwytasz za �uk i zaczynasz strzela� w wampira.")<<endl;
        cout<<PL("Ten jednak dalej popisuje si� swoj� pr�dko�ci�, �adna strza�a nie dosz�a do celu.")<<endl;
    }
    else if(wybor[0]==2)
    {
            cout<<PL("Kaszl�c podnosisz si� z ziemi, wyci�gasz miecz i pomimo b�lu biegniesz w kierunku wampira.")<<endl;
            cout<<PL("Ten jednak kiedy zamachn��e� si� broni� ponownie si� przeni�s� na o�tarz.")<<endl;
            cout<<PL("Bro� z pustym �wistem przeci�a powietrze.")<<endl;
    }
    else if (wybor[0]==3)
    {
            cout<<PL("Kaszl�c podnosisz si� z ziemi, wyci�gasz fiolk� i rzucasz j� w miejsce gdzie obecnie stoi wampir.")<<endl;
            cout<<PL("Ten jednak w momencie rozbicia naczynia ponownie u�y� pr�dko�ci i si� przeni�s� na o�tarz.")<<endl;
    }
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    cout<<PL("TWOJE MY�LI: Cholera jak ja mam go cho�by zadrapa�...")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<PL("Tym razem Alucard pojawi� si� przed Tob�, nie mia�e� czasu na reakcj�.")<<endl;
    cout<<PL("Oberwa�e� od niego z pi�ci w brzuch, z twoich ust polecia�a krew.")<<endl;
    hp=hp-10;
    cout<<PL("Zdrowie: ")<<hp<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    cout<<PL("TWOJE MY�LI: W takim tempie marnie sko�cz�...Ka�dy jego atak zabiera 10 punkt�w zdrowia.")<<endl;
    cl();
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

    while (hp>=0)
    {
        if (d2==0)
        {
        cout<<PL("Nie mia�e� nawet chwili aby pomy�le� nad kolejnym ruchem, pojawia� si� niewiadomo sk�d zadaj�c cios za ciosem.")<<endl;
        d2++;
        }
        hp=hp-dma;
        cout<<PL("Zdrowie: ")<<hp<<endl;
        Sleep(1000);
        cout<<endl;

        if (d2==1)
        {
        cout<<PL("Alucard ok�adaj�c ci� pi�ciami ca�y czas szale�czo si� �mia�. Wizja kolejnego trupa do kolekcji go bawi�a.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        cout<<PL("No co jest, mia�e� by� TYM WYBRA�CEM KT�RY MNIE ZABIJE hahahah.")<<endl;
        cout<<PL("A prosz�, kto tu kogo zaraz zaszlachtuje?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Nawet nie wiesz w kt�rym momencie twoja bro� znalaz�a sie poza twoim zasi�giem.")<<endl;
        cout<<PL("Wyrwa� ci j� w kt�rym� momencie? Sam j� upu�ci�e�? Ju� sam nie wiedzia�e�.")<<endl;
        }

        if (d2==1)
        {
        cout<<PL("Ka�dy kolejny cios r�wna� si� coraz wi�kszej ka�u�y krwi, wampir nie szcz�dzi� si�y. Jego szpony")<<endl;
        cout<<PL("rani�y ca�e twoje cia�o, opada�e� z si�. Koniec by� bliski.")<<endl;
        }

        if (d2==2)
        {
        cout<<PL("Zacz��e� �a�owa� �e tu przyszed�e�, �e pomog�e� wtedy Annie. Obarczono ci� misj� zabicia wampira...")<<endl;
        }

         if (d2==3)
        {
        cout<<PL("Lecz jeste� za s�aby...Przedmioty nie s� na tyle mocne aby z nim si� mierzy�...")<<endl;
        }

         if (d2==4)
        {
        cout<<PL("To od pocz�tku by�a samob�jcza misja...")<<endl;
        }

        if (hp<=10)
        {
            cl();
            cout<<PL("Ledwo �ywy wy�apa�e� ruch ko�o o�tarza, Nero smutnym spojrzeniem obserwowa� jak obrywasz.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("TWOJE MY�LI: Trzymaj si� planu...Wytrzymam jeszcze chwil�...tak s�dz�...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            goto nero;
        }
        d2++;
        cout<<endl;
        Sleep(1500);
        //system ("cls");
    }

nero:
    cout<<PL("Alucard by� zbyt zaj�ty Tob� aby zwr�ci� uwag� na wilka, kt�ry niepostrze�enie prze�lizgn�� si� dziur� z ty�u kaplicy.")<<endl;
    if (wybor[0]==1)
    {
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        cout<<PL("Wiesz wybra�cu, mam taki zwyczaj... Wypijam kielich krwi moich ofiar...poczekaj chwil�.")<<endl;
        cout<<PL("Twojej krwi tak�e pragn� skosztowa�...")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<R"(
                   .:....:.
                .:!!!!!!!!!!!!:.
           .::!!!!!!!!!!!!!!!!!!!!::.
    ..::!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!::..
..```. . eeee .... ... '~' ... .... eeee . .'''..
 `!h:. $ $$$$ $$$$ $$$$b d$$$$ $$$$ $$$$ $ .:h!'
  `!!!!. `$$$ '$$' '$$$' `$$$` '$$' $$$'.!!!!!'
    `!!!!.`$$ .   .  ......   .   . $$'.!!!!'
     `!!!! $$ !!!!!!!!!!!!!!!!!!!!! $$ !!!!'
       `!!h ` !!!!!!!!!!!!!!!!!!!!! ' d!!'
         `!h !!!!!!!!!!!!!!!!!!!!!!! d!'
          ``!!!!!!!!!!!!!!!!!!!!!!!!''
             ``!!!!!!!!!!!!!!!!!!''
                 ```!!!!!!!!'''
    )"<<endl;
    cl();
    cout<<PL("Alucard nagle znalaz� si� na o�tarzu.")<<endl;
    cout<<PL("W tym momencie wyskoczy� na niego schowany Nero. Pchni�ty wampir spad� z o�tarza i wyl�dowa� twarz� na posadzce.")<<endl;
    cout<<PL("Nie by�o du�o czasu, chwyci�e� lez�cy obok �uk i wycelowa�e� srebrn� strza�� prosto w serce.")<<endl;
    cout<<PL("Ta w ko�cu trafi�a cel..idealnie w serce. Alucard wyda� przera�liwy krzyk b�lu.")<<endl;

    }
    else if(wybor[0]==2)
    {
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        cout<<PL("Wiesz wybra�cu, mam taki zwyczaj... Wypijam kielich krwi moich ofiar...poczekaj chwil�.")<<endl;
        cout<<PL("Twojej krwi tak�e pragn� skosztowa�...")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<R"(
                    .:....:.
                .:!!!!!!!!!!!!:.
           .::!!!!!!!!!!!!!!!!!!!!::.
    ..::!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!::..
..```. . eeee .... ... '~' ... .... eeee . .'''..
 `!h:. $ $$$$ $$$$ $$$$b d$$$$ $$$$ $$$$ $ .:h!'
  `!!!!. `$$$ '$$' '$$$' `$$$` '$$' $$$'.!!!!!'
    `!!!!.`$$ .   .  ......   .   . $$'.!!!!'
     `!!!! $$ !!!!!!!!!!!!!!!!!!!!! $$ !!!!'
       `!!h ` !!!!!!!!!!!!!!!!!!!!! ' d!!'
         `!h !!!!!!!!!!!!!!!!!!!!!!! d!'
          ``!!!!!!!!!!!!!!!!!!!!!!!!''
             ``!!!!!!!!!!!!!!!!!!''
                 ```!!!!!!!!'''
    )"<<endl;
    cl();
    cout<<PL("Alucard nagle znalaz� si� na o�tarzu.")<<endl;
    cout<<PL("W tym momencie wyskoczy� na niego schowany Nero. Pchni�ty wampir spad� z o�tarza i wyl�dowa� twarz� na posadzce niedaleko Ciebie.")<<endl;
    cout<<PL("Nie by�o du�o czasu, wyci�gn��e� ukryty srebrny sztylet i ostatkiem si� rzuci�e� w kierunku Alucarda, mierz�c mi�dzy oczy...")<<endl;
    cout<<PL("Ten idealnie podni�s� g�ow� z ziemi, sztylet trafi�, Alucard wyda� przera�liwy krzyk b�lu.")<<endl;
    }
    else if (wybor[0]==3)
    {
        cout<<PL("W pysku trzyma� fiolk� z zatrut� krwi�, wystarczy�o aby dola� to do kielicha na o�tarzu a wampir padnie.")<<endl;
        cout<<PL("Nero nie m�g� znie�� �e pozwala katowa� ")<<nick<<"";
        cout<<PL(" ,lecz nie m�g� nic na to poradzi�. Jedyn� opcj� by�o po�wi�cenie wybra�ca aby wampir zgin��.")<<endl;
        cout<<PL("Opcja ta nie podoba�a mu si� ani troch�.")<<endl;
        cout<<PL("Zakrad� i wspi�� si� na o�tarz, szybko przechyli� �eb i wla� zawarto�� fiolki do kielicha sakralnego.")<<endl;
        cout<<PL("Teraz niech wampir to tylko wypije...")<<endl;
        cout<<PL("Wilk wycofa� si� i ukry� za jedn� z �aw ko�cielnych.")<<endl;
        cout<<PL("Akurat w tym momencie wampir przesta� atakowa�")<<nick<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        cout<<PL("Wiesz wybra�cu, mam taki zwyczaj... Wypijam kielich krwi moich ofiar...poczekaj chwil�.")<<endl;
        cout<<PL("Twojej krwi tak�e pragn� skosztowa�...")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<R"(
                    .:....:.
                .:!!!!!!!!!!!!:.
           .::!!!!!!!!!!!!!!!!!!!!::.
    ..::!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!::..
..```. . eeee .... ... '~' ... .... eeee . .'''..
 `!h:. $ $$$$ $$$$ $$$$b d$$$$ $$$$ $$$$ $ .:h!'
  `!!!!. `$$$ '$$' '$$$' `$$$` '$$' $$$'.!!!!!'
    `!!!!.`$$ .   .  ......   .   . $$'.!!!!'
     `!!!! $$ !!!!!!!!!!!!!!!!!!!!! $$ !!!!'
       `!!h ` !!!!!!!!!!!!!!!!!!!!! ' d!!'
         `!h !!!!!!!!!!!!!!!!!!!!!!! d!'
          ``!!!!!!!!!!!!!!!!!!!!!!!!''
             ``!!!!!!!!!!!!!!!!!!''
                 ```!!!!!!!!'''
    )"<<endl;
    cl();
    cout<<PL("Alucard nagle znalaz� si� na o�tarzu.")<<endl;
       SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
       SetConsoleTextAttribute( hOut, FOREGROUND_RED );
    cout<<PL("Oh sekunda! Nie dopi�em po twoim poprzedniku.")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<PL("Wampir za jednym razem wypi� ca�a zawarto�� zatrutego kielicha.")<<endl;
    cout<<PL("U�miechn�� si� oblizuj�c usta, jednak zaraz zacz�� si� dusi�.")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    cout<<PL("M�wi�em...j-jestem wybra�cem...i..i..ci� zabij�...")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

    }
        cout<<PL("Wampir zacz�� si� rozpada�..jakby by� z papieru. A z jego cia�a zacz�o bi� �wiat�o ")<<endl;
        cout<<PL("tworz�c wielk� �un� nad ko�cio�em, przypominaj�c� zorze polarn�.")<<endl;

        cout<<PL("Lecz ty nie masz sposobno�ci zobaczy� tego zjawiska.")<<endl;
        cout<<PL("Padasz na ziemi�, powa�nie krwawisz...Nero podbiega do Ciebie, widz�c tw�j tragiczny stan")<<endl;
        cout<<PL("chce lecie� po torb� z apteczk� od Eleny...lecz zatrzymujesz zwierzaka.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Nie zd��ysz...zosta� ze mn� do ko�ca...")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Wilk k�adzie sie obok ciebie opieraj�c g�ow� o tw�j tors, z jego oczu lec� �zy...")<<endl;
        cout<<PL("Tak samo zaczynasz p�aka� wiedz�c �e to koniec...")<<endl;
        cout<<PL("Powoli odp�ywasz...obraz zaczyna si� zamazywa� i ciemnie�...")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("B�d� za tob� t�skni� przyjacielu...")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Wypowiadasz ostatnim tchnieniem...i umierasz...")<<endl;
        hp=0;
        cl();

        cout<<PL("Ludzie widz�c �un� �wiat�a nad kaplic�, zacz�li wychodzi� szcz�liwi z dom�w... ")<<endl;
        cout<<PL("Bawili si�, ta�czyli, �piewali...nie wiedz�c jaka tragedia tam mia�a miejsce...")<<endl;
        cout<<PL("Gobliny i inne potwory widz�c j� natomiast zrozumia�y kl�sk� swego pana...wycofali si� zn�w do swoich kryj�wek.")<<endl;
        cout<<endl;
        cout<<PL("Kiedy Anna, Elena, Iwan oraz Burmistrz dotarli do kaplicy, zastali ca�a watah� czekaj�ca na zewn�trz.")<<endl;
        cout<<PL("Przera�eni spojrzeli po sobie i wbiegli do niej...Spostrzegli Nero pochylaj�cego si� nad cia�em ")<<nick<<endl;
        cout<<PL("Zrozumieli jak okrutna batalia to by�a...")<<endl;
        cout<<endl;
        cout<<PL("Od tamtej pory kaplica jest miejscem, gdzie co wiecz�r przyw�dca watahy wznosi �a�obne wycie za przyjacielem...")<<endl;
        cout<<PL("Ka�dego wieczora...a� po sw�j ostatni dzie�.")<<endl;
        cout<<R"(                              __
                            .d$$b
                          .' TO$;\
                         /  : TP._;
                        / _.;  :Tb|
                       /   /   ;j$j
                   _.-"       d$$$$
                 .' ..       d$$$$;
                /  /P'      d$$$$P. |\
               /   "      .d$$$P' |\^"l
             .'           `T$P^"""""  :
         ._.'      _.'                ;
      `-.-".-'-' ._.       _.-"    .-"
    `.-" _____  ._              .-"
   -(.g$$$$$$$b.              .'
     ""^^T$$$P^)            .(:
       _/  -"  /.'         /:/;
    ._.'-'`-'  ")/         /;/;
 `-.-"..--""   " /         /  ;
.-" ..--""        -'          :
..--""--.-"         (\      .-(\
  ..--""              `-\(\/;`
    _.                      :
                            ;`-
                           :\
                           ;
                           )"<<endl;
                           cl();
                           cout<<R"(


888888888888 88        88 88888888888    88888888888 888b      88 88888888ba,
     88      88        88 88             88          8888b     88 88      `"8b
     88      88        88 88             88          88 `8b    88 88        `8b
     88      88aaaaaaaa88 88aaaaa        88aaaaa     88  `8b   88 88         88
     88      88""""""""88 88"""""        88"""""     88   `8b  88 88         88
     88      88        88 88             88          88    `8b 88 88         8P
     88      88        88 88             88          88     `8888 88      .a8P
     88      88        88 88888888888    88888888888 88      `888 88888888Y"'
)"<<endl;





    }

        else if (lvl<4)
        {
            cout<<PL("Nie mo�esz wej��, za ma�y poziom. Wybierz jeszcze raz.")<<endl;
            goto lokacje;
        }
    break;
    death:
        SetConsoleTextAttribute( hOut, BACKGROUND_RED );
        cout<<PL("NIE �YJESZ - KONIEC GRY")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        system("pause");
    return (0);
}
    }
