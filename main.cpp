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
 case 'π': result += static_cast < char >( 0xa5 ); break;
 case 'Ê': result += static_cast < char >( 0x86 ); break;
 case 'Í': result += static_cast < char >( 0xa9 ); break;
 case '≥': result += static_cast < char >( 0x88 ); break;
 case 'Ò': result += static_cast < char >( 0xe4 ); break;
 case 'Û': result += static_cast < char >( 0xa2 ); break;
 case 'ú': result += static_cast < char >( 0x98 ); break;
 case 'ø': result += static_cast < char >( 0xbe ); break;
 case 'ü': result += static_cast < char >( 0xab ); break;
 case '•': result += static_cast < char >( 0xa4 ); break;
 case '∆': result += static_cast < char >( 0x8f ); break;
 case ' ': result += static_cast < char >( 0xa8 ); break;
 case '£': result += static_cast < char >( 0x9d ); break;
 case '—': result += static_cast < char >( 0xe3 ); break;
 case '”': result += static_cast < char >( 0xe0 ); break;
 case 'å': result += static_cast < char >( 0x97 ); break;
 case 'Ø': result += static_cast < char >( 0xbd ); break;
 case 'è': result += static_cast < char >( 0x8d ); break;
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

int hp=30, str=20, lvl=1, exp=0, dex=20;//G≥Ûwny
int dm, hp_goblin1=5,hps=50,dms,dmg,hps1=40,sila=30;//Przeciwnicy
int hpn=30, fn=40, strn=30; //Wilk
int wybor[20],d=0,d1=0, historia=0,d2=0;//Historia
int ahp=100, af=50, asl=50,dma=10;//Alucard

int main()
{
    system("color 07");
    HANDLE hOut;
 hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    cout << PL ("Witaj! Aby zaczπÊ grÍ podaj nazwÍ gracza:  "); cin>>nick;

    fstream plik; //£adowanie danych gracza do pliku
    plik.open("Dane.txt", ios::out);
    plik<<nick<<endl;
    system("cls");

    cout<<PL("ParÍ informacji na start:")<<endl; //Startowe informacje

    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );

    cout<<PL("Takim kolorem bÍdπ oznaczone wypowiedzi podczas ktÛrych musisz dokonaÊ wyboru.")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

    cout<<PL("Takim kolorem bÍdπ oznaczone twoje wypowiedzi.")<<endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    cout<<PL("Takim kolorem oznaczony jest skok czasu akcji.")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<PL("W zdaniach oznaczonych *...* zawarty jest opis akcji/czynnoúci.")<<endl;



    cout<<PL("A wiÍc nazywasz siÍ ")<<nick<<PL("?Mi≥o ciÍ poznaÊ! BÍde twoim przewodnikiem podczas krÛtkiego wstÍpu.")<<endl;
    cout<<PL("Skoro juø siÍ znamy czas na wybranie klasy twojej postaci. Masz do wyboru: ")<<endl;
    klasa:
    cout<<PL("1.£ucznik")<<endl;
    cout<<"2.Rycerz"<<endl;
    cout<<"3.Zielarz"<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<PL("KtÛrπ klasÍ wybierasz?")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cin>>wybor[0];
        switch( wybor[0] ) //WybÛr klasy
        {
        case 1:
                cout << PL("A wiÍc jesteú ≥ucznikiem! Twoje obecne statystki: ")<<endl;
        break;
        case 2:
                cout <<PL("A wiÍc jesteú rycerzem! Twoje obecne statystki: ")<<endl;
        break;
        case 3:
                cout <<PL("A wiÍc jesteú zielarzem! Twoje obecne statystki: ")<<endl;
        break;
        default:
                cout<<PL("Nie ma wiÍcej dostÍpnych postaci. Wybierz jeszcze raz.")<<endl;
                Sleep(1500);
                system("cls");
                goto klasa;
        break;
        }

    cout<<PL("Poziom: ")<<lvl<<endl; //Poczπtkowe statystyki
    cout<<PL("Øycie: ")<<hp<<endl;
    cout<<PL("Si≥a: ")<<str<<endl;
    cout<<PL("ZrÍcznoúÊ: ")<<dex<<endl;


    if (wybor[0]==1)
    {
        cout<<PL("Twoimi przedmiotami startowymi sπ ≥uk i strza≥y.")<<endl;
    }
    else if(wybor[0]==2)
    {
            cout<<PL("Twoimi przedmiotami startowymi sπ miecz i tarcza.")<<endl;
    }
    else if (wybor[0]==3)
    {
            cout<<PL("Twoimi przedmiotami startowymi sπ zio≥a lecznicze i wype≥niona zielonym p≥ynem fiolka.")<<endl;
    }


    cout<<PL("Skoro jesteú juz wyposaøony i znasz swoje statystki oraz podstawy,")<<endl;
    cout<<PL("moøe czas na walkÍ prÛbna zanim zacznie siÍ twoja przygoda?")<<endl;

    cl();

    cout<<PL("*Nagle przed ")<<nick<<PL(" pojawia siÍ goblin.*")<<endl; //Pierwszy przeciwnik,system obraøeÒ
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
    cout<<PL("A≥a!")<<nick<<PL(" zosta≥ uderzony przez przeciwnika.")<<endl;
    hp=hp-dm;
    cout<<"HP="<<hp<<endl;


        if (wybor[0]==1)
        {
        cout<<PL("*Wkurzony wyciπgasz ≥uk i strzelasz do potwora.*")<<endl;
        }
        else if(wybor[0]==2)
        {
            cout<<PL("*Wkurzony wyciπgasz miecz i atakujesz potwora.*")<<endl;
        }
        else if (wybor[0]==3)
        {
            cout<<PL("*Wkurzony wyciπgasz dziwnπ fiolkÍ i rzucasz niπ w potwora.*")<<endl;
        };
        hp_goblin1=hp_goblin1-5;
        if (hp_goblin1==0)
        {
            cout<<PL("TwÛj atak by≥ skuteczny, pozby≥eú sie wroga!EXP+75")<<endl;
        }
    exp=exp+75;


    cout<<PL("åwietnie, pokona≥eú pierwszego goblina. Moøesz w takim razie zaczπÊ prawdziwπ rozgrywkÍ.")<<endl;
    cout<<PL("Od teraz bÍdzie tylko trudniej, powodzenia!")<<endl;
    cout<<PL("*Nagle wszytko staje siÍ ciemne, kiedy otwierasz oczy znajdujesz sie na ogromnym zat≥oczonym rynku.*")<<endl;


    lokacje:
        cout<<endl;
    cout<<PL("1.Ulice miasta(od lvl'u 1)")<<endl;//WybÛr lokacji,label
    cout<<PL("2.Las za miastem(od lvl'u 2)")<<endl;
    cout<<PL("3.Opuszczona kopalnia(od lvl'u 3)")<<endl;
    cout<<PL("4.Kaplica(od lvl'u 4)")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<PL("Gdzie teraz chcesz siÍ udaÊ?")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cin>>wybor[1];

        if (wybor[1]>4)
        {
            cout<<PL("Nie ma wiÍcej dostÍpnych lokacji. Wybierz jeszcze raz: ")<<endl;
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
            cout<<PL("*Przeszed≥eú na drugπ stronÍ rynku, w miÍdzy czasie obserwujπc ludzi krÍcπcych siÍ wokÛ≥. Przechadzajπc sie bez celu")<<endl;
            cout<<PL(" ulicami zagapi≥eú sie i wpad≥eú na kogoú.*")<<endl;
            rozmowa0:
            cout<<PL("1.UGH UWAØAJ JAK £AZISZ!")<<endl;
            cout<<PL("2.Najmocniej przepraszam zagapi≥em siÍ...")<<endl;
            cout<<PL("3.*Nic nie mÛwisz.*")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Co wybierasz?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cin>>wybor[2];
                switch (wybor[2])
                {
                case 1:
                    cout<<PL("Nieznajoma - Sam patrz na drogÍ palancie. *Kobieta na ktÛrπ wpad≥eú spoglπda na Ciebie zdenerwowanym spojrzeniem.*")<<endl;
                break;
                case 2:
                    cout<<PL("Nieznajoma - Nie to ja Pana przepraszam zamyúli≥am siÍ...*Kobieta na ktÛrπ wpad≥eú spoglπda na Ciebie ≥agodnym spojrzeniem.*")<<endl;
                break;
                case 3:
                    cout<<PL("Nieznajoma - JÍzyka w gÍbie nie masz? Wypada przeprosiÊ kiedy wpadasz na kogoú. *Kobieta na ktÛrπ wpad≥eú spoglπda")<<endl;
                    cout<<PL("na ciebie obojÍtnym wzrokiem.*")<<endl;
                break;
                default:
                    cout<<PL("Nie ma wiÍcej opcji dialogowych. Wybierz jeszcze raz.")<<endl;

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

            cout<<PL("*Jej wzrok pada na Twoje ramie* Ah wiÍc to ty jesteú tym nowym ")<<"";
            if (wybor[0]==1)
            {
                cout<<PL("≥ucznikiem. *Kierujesz swoje spojrzenie na ramiÍ i widzisz znamiÍ w kszta≥cie ≥uku.*")<<endl;
            }
            else if(wybor[0]==2)
            {
                cout<<PL("rycerzem. *Kierujesz swoje spojrzenie na ramiÍ i widzisz znamiÍ w kszta≥cie miecza.*")<<endl;
            }
            else if (wybor[0]==3)
            {
                cout<<PL("zielarzem. *Kierujesz swoje spojrzenie na ramiÍ i widzisz znamiÍ w kszta≥cie kwiatu.*")<<endl;
            }

            cout<<PL("Nieznajoma - Mimo wszystko dobrze øe cie spotka≥am. Przyda mi siÍ twoja pomoc...")<<endl;
            rozmowa2:
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Czy chcesz pomÛc nieznajomej?1.Tak 2.Nie")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cin>>wybor[3];
            if (wybor[3]==1)
            {
                system("cls");
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
                cout<<PL("Dobrze wys≥ucham ciÍ.")<<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            }
            else if (wybor[3]==2)
            {
                system("cls");
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
                cout<<PL("Nie mam zamiaru ci pomÛc.")<<"";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                cout<<PL("*Chcesz odejúÊ ale nieznajoma ≥apie ciÍ za rÍkÍ.*")<<endl;
                cout<<PL("Nieznajoma - B≥agam hojnie ciÍ wynagrodzÍ obiecujÍ...")<<endl;
            }
            else if (wybor[3]>2)
            {
                cout<<PL("Moøesz wybraÊ tylko tak lub nie.")<<endl;
                Sleep(1000);
                system("cls");
                goto rozmowa2;
            }
                cout<<PL("Mam problem z chochlikami w moim domu...Posiadasz znamiÍ, powinieneú sobie z nimi poradziÊ.")<<endl;
                cout<<PL("ObiecujÍ jak tylko siÍ ich pozbÍdziesz dostaniesz naprawdÍ przydatnπ rzecz.")<<endl;


                rozmowa1:
                cout<<PL("1.Kim tak w≥aúciwie jesteú?")<<endl;
                cout<<PL("2.Opowiedz mi wiÍcej o tych chochlikach.")<<endl;
                cout<<PL("3.WiÍc ruszajmy do twojego domu.")<<endl;
                cout<<PL("4.*Nic nie mÛwisz*")<<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
                cout<<PL("Wybierz opcjÍ dialogowπ: ");
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                cin>>wybor[4];
                    switch (wybor[4])
                    {
                    case 1:
                        cout<<PL("Anna - Nazywam siÍ Anna, jestem nauczycielka w pobliskiej szkole.")<<endl;
                        Sleep(2500);
                        system("cls");
                        goto rozmowa1;
                    break;
                    case 2:
                        cout<<PL("Anna - To lubiπce psoty istoty, zazwyczaj nie robiπ AØ takich szkÛd jak teraz i nie zbliøajπ siÍ do ludzi.")<<endl;
                        Sleep(2000);
                        cout<<PL("Ale odkπd w kaplicy zaczÍ≥y dziaÊ siÍ dziwne rzeczy...wszystkie stwory powariowa≥y i siÍ zmieni≥y.")<<endl;
                        Sleep(2500);
                        system("cls");
                        goto rozmowa1;
                    break;
                    case 3:
                        cout<<PL("Anna - A wiÍc chodü za mnπ. To niedaleko stπd.")<<endl;
                        system("cls");
                    break;
                    case 4:
                        cout<<PL("Anna - Ma≥omÛwny jesteú...Chodü wiÍc po prostu za mnπ.")<<endl;
                        system("cls");
                    break;
                    default:
                        cout<<PL("Nie ma wiÍcej opcji dialogowych. Wybierz jeszcze raz.")<<endl;
                        Sleep(1000);
                        system("cls");
                        goto rozmowa1;
                        break;
                    }
               cout<<PL("*Ruszasz za kobietπ, po kilku minutach drogi wπskimi i krÍtymi alejkami stajesz przed starπ kamienicπ.*")<<endl;
               cout<<PL("Anna - To tutaj...Musisz wejúÊ sam ja mam juø tego serdecznie doúÊ.")<<endl;
               cout<<PL("*Spoglπdasz podejrzanie na kobietÍ.* Po prostu siÍ bojÍ ok?Eh idü to za≥atw.")<<endl;
               cout<<PL("Ale zanim tam wejdziesz, zdradzisz mi Twoje imiÍ...?")<<endl;
               SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
               cout<<nick<<endl;
               SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
               cout<<PL("*Nie czekajπc d≥uøej wchodzisz do kamiennicy, wszÍdzie widzisz rozwalone úciany oraz pe≥no zniszczonych przedmiotÛw.")<<endl;
               cout<<PL("W trakcie przechadzki po domu nagle zauwaøasz ruch w kπcie.*")<<endl;
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
            cout<<PL("By≥ to dziwnie wyglπdajπcy ma≥y stworek, ktÛry zaraz po zorientowaniu siÍ øe zosta≥ odkryty wyda≥ przeraüliwy pisk i w kilka ")<<endl;
            cout<<PL("sekund nie by≥ juø on sam. Otoczy≥o cie ogrom takich stworzeÒ.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("BÍdzie ciÍøej niø sπdzi≥em...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            opcje0:
            if (wybor[0]==1)
            {
                cout<<PL("1.Wyciπgasz swÛj ≥uk i celujesz do chochlika ktÛrego zauwaøy≥eú pierwszego.")<<endl;
            }
            else if(wybor[0]==2)
            {
                cout<<PL("1.Wyciπgasz miecz oraz tarczÍ przyjmujπc pozÍ do obrony.")<<endl;
            }
            else if (wybor[0]==3)
            {
                cout<<PL("1.Wyjmujesz kolejnπ dziwnπ buteleczkÍ i kierujesz z powrotem wzrok do chochlika ktÛrego zauwaøy≥eú pierwszego.")<<endl;
            }
            cout<<PL("2.Wycofujesz siÍ powoli do wyjúcia.")<<endl;
            cout<<PL("3.Kopiesz najbliøszego chochlika.")<<endl;
            cout<<PL("4.Moøe siÍ jakoú dogadamy...?*Nie ruszasz siÍ.*")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Co robisz?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cin>>wybor[5];
            system("cls");
            switch (wybor[5])
            {
                case 1:
                    cout<<PL("Wszystkie chochliki rzucajπ siÍ na Ciebie zadajπc niewielkie obraøenia, starasz siÍ broniÊ i atakowaÊ stworki ale te sπ zbyt")<<endl;//Sleep(2000);
                    cout<<PL("szybkie i wiÍkszoúci ciosÛw unikajπ.")<<endl;
            break;
                case 2:
                    cout<<PL("Chochliki szybko zagrodzi≥y ci drzwi uniemoøliwiajπc ucieczkÍ.")<<endl;

            break;
                case 3:
                    cout<<PL("Rozwúcieczy≥o to tylko pozosta≥e, ktÛre rzuci≥y sie na ciebie atakujπc.")<<endl;

            break;
            case 4:
                    cout<<PL("Chochliki obserwujπ ciÍ nie wykonujπc øadnego ruchu.")<<endl;

            break;
                default:
                    cout<<PL("Nie ma wiÍcej opcji, wybierz jeszcze raz.")<<endl;
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
                cout<<PL("Odpychasz je od siebie i uciekasz na piÍtro po drodze likwidujπc kilka szkodnikÛw przy uøyciu broni, padajπ po jednym ciosie.")<<endl;
                exp=exp+100;
                cout<<PL("Zauwaøasz starπ komodÍ stojπca idealnie na rogu schodÛw, zrzucasz jπ na wszystkie stwory ktÛre sta≥y na schodach.")<<endl;
                cout<<PL("Oficjalnie pozby≥eú sie wszystkich pozosta≥ych jednym trafieniem! EXP+100")<<endl;
                cout<<PL("Wracasz na do≥ i wychodzisz na ulicÍ gdzie czeka Anna zaniepokojona wczeúniejszymi odg≥osami walki.")<<endl;
                cout<<PL("Widzπc øe jesteú ca≥y oddycha z ulgπ.")<<endl;
                cout<<PL("*Sama wchodzi do kamiennicy a po chwili wraca.* ")<<endl;
                cout<<PL("Anna - A wiÍc naprawdÍ uda≥o ci sie ich pozbyÊ...nie wiem jak ci dziÍkowaÊ,obieca≥am ci zap≥atÍ oto ona.")<<endl;
                cout<<PL("Kobieta podaje ci ma≥a skrzynkÍ w ktÛrej znajdujesz naszyjnik, zak≥adasz go. *Wszystkie statystyki podnoszπ siÍ o 10 punktÛw.")<<endl;
                hp=hp+10;
                cout<<"HP="<<hp<<endl;
                str=str+10;
                cout<<PL("Si≥a=")<<str<<endl;
                dex=dex+10;
                cout<<PL("ZrÍcznoúc=")<<dex<<endl;
                if (exp==150);
                {
                    lvl++;

                    cout<<PL("Gratulacje uzyska≥eú kolejny level!Poziom: ")<<lvl<<endl;
                    exp=0;
                    cl();
                    cout<<PL("Chcesz odejúÊ, ale odwracajπc siÍ wpadasz na kogoú.")<<endl;
                    cout<<PL("Nieznajomy - Oh najmocniej przepraszam, widzÍ øe uporaliúcie siÍ juø z problemem, wiÍc py≥ nie bÍdzie potrzebny.")<<endl;
                    cout<<PL("*Nieznajomy chowa jakπú sakiewkÍ do kieszeni.*")<<endl;
                    cout<<PL("Anna - ")<<nick<<PL(" poznaj burmistrza naszego miasta.")<<endl;
                    cout<<PL("*Nieznajomy spoglπda na twoje ramiÍ.* Ah teraz rozumiem jesteú kolejnym pseudo wybraÒcem. Zapowiadasz siÍ obiecujπco,")<<endl;
                    cout<<PL("aø jestem ciekaw jak ci pÛjdzie z Alucardem. ChoÊ po twojej minie widzÍ øe nikt nic ci nie wyt≥umaczy≥.")<<endl;
                }
            }
            else if ((wybor[5]==2)||(wybor[5]==4))
            {
                cout<<PL("Do mieszkania wchodzi Anna wraz z jakimú mÍøczyznπ, widzπc twojπ beznadziejnπ sytuacjÍ nowa postaÊ rusza w twoim kierunku.")<<endl;
                cout<<PL("Kiedy chochliki chcπ siÍ do niego zbliøyÊ zostajπ posypane jakimú py≥em przez ktÛry padajπ nieprzytomne na ziemiÍ. Pozosta≥e na ten widok szybko siÍ ulotni≥y.")<<endl;
                cout<<PL("Anna - jednak siÍ co do Ciebie przeliczy≥am...")<<endl;
                cout<<PL("Nieznajomy mÍøczyzna - A mÛwi≥em abyú poczeka≥a, teraz nie powinny wrÛciÊ.")<<endl;
                cout<<PL("*Rozsypa≥ owy py≥ po ca≥ym pomieszczeniu. A nastÍpnie spoglπda na twoje ramiÍ.*")<<endl;
                cout<<PL("Ah teraz rozumiem jesteú kolejnym pseudo wybraÒcem. Pfi nawet chochliki ciÍ pokona≥y,")<<endl;
                cout<<PL("aø strach pomyúleÊ co zrobi z tobπ Alucard. Jestem burmistrzem, a po twojej minie widzÍ øe nikt nic ci nie wyt≥umaczy≥.")<<endl;
            }
            rozmowa3:
                cout<<PL("1.Co to by≥ za py≥?")<<endl;
                cout<<PL("2.O co ci chodzi z tym pseudo wybraÒcem?")<<endl;
                cout<<PL("3.Kim jest ten Alucard?")<<endl;
                if ((wybor[5]==2)||(wybor[5]>=4))
                {
                    cout<<PL("4.Co z tym wynagrodzeniem?")<<endl;
                }
                else if ((wybor[5]==1)||(wybor[5]==3))
                {
                    cout<<PL("4.Co to za naszyjnik?")<<endl;
                }
                cout<<PL("5.Nie mam wiÍcej pytaÒ.")<<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
                cout<<PL("Masz do mnie jakieú pytania?")<<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                cin>>wybor[7];
                switch (wybor[7])
                {
                case 1:
                    cout<<PL("Burmistrz - Py≥ z kwiatÛw maku zebranych podczas pe≥ni, te ma≥e mendy nienawidzπ tych kwaitÛw. Najlepsza forma na ich odstraszenie.")<<endl;
                    Sleep(3000);
                        system("cls");
                    goto rozmowa3;
                break;
                case 2:
                    cout<<PL("Burmistrz - Stara legenda mÛwi o przybyciu wybraÒca z znamieniem na ramieniu, ktÛry ma nam pomÛc uwolniÊ siÍ od Alucarda.")<<endl;
                    Sleep(1000);
                    cout<<PL("Wielu juø siÍ takich pojawi≥o, wszystkich moøesz znaleüÊ na cmentarzu obok kaplicy.")<<endl;
                    Sleep(3000);
                        system("cls");
                    goto rozmowa3;
                break;
                case 3:
                    cout<<PL("Burmistrz - Wampir przebywajπcy w kaplicy, wybudzi≥ siÍ z stu letniego odpoczynku i terroryzuje miasto.")<<endl;
                    Sleep(1000);
                    cout<<PL("Wed≥ug starej legendy ma przybyÊ wybraniec z znamieniem na ramieniu i z powrotem wys≥aÊ go na kolejnπ drzemkÍ.")<<endl;
                    Sleep(1000);
                    cout<<PL("Wielu juø siÍ takich pojawi≥o, kaødy skoÒczy≥ jako jego posi≥ek.")<<endl;
                    Sleep(1000);
                    Sleep(3000);
                        system("cls");
                    goto rozmowa3;
                break;
                case 4:
                    if ((wybor[5]==2)||(wybor[5]>=4))
                    {
                    cout<<PL("Anna - Wybacz lecz nie wywiπza≥eú siÍ z obowiπzku...nie mogÍ ci zap≥aciÊ.")<<endl;
                    Sleep(2500);
                        system("cls");
                    goto rozmowa3;
                    }
                    else if ((wybor[5]==1)||(wybor[5]==3))
                    {
                        cout<<PL("Anna - Naleøa≥ do poprzedniego burmistrza, mojego ojca. MÛwi≥ øe mam go daÊ wybraÒcowi aby pomÛc mu pozbyÊ siÍ z≥a...")<<endl;
                        Sleep(2500);
                        system("cls");
                        goto rozmowa3;
                    }
                break;
                case 5:
                    cout<<PL("*Øegnasz siÍ z burmistrzem i Annπ odchodzπc w przeciwnym kierunku.*")<<endl;
                    Sleep(2000);
                        system("cls");
                    break;
                default:
                    cout<<PL("Nie ma wiÍcej opcji, wybierz jeszcze raz.")<<endl;
                    Sleep(1000);
                        system("cls");
                    goto rozmowa3;
                break;
                }//Koniec pierwszej po≥owy historii


    cout<<PL("Rozmyúlajπc o wampirze i przepowiedni w≥Ûczy≥eú siÍ bez celu po mieúcie, nie majπc zielnego pojÍcia co ze sobπ teraz zrobiÊ.")<<endl;
    cout<<PL("Juø dawno zasz≥o s≥oÒce, a na ulicach by≥o coraz mniej ludzi. Idπc tak bez celu zawÍdrowa≥eú pod karczmÍ.")<<endl;
    cout<<PL("Przeszuka≥eú kieszenie, na szczÍúcie znalaz≥eú trochÍ z≥otych monet. Biorπc g≥eboki oddech pchnπ≥eú drzwi i wszed≥eú do úrodka.")<<endl;
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
        cout<<PL("*Podszed≥eú do baru, po≥oøy≥eú na stole monety proszπc mÍøczyznÍ stojπcego za ladπ o posi≥ek i coú do picia.*")<<endl;
        cout<<PL("Ten wziπ≥ monety i kaza≥ ci poczekaÊ, kilka minut pÛüniej siedzia≥eú jedzπc ciep≥π zupe i popijajπc jπ piwem.")<<endl;
        cout<<PL("W miÍdzy czasie nas≥uchiwa≥eú rozmÛw ludzi wokÛ≥, jednak nic nie zwrÛci≥o twojej szczegÛlnej uwagi.")<<endl;
        cout<<PL("Kiedy juø mia≥eú wychodziÊ do karczmy wpad≥ zdyszany mÍøczyzna, krzyknπ≥ do kelnera aby ten poda≥ mu kufel piwa")<<endl;
        cout<<PL("po czym usadowi≥ siÍ na krzeúle obok Ciebie.")<<endl;
        cout<<PL("Zauwaøy≥eú øe owa osoba ma poszarpane ca≥e ramie z ktÛrego sπczy siÍ krew.")<<endl;
        rozmowa4:
            cout<<PL("1.Jest Pan ranny...")<<endl;
            cout<<PL("2.Co siÍ Panu sta≥o?")<<endl;
            cout<<PL("3.*Nic nie mÛwisz, wpatrujesz siÍ tylko w ranÍ.*")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Co mÛwisz?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cin>>wybor[8];
                    switch (wybor[8])
                    {
                    case 1:
                        system("cls");
                        cout<<PL("MÍøczyzna - Do wesela siÍ zagoi. *Wypija na raz kufel piwa podany przez kelnera.*")<<endl;
                    break;
                    case 2:
                        system("cls");
                            cout<<PL("MÍøczyzna - Nie twÛj interes m≥ody.")<<endl;
                    break;
                    case 3:
                        system("cls");
                            cout<<PL("MÍøczyzna - Co siÍ tak lampisz?")<<endl;
                    break;
                    default:
                            cout<<PL("Nie ma wiÍcej opcji dialogowych. Wybierz jeszcze raz.")<<endl;
                            Sleep(2000);
                            system("cls");
                            goto rozmowa4;
                    break;
                    }

            cout<<PL("Ch≥odny ton oraz podejúcie sπsiada sprawi≥o øe jeszcze szybciej chcia≥eú opuúciÊ karczmÍ.")<<endl;
            cout<<PL("Jednak zacisnπ≥eú zÍby i wyciπgnπ≥eú z kieszeni opatrunek.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Jeúli Pan pozwoli mogÍ Pana opatrzyÊ...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Ten widocznie wkurzony twoim natrÍctwem odwrÛci≥ siÍ prosto do Ciebie chcπc kazaÊ Ci siÍ odwaliÊ. Lecz dostrzeg≥ znamiÍ.")<<endl;
            cout<<PL("Pyrchnπ≥ tylko i odpowiedzia≥ abyú robi≥ co chcesz.")<<endl;
            cout<<PL("Prze≥knπ≥eú gulÍ w gardle i zabra≥eú siÍ do opatrywania.")<<endl;
            cl();
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("KILKA MINUT P”èNIEJ")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("*SkoÒczy≥eú opatrywanie ramienia nieznajomego.*")<<endl;
            cout<<PL("MÍøczyzna - Jestem Iwan, wybacz za tak ch≥odny poczπtek i dziÍki za pomoc. EXP+75")<<endl;
            exp=exp+75;
            if ((wybor[5]==2)||(wybor[5]==4))
            {
                if (exp==150);
                {
                    lvl++;
                    cout<<PL("Gratulacje uzyska≥eú kolejny level!Poziom: ")<<lvl<<endl;
                    exp=0;
                }
            }
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("W takim razie Iwan powiesz mi kto ciÍ tak za≥atwi≥?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Iwan - Wilki. W lesie za miastem jest ich pe≥no. Chcia≥em na nie zapolowaÊ, ale zawsze chodzπ ca≥ym stadem. Cudem im uciek≥em.")<<endl;
            cout<<PL("*Do rozmowy do≥πczy≥ siÍ kelner, ktÛry przechodzi≥ obok.*")<<endl;
            cout<<PL("Kelner - Pff tak o wilki ci na pewno chodzi≥o. Wcale nie o to aby podlizaÊ siÍ tej elfce.")<<endl;
            cout<<PL("Iwan - Nie wtrπcaj nosa w nie swoje sprawy kelnerzyku.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("W tym lesie mieszkajπ elfy?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Kelner - Kiedyú moøe i tak, ale gobliny i wilki siÍ ich pozby≥y, teraz zosta≥a tylko Elen.*Ch≥opak zebra≥ puste naczynia i zniknπ≥.*")<<endl;
            cout<<PL("Iwan - Zgaduje øe jesteú tu pierwszy dzieÒ, jak chcesz moøesz przenocowaÊ u mnie panie wybraniec.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Jestem ")<<nick<<PL(". MÛw mi po imieniu. I z chÍciπ skorzystam z twojej oferty.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("*Iwan zap≥aci≥ za piwo i wyszliúcie z karczmy. Po paru minutach drogi w ciszy doszliúcie na skraj miasta.")<<endl;
            cout<<PL("Nowy znajomy otworzy≥ drzwi do starego drewnianego domu, wszed≥eú do niego zaraz po nim.*")<<endl;
            cout<<PL("Iwan - to nie luksusowy pa≥ac, ale chyba jako podziÍkowanie za opatrunek ujdzie?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Jak najbardziej, ratujesz mnie przed nocπ pod go≥ym niebem.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Gospodarz uúmiechnπ≥ siÍ w odpowiedzi i wskaza≥ ≥Ûøko na kÛrym dane by≥o ci odpoczπÊ.")<<endl;
            cout<<PL("Kiedy tylko siÍ po≥oøy≥eú zmorzy≥ ciÍ sen.")<<endl;
            cl();
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("RANEK")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
             cout<<PL("Obudzi≥o mnie pianie kogutÛw. Wsta≥em leniwie z ≥Ûøka i spostrzeg≥em øe Iwan jeszcze úpi na kanapie obok.")<<endl;
             cout<<PL("Wczorajsza rozmowa o lesie i elfach podsunÍ≥a mi pomys≥ gdzie mogÍ znaleúÊ radÍ co mam robiÊ jako wybraniec.")<<endl;
             cout<<PL("Znalaz≥em kawa≥ek kartki z atramentem i zapisa≥em gospodarzowi wiadomoúÊ, øe wybieram siÍ do lasu porozmawiaÊ z Elen.")<<endl;
            cl();
            cout<<PL("GRATULACJE UKO—CZY£Eå PIERWSZY ROZDZIA£ HISTORII!")<<endl;
            historia++;
            goto lokacje;
            }
            if (historia>0)
            {
                cout<<PL("Juø ukoÒczy≥eú ten rozdzia≥.")<<endl;
                goto lokacje;
            }
            break;

     case 2:
        if ((lvl>=2)&&(historia==1))
        {
            cout<<PL("Jak najciszej opuúci≥eú lokum Iwana i skierowa≥eú swoje kroki w stronÍ lasu.")<<endl;
            cout<<PL("Podczas drogi obserwowa≥eú jak miasto budzi siÍ do øycia.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("P”£ GODZINY P”èNIEJ")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Doszed≥eú wreszcie do lasu, wszÍdzie by≥y tabliczki ostrzegajπce przed watahπ.")<<endl;
            cout<<PL("Zaczπ≥eú siÍ zastanawiaÊ jak wielki jest ten las.")<<endl;
            cout<<PL("Westchnπ≥eú tylko i zaczπ≥eú iúÊ przed siebie majπc nadziejÍ øe szybko odnajdziesz elfkÍ.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cl();
            cout<<PL("JAKIå CZAS P”èNIEJ")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Chodzi≥eú po lesie szukajπc jakichkolwiek úladÛw elfki, ale nic nie mog≥eú znaleüÊ.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("A mog≥em zapytaÊ Iwana o drogÍ lub cokolwiek...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("*Usiad≥eú zrezygnowany pod najbliøszym drzewem odk≥adajπc broÒ na bok, pusty øo≥πdek zaczπ≥ dawaÊ o sobie znak.*")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Mog≥em teø iúÊ coú kupiÊ na úniadanie...Eh chyba lepiej bÍdzie wracaÊ...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("*Kiedy chcia≥eú siÍ podnieúÊ kπtem oka wy≥apa≥eú ruch w pobliskich krzakach.*")<<endl;
            getch();
            if (wybor[0]==1)
            {
                cout<<PL("*Wstajπc chwyci≥eú za ≥uk i wymierzy≥eú strza≥π w krzaki.*")<<endl;
            }
            else if(wybor[0]==2)
            {
                cout<<PL("*Wstajπc chwyci≥eú za miecz i tarczÍ przyjmujπc pozycjÍ do obrony.*")<<endl;
            }
            else if (wybor[0]==3)
            {
                cout<<PL("*Jakimú cudem w kieszeni mia≥eú kolejne fiolki. Wyciπgnπ≥eú jednπ celujπc w krzaki.*")<<endl;
            }
            cout<<PL("Serce bi≥o ci jak szalone, lecz stara≥eú siÍ zachowaÊ spokÛj.")<<endl;
            cout<<PL("Po chwili krzaki znÛw siÍ poruszy≥y i zobaczy≥eú parÍ oczu skupionych na Tobie.")<<endl;
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
        cout<<PL("Powoli z opuszczonym ≥bem szczerzπc k≥y z zaroúli wyszed≥ wilk.")<<endl;
        cout<<PL("Ca≥y czas oboje bacznie siÍ obserwowaliúcie oczekujπc jakiegokolwiek ruchu przeciwnika.")<<endl;
        cout<<PL("Musia≥eú przyznaÊ øe zwierzÍ wyglπda≥o naprawÍ olúniewajπco, pierwszy raz widzia≥eú wilka z tak ciekawym ubarwieniem futra i bystrymi oczami.")<<endl;
        cout<<PL("Badajπc jego wyglπd spostrzeg≥eú rannπ ≥apÍ zwierzÍcia. Najpewniej po k≥usowniczej pu≥apce. Mimo wszystko zrobi≥o ci siÍ go szkoda.")<<endl;
        cout<<PL("Niestety opuúci≥eú przez to lekko gardÍ, wilk widzπc to nastroszy≥ siÍ warczπc.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Chwila...Iwan mÛwi≥ øe chodzicie stadem...Zostawili ciÍ przez ranÍ?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("ZwierzÍ zdawa≥o siÍ rozumieÊ co mÛwisz i przesta≥o warczeÊ.")<<endl;
        cout<<PL("Nie chcia≥eú go zabijaÊ...strach i niepokÛj teø odesz≥y, chcia≥eú mu pomÛc.")<<endl;
        cl();
        if (wybor[0]==1)
            {
                cout<<PL("*Opuúci≥eú ≥uk i powoli usiad≥eú z powrotem pod drzewem.*")<<endl;
            }
            else if(wybor[0]==2)
            {
                cout<<PL("*Powoli od≥oøy≥eú tarcze i tak samo ostroønie usiad≥eú ponownie pod drzewem.*")<<endl;
            }
            else if (wybor[0]==3)
            {
                cout<<PL("*Schowa≥eú fiolkÍ i powoli usiad≥eú pod drzewem.*")<<endl;
            }
            cout<<PL("ZwierzÍ uwaønie obserwowa≥o twoje ruchy szukajπc w nich podstÍpu.")<<endl;
            cout<<PL("Odnalaz≥eú w kieszeni ostatni kawa≥ek bandaøa.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Nie chcÍ ciÍ skrzywdziÊ...chce ci tylko pomÛc...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Wilk przechyli≥ ≥eb w lewo chowajπc k≥y.")<<endl;
            cout<<PL("Odrzuci≥eú broÒ jeszcze dalej i wyciπgnπ≥eú przed siebie d≥oÒ.")<<endl;
            cout<<PL("ZwierzÍ zaczÍ≥o nieufnie podchodziÊ, kiedy stanπ≥ przed twojπ d≥oniπ serce ci stanÍ≥o myúlπc, øe zaraz jπ stracisz.")<<endl;
            cout<<PL("Jednak wilk poliza≥ ciÍ tylko po niej i usiad≥ naprzeciwko Ciebie wysuwajπc do przodu rannπ ≥apÍ.")<<endl;
            cout<<PL("Najdelikatniej jak tylko umai≥eú zajπ≥eú siÍ opatrywaniem jej, ca≥y czas jednak majπc siÍ na bacznoúci.")<<endl;
            cl();
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("CHWILA P”èNIEJ")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Kiedy skoÒczy≥eú, poczu≥eú øe ktoú cie obserwujÍ. Dyskretnie zbada≥eú wzrokiem teren. Za jednym z drzew dostrzeg≥eú postaÊ.")<<endl;
            cout<<PL("Wilk nagle wsta≥ i rzuci≥ siÍ na Ciebie, przewracajπc ciÍ na ziemiÍ.")<<endl;
            cout<<PL("Szykowa≥eú siÍ poczuÊ bÛl, ale za to zwierzÍ zaczÍ≥o ciÍ lizaÊ po twarzy.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Nastraszy≥eú mnie...a chcia≥eú tylko podziÍkowaÊ.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Pog≥aska≥eú wilka po grzbiecie, ten zszed≥ z Ciebie i usiad≥ obok.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("A ty kimkolwiek jesteú moøesz sie pokazaÊ, wiem øe nas obserwujesz.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Z krzakÛw na úrodek ma≥ej polanki na ktÛrej byliúcie wysz≥a zakapturzona postaÊ.")<<endl;
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
        cout<<PL("? - Jestem Elena, wiatr przekaza≥ mi øe ciÍ tu znajdÍ...Myúla≥am øe bÍdziesz kolejnym podrabiaÒcem, ale nie...")<<endl;
        cout<<PL("Jesteú prawdziwym wybraÒcem...ChoÊ za mnπ, drzewa majπ uszy. Wszystko ci wyjaúniÍ obiecujÍ.")<<endl;
        cl();
        cout<<PL("Wsta≥eú z ziemi, Elena odwrÛci≥a siÍ i zaczÍ≥a odchodziÊ. Spojrza≥eú na wilka, ten trwa≥ przy twoim boku.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Czyli co..zostajesz moim kompanem?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Wilk pokiwa≥ ≥bem w gÛrÍ i w dÛ≥ i ruszy≥ za Elenπ. Zebra≥eú swojπ broÒ z ziemi i rÛwnieø ruszy≥eú w úlad za elfkπ.")<<endl;
        cout<<PL("Po kilku minutach drogi przez zaroúla doszliúcie nad rzekÍ. Elena podesz≥a do wielkiego kamienia leøπcego na brzegu.")<<endl;
        cout<<PL("Nakreúli≥a rÍkπ jakieú znaki i nagle pojawi≥y siÍ drzwi.")<<endl;
        cout<<PL("Elena - Zapraszam.")<<endl;
        cout<<PL("Wraz z nowym towarzyszem spojrzeliúcie na siebie i weszliúcie do úrodka.")<<endl;
        cout<<PL("Wewnπtrz by≥o naprawdÍ przytulnie, jak w zwyk≥ym domu. Elena zamknÍ≥a za wami drzwi, ktÛre w momencie zamkniÍcia zniknÍ≥y.")<<endl;
        cout<<PL("Elena - årodki bezpieczeÒstwa, a teraz siadajcie zrobiÍ wam coú do jedzenia.")<<endl;
        cout<<PL("Usiad≥eú przy stole a wilk po≥oøy≥ siÍ pod twoim krzes≥em.")<<endl;
        cout<<PL("Elena krzπta≥a siÍ po ma≥ej kuchni robiπc sa≥atkÍ i zio≥owπ herbatÍ.")<<endl;
        cout<<PL("Elena - Wybra≥eú juø imiÍ?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("S≥ucham?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Elena - No imiÍ, dla niego. *Wskaza≥a na odpoczywajπcego wilka.*")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Ah nie...jeszcze nie.")<<"";
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("*Spojrza≥eú na zwierzaka zastanawiajπc siÍ co tu siÍ dzieje.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Nero, nazwÍ go Nero.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Elena - åwietnie, jemu teø zdaje siÍ pasowaÊ. *MÛwiπc to po≥oøy≥a przed Nero miskÍ z miÍsem.*")<<endl;
        cout<<PL("Przed Tobπ pojawi≥a siÍ miska pe≥na sa≥atki i kubek gorπcej herbaty* Jedzcie, musicie nabraÊ si≥. ")<<endl;
        cout<<PL("*MÛwiπc to usiad≥a naprzeciwko Ciebie uúmiechajπc siÍ.* Oh spokojnie zaraz ci wszystko wyjaúniÍ.")<<endl;
        cout<<PL("By≥eú naprawdÍ g≥odny, po 5 minutach po sa≥atce nie by≥o úladu. Nero teø skoÒczy≥ swojπ porcjÍ.")<<endl;
        cout<<PL("Pusta miska i talerz zniknÍ≥y, a Elena w koÒcu mog≥a rozwiaÊ wszystkie wπtpliwoúci.")<<endl;

        cout<<PL("Elena - Z tego co mi wiadomo znasz juø przepowiedniÍ i wiesz kim jest Alucard, prawda?")<<endl;
        rozmowa5:
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Czy chcesz jeszcze raz us≥yszeÊ przepowiedniÍ?1.Tak 2.Nie")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cin>>wybor[9];
            if (wybor[9]==1)
            {
                system("cls");
                cout<<PL("Alucard, wampir ktÛry spa≥ pod naszym miastem przebudzi≥ siÍ jakiú czas temu.")<<endl;
                cout<<PL("Zaczπ≥ terroryzowaÊ wioskÍ i mieszkaÒcÛw, potwory przez niego zacze≥y szaleÊ.")<<endl;
                cout<<PL("Legenda o wampirze jednak zawiera teø element o wybraÒcu, ktÛry go pokona.")<<endl;
                cout<<PL("Nosi on na ramieniu znamiÍ swojej profesji.")<<endl;
            }
            else if (wybor[9]==2)
            {
                system("cls");
             cout<<PL("Dobrze, wiÍc mogÍ przejúÊ do dalszej czÍúci.")<<endl;
            }
            else if (wybor[9]>2)
            {
                cout<<PL("Moøesz wybraÊ tylko tak lub nie.")<<endl;
                Sleep(1000);
                system("cls");
                goto rozmowa5;
            }
            cout<<PL("Jednak nikt nie wie, øe wersja ogÛlnie znana to nie ca≥a przepowiednia...Poprzedni burmistrz zatai≥ najwaøniejszπ czÍúÊ.")<<endl;
            cout<<PL("Aby umieÊ rozrÛøniÊ podrÛbki od prawdziwego wybraÒca.")<<endl;
            cout<<PL("Wybraniec musi mieÊ czyste serce, wedle przepowiedni kiedy spotka na swej drodze rannego czy to wroga czy przyjaciela zawsze go opatrzy.")<<endl;
            cout<<PL(R"(*Elena przenios≥a wzrok na Nero. *Kaødy poprzedni ,,wybraniec" chcia≥ skrzywdziÊ rannego wilka, ktÛrego los mu zsy≥a≥.)")<<endl;
            cout<<PL("Jesteú pierwszym ktÛry pomÛg≥...jesteú prawdziwym wybraÒcem. Nie podrÛbkπ szukajπca chwa≥y.")<<endl;
            exp=exp+250;
            if (exp==250);
                {
                    lvl++;
                    cout<<PL("Gratulacje uzyska≥eú kolejny level!Poziom: ")<<lvl<<endl;
                    exp=0;
                }
            cout<<PL("*Nero po≥oøy≥ g≥owÍ na twoich kolanach widocznie szczÍúliwy.*")<<endl;
            cout<<PL("Elena - Gdybyú go zabi≥, musia≥byú siÍ zmierzyÊ z ca≥a watahπ. Inaczej nie zdoby≥byú tego czego potrzebujesz do walki.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("A czego potrzebujÍ?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Ponownie pojawi≥y siÍ drzwi przez ktÛre teraz wszed≥ Iwan...lecz z jednπ rÛønicπ, mia≥ elfie uszy.")<<endl;
            cout<<PL("Iwan - Mam nadziejÍ øe nie gniewasz siÍ øe nie powiedzia≥em nic o byciu elfem?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Nie no, rozumiem øe chcieliúcie mnie sprawdziÊ.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Elfy uúmiechnÍ≥y siÍ w odpowiedzi, Iwan wyciπgnπ≥ zza plecÛw wielki miecz.")<<endl;
            cout<<PL("Elena - Skarb, ktÛrego strzeøe wataha. Musia≥byú odebraÊ to si≥π jak reszta, ale pomog≥eú przywÛdcy. Wataha wiÍc oddaje ci to jako prezent.")<<endl;
            cl();
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("PrzywÛdcy?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Elena - Tak, Nero to alfa stada a teraz teø twÛj towarzysz w dalszej wyprawie.")<<endl;
            cout<<PL("Nie zostawili go bo by≥ ranny jak za≥oøy≥eú.")<<endl;
            cout<<PL("Kaza≥ reszcie pilnowaÊ skarbu a sam wyszed≥ skonfrontowaÊ siÍ z Tobπ.")<<endl;
            cout<<PL("*Pog≥aska≥eú wilka i odebra≥eú przedmioty od Iwana.*")<<endl;
            hp=hp+15;
            cout<<"HP="<<hp<<endl;
            str=str+20;
            cout<<PL("Si≥a=")<<str<<endl;
            dex=dex+10;
            cout<<PL("ZrÍcznoúc=")<<dex<<endl;
            cout<<PL("Elena - Jesteú teraz gotowy na starcie z potworami kopalni.")<<endl;
            cout<<PL("Po podwyøszeniu waszych umiejÍtnoúci w trakcie walki z nimi bÍdziecie w stanie walczyÊ z Alucardem.")<<endl;
            cout<<PL("Jest tam teø przedmiot ktÛry musisz obowiπzkowo zabraÊ.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Jaki przedmiot?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Elena - Dowiesz siÍ kiedy go odnajdziesz,szukaj skrzyni z znakiem jak twoje znamiÍ.")<<endl;
            cout<<PL("A teraz ruszajcie, aby dotrzeÊ do niej zanim zajdzie s≥oÒce.")<<endl;
            cout<<PL("*Elena da≥a ci pe≥no jedzenia oraz bandaøy.*")<<endl;
            cout<<PL("Poøegna≥eú siÍ z elfami i razem z Nero opuúci≥eú mieszkanie w g≥azie.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("No to teraz czeka nas d≥ugi spacer, co towarzyszu?")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Nero tylko pomacha≥ ogonem i ruszy≥ przodem prowadzπc ciÍ do kolejnej lokalizacji.")<<endl;
            cl();
            cout<<PL("GRATULACJE UKO—CZY£Eå DRUGI ROZDZIA£ HISTORII!")<<endl;
            cout<<PL("Zdoby≥eú rÛwnieø kompana.")<<endl;
            cout<<PL("Statystki Nero: ")<<endl;
            cout<<PL("Øycie=")<<hpn<<endl;
            cout<<PL("Si≥a=")<<strn<<endl;
            cout<<PL("SzybkoúÊ=")<<fn<<endl;
            historia++;
            goto lokacje;
        }
        else if(lvl<2)
        {
            cout<<PL("Nie moøesz wejúÊ, za ma≥y poziom. Wybierz jeszcze raz.")<<endl;
            goto lokacje;
        }
        else if (historia>1)
            {
                cout<<PL("Juø ukoÒczy≥eú ten rozdzia≥.")<<endl;
                goto lokacje;
            }
        break;//Koniec 2 rozdzia≥u

    case 3:
        if ((lvl>=3)&&(historia==2))
        {
          cout<<PL("Na miejsce dotarliúcie po zmroku, okaza≥o siÍ øe krÛtka drzemka w po≥owie drogi okaza≥a siÍ d≥uøszπ przerwπ.")<<endl;
          cout<<PL("Zebra≥eú patyki aby rozpaliÊ ognisko na pobliskiej polanie, nie chcia≥eú wchodziÊ do kopalni nocπ.")<<endl;
          cout<<PL("Nero pilnowa≥ torby z zapasami, ca≥y czas obserwujπc twoje prÛby rozpalenia ognia, ktÛre nie sz≥y za dobrze.")<<endl;
          cout<<PL("Wilk wsta≥, poszed≥ w kierunku krzakÛw a po chwili wrÛci≥ z patykiem w pysku.")<<endl;
          cout<<PL("Bez s≥owa wziπ≥eú go od towarzysza i magicznie dziÍki niemu uda≥o siÍ w koÒcu rozpaliÊ ogieÒ.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cout<<PL("DziÍki, zas≥uøy≥eú na coú dobrego na kolacje.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("*Pog≥aska≥eú wilka i poda≥eú mu z torby kawa≥ek miÍsa.* Elena uøy≥a jakiú tam czary mary aby nie popsu≥o siÍ w trakcie drogi.")<<endl;
          cout<<PL("Wilk ucieszony zabra≥ jedzenie i usadowi≥ siÍ w bezpiecznej odleg≥oúci od ogniska zaczynajπc jeúÊ.")<<endl;
          cout<<PL("Poszed≥eú w úlady towarzysza i wyjπ≥eú bochenek chleba.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cl();
          cout<<PL("RANEK")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("Nero obudzi≥ cie warczeniem, nawet nie wiedzia≥eú kiedy poprzedniego wieczora zasnπ≥eú.")<<endl;
          cout<<PL("Chwyci≥eú za broÒ i szybko wsta≥eú...jednak polana by≥a pusta.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cout<<PL("Chcia≥eú mnie tylko obudziÊ?")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("ZwierzÍ ruchami ≥ba potwierdzi≥o twoje stwierdzenie.")<<endl;
          cout<<PL("Westchnπ≥eú tylko i zaczπ≥eú zbieraÊ rzeczy aby wyruszyÊ.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cout<<PL("TIME SPEEK")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("StanÍliúcie przed wejúciem do opuszczonej kopalni. ZaczÍ≥y nachodziÊ ciÍ wπtpliwoúci czy to aby na pewno dobry pomys≥...")<<endl;
          cout<<PL("Lecz teraz nie by≥o juø odwrotu. Wziπ≥eú g≥Íboki oddech i przekroczy≥eú stary drewniany prÛg.")<<endl;
          cout<<PL("Na pod≥odze leøa≥y stare lampy naftowe, wziπ≥eú jednπ i nape≥ni≥eú naftπ od Eleny.")<<endl;
          cout<<PL("Teraz juø w 100% gotowi mogliúcie ruszyÊ dalej.")<<endl;
          cl();
          cout<<PL("Po kilku minutach podrÛøy w dÛ≥ g≥Ûwnym korytarzem doszliúcie do rozwidlenia.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cout<<PL("W ktÛrπ stronÍ?")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("Nero wystrzeli≥ jak z procy w prawo. Pobieg≥eú za nim nie rozumiejπc co go ugryz≥o i nagle tak siÍ zachowa≥.")<<endl;
          cout<<PL("Niestety ale zaraz po tym Nero zniknπ≥ w d≥ugim ciemnym korytarzu.")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
          cout<<PL("NERO!!")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("Nawo≥ywa≥eú wilka lecz ten juø dawno zniknπ≥ z twojego pola widzenia.")<<endl;
          cout<<PL("Po chwili dotar≥eú do kolejnego rozwidlenia.")<<endl;
          korytarze1:
          SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("W ktÛrπ stronÍ chcesz siÍ udaÊ?1.Lewy korytarz 2.Prawy korytarz")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cin>>wybor[10];//labirynt
          if(wybor[10]==1)
          {
              system("cls");
              cout<<PL("Poszed≥eú w lewo, po kilku minutach drogi prostym korytarzem nagle nastπpi≥eú na dziwny kamieÒ, ktÛry pod ciÍøarem ")<<endl;
              cout<<PL("twojego nacisku ods≥oni≥ wielkπ zapadniÍ w ziemi z kolcami na dnie.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
              cout<<PL("Elena nie mÛwi≥a o pu≥apkach...oby Nero w øadnπ nie wpad≥.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
              cout<<PL("Kiedy zabra≥eú nogÍ z kamienia zapadnia siÍ zamknÍ≥a.")<<endl;
              cout<<PL("Powoli i ostroønie przeszed≥eú na drugi koniec uwaønie teraz obserwujπc gdzie stajesz.")<<endl;
              cout<<PL("Po d≥uøszej chwili drogi doszed≥eú do kolejnego rozwidlenia.")<<endl;
          }
          else if (wybor[10]==2)
          {
              system("cls");
              cout<<PL("Poszed≥eú w prawo, po d≥uøszej chwili drogi prostym korytarzem doszed≥eú do kolejnego rozwidlenia.")<<endl;
          }
        else if (wybor[10]>2)
        {
            cout<<PL("Moøesz wybraÊ tylko lewo lub prawo.")<<endl;
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
              cout<<PL("Poszed≥eú w lewo, po d≥uøszej chwili drogi stwierdzi≥eú øe czas na krÛtkπ przerwÍ.")<<endl;
          }
          else if (wybor[11]==2)
          {
              system("cls");
              cout<<PL("Szed≥eú spokojnie prawym korytarzem, aø us≥ysza≥eú czyjeú kroki.")<<endl;
              cout<<PL("Z kaødπ chwilπ stawa≥y siÍ one coraz g≥oúniejsze, odstawi≥eú lampÍ na ziemiÍ i wyciπgnπ≥eú")<<endl;
              cout<<PL("miecz od Iwana przyjmujπc pozycjÍ do ataku. ")<<endl;
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
        if (d==0) {cout<<PL("Nagle z ciemnoúci wy≥oni≥a siÍ postaÊ przypominajπca smoka, rzuci≥a siÍ na ciebie.")<<endl;
        cout<<PL("Statystyki przeciwnika:")<<endl;
        cout<<PL("Øycie: ")<<hps<<endl;
        cout<<PL("Si≥a: ")<<sila<<endl;}
        srand(time(NULL));
        dms=rand()%10;
        hp=hp-dms;
        cout<<PL("Zdrowie: ")<<hp<<endl;
        cout<<PL("Otrzymane obraøenia: ")<<dms<<endl;
        Sleep(1000);
        cout<<endl;
        if (hp<0)
        {
            cout<<PL("Nie øyjesz.")<<endl;
            goto death;
        }
        if (d==0)
        {
            cout<<PL("Oberwa≥eú w ramiÍ, monstrum wbi≥o ci w nie szpony.")<<endl;
            cout<<PL("Uøy≥eú miecza i wbi≥eú go za to w bok potwora.")<<endl;
            Sleep(2000);
            d++;
        }

        else if(d==1)
        {
            cout<<PL("Monstrum chwyci≥o drugπ rÍkπ za ostrze miecza wyciπgajπc go z rany i odrzucajπc na bok.")<<endl;
            cout<<PL("Straci≥eú miecz, pozosta≥a ci tylko walka na pieúci.")<<endl;
            Sleep(2000);
            d++;
        }
        else if(d==2)
        {
            cout<<PL("Starcie by≥o teraz tylko unikami i wymiana ciosÛw miÍdzy wami.")<<endl;

            d++;
        }
        srand(time(NULL));
        dmg=rand()%15;
        hps=hps-dmg;
        cout<<endl;
        cout<<PL("Zdrowie przeciwnika: ")<<hps<<endl;
        cout<<PL("Zadane obraøenia: ")<<dmg<<endl;
        if (hps<0)
        {
            cout<<PL("Zabi≥eú potwora.")<<endl;
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
        cout<<PL("Omijasz martwego przeciwnika, zbierasz z ziemi swÛj miecz i siadasz pod úcianπ.")<<endl;
        cout<<PL("Wyciπgasz z torby bandaøe od Elen i opatrujesz rany.")<<endl;
        hp=hp+25;
        cout<<"Zdrowie: "<<hp<<endl;
          }
           else if (wybor[11]>2)
        {
            cout<<PL("Moøesz wybraÊ tylko lewo lub prawo.")<<endl;
            goto korytarze2;
        }
        if (wybor[11]==2)
    {
        cout<<PL("Ponownie s≥yszysz øe ktoú biegnie w twojπ stronÍ. Wstajesz szybko z ziemi bÍdπc gotowy do kolejnej walki.")<<endl;
        cout<<PL("Lecz z ciemnoúci korytarza wy≥ania siÍ Nero.")<<endl;
        cout<<PL("Opuszczasz bron i wzdychasz. ")<<endl;
        cl();
    }
        else if (wybor[11]==1)
    {
        cout<<PL("S≥yszysz øe ktoú biegnie w twojπ stronÍ. Wstajesz szybko z ziemi wyciπgajπc miecz.")<<endl;
        cout<<PL("Lecz z ciemnoúci korytarza wy≥ania siÍ Nero.")<<endl;
        cout<<PL("Opuszczasz bron i wzdychasz.")<<endl;
    }
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Najpierw mnie zostawiasz a teraz nagle wracasz, tak siÍ nie robi stary.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Wilk jednak ochoczo podchodzi do Ciebie trzymajπc coú w pysku.")<<endl;
        cout<<PL("Przyjmujesz przedmiot od towarzysza, okazuje siÍ øe to mapa!")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("HAHA, úwietnie nie bÍdziemy musieli b≥πdziÊ po tych korytarzach.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Na mapie by≥y zarÛwno oznaczone pu≥apki jak i skrÛty dziÍki ktÛrym bÍdzie moøna omijaÊ korytarze z potworami. ")<<endl;
        cout<<PL("Wyciπgnπ≥eú z torby ostatni kawa≥ek miÍsa i da≥eú Nero.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Dobrze siÍ spisa≥eú przyjacielu, wybacz za wczeúniej.")<<endl;
        cout<<PL("Skoro mamy mapÍ myúlÍ, øe moøemy chwilÍ odpoczπÊ.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Jakiú czas pÛüniej")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("DziÍki mapie wasza podrÛø przez kopalnie posz≥a o wiele szybciej, ominÍliúcie wszystkie pu≥apki oraz potwory.")<<endl;
        cout<<PL("Obecnie szliúcie ostatnim prostym korytarzem, ktÛry mia≥ was zaprowadziÊ do pomieszczenia w ktÛrym znajduje siÍ")<<endl;
        cout<<PL("przedmiot wed≥ug Elen bardzo ci potrzebny. Jednak stanÍliúcie na kolejnym rozwidleniu.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Na mapie nie ma juø øadnej drogi...Tu powinna byÊ wielka pusta sala.")<<endl;
        cout<<PL("Eh musimy ponownie wybraÊ...")<<"";
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("*Patrzysz na Nero. Ten skupiony raz spoglπda na lewo raz na prawo.*")<<endl;
        cout<<PL("Ostatecznie podchodzi do prawego korytarza, a potem spoglπda na Ciebie.")<<endl;
        korytarze3:
          SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );
          cout<<PL("KtÛry korytarz wybierasz?1.Lewy 2.Prawy")<<endl;
          SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
          cin>>wybor[12];
          if(wybor[12]==1)
          {
              system("cls");
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
              cout<<PL("Rozdzielmy siÍ, jeúli ktÛreú napotka pu≥apkÍ albo przeciwnika wraca tutaj.")<<endl;
              cout<<PL("Jeden z nich musi byÊ dobry....")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
              cout<<PL("Ruszy≥eú lewym korytarzem, mia≥eú nadziejÍ øe Nero nie napotka nic w swoim korytarzu.")<<endl;
              cout<<PL("Po paru minutach drogi zaczπ≥eú myúleÊ øe trafi≥eú na pusty korytarz, jednak w momencie kiedy")<<endl;
              cout<<PL("chcia≥eú zawrÛciÊ po wilka nastπpi≥eú na jakπú p≥ytkÍ.")<<endl;
              cout<<PL("Nagle w úcianach pojawi≥y siÍ otwory, ktÛre zasypa≥y ciÍ atakiem strza≥.")<<endl;
              hp=hp-10;
              cout<<"Zdrowie: "<<hp<<endl;
              cout<<PL("Oberwa≥eú w udo oraz obojczyk, grad strza≥ po chwili usta≥.")<<endl;
              cout<<PL("CiÍøko dyszπc siadasz na ziemi, mocno krwawisz. Chcesz opatrzyÊ rany lecz...")<<endl;
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
              cout<<PL("Pojawia siÍ kolejny ,,smok'', nie masz czasu siÍ opatrzyÊ wstajesz pomimo bÛlu i wyjmujesz miecz.")<<endl;
              cout<<PL("Statystyki przeciwnika:")<<endl;
                cout<<PL("Øycie: ")<<hps1<<endl;
                cout<<PL("Si≥a: ")<<sila<<endl;
              while ((hp>=0)||(hps>=0))
    {

        if (d1==0)
        {
        srand(time(NULL));
        dms=rand()%10;
        hp=hp-dms;
        cout<<PL("Zdrowie: ")<<hp<<endl;
        cout<<PL("Otrzymane obraøenia: ")<<dms<<endl;
        Sleep(1000);
        cout<<endl;
        if (hp<0)
        {
            cout<<PL("Nie øyjesz.")<<endl;
            goto death;
        }
            cout<<PL("Przeciwnik wbieg≥ w Ciebie z impetem posy≥ajπc ciÍ na najbliøszπ úcianÍ.")<<endl;
            cout<<PL("Zda≥eú sobie sprawÍ øe nie masz szans...W tym starciu przegrasz.")<<endl;
            cout<<PL("Kiedy potwÛr mia≥ zadaÊ cios rzuci≥ siÍ na niego Nero, gryzπc go w ≥ydkÍ.")<<endl;

        }

        if(d1==1)
        {
            cout<<PL("PotwÛr kompletnie straci≥ zainteresowanie Tobπ skupi≥ siÍ na pozbyciu siÍ Nero.")<<endl;
            cout<<PL("Ten jednak by≥ szybszy i unika≥ ciosÛw przeciwnika, a w miÍdzy czasie go gryzπc")<<endl;
            cout<<PL("Da≥o ci to czas na opatrzenie ran.")<<endl;
            hp=hp+10;
            cout<<PL("Zdrowie: ")<<hp<<endl;

        }
         if(d1==2)
        {
            cout<<PL("Jednak w koÒcu jeden z ciosÛw trafi≥ Nero, szpony bestii rozdar≥ ca≥y grzbiet wilka.")<<endl;
            hpn=hpn-20;
            cout<<PL("Zdrowie Nero: ")<<hpn<<endl;
            cout<<PL("Widzπc to rzuci≥eú siÍ wúciek≥y na przeciwnika odcinajπc mu mieczem g≥owÍ.")<<endl;
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
        cout<<PL("Zadane obraøenia: ")<<dmg<<endl;
        potwor:
            if (hps1<0)
        {
            cout<<PL("PotwÛr pada martwy na ziemiÍ.")<<endl;
            exp=exp+150;
            goto fab1;
        }
        d1++;
        cout<<endl;
        getch();
        system ("cls");
    }
    fab1:

        cout<< PL(" Podbiegasz do Nero, ranny ciÍøko dyszy. Straci≥ duøo krwi.")<<endl;
        cout<< PL("Wyjmujesz bandaøe z fiolkami od Elen i opatrujesz towarzysza.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("BÍdzie dobrze, wyjdziesz z tego...")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<< PL("Na szczÍúcie mieszanki ziÛ≥ szybko zatamowa≥y krwawienie, opatrzy≥eú grzbiet Nero.")<<endl;
        cout<< PL("Ten tylko poliza≥ twojπ d≥oÒ i chcia≥ wstaÊ.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Oj nie nie nie...zostaÒ tutaj, pÛjdÍ po to cholerstwo i wrÛcÍ do ciebie.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<< PL("Wilk skinπ≥ ≥bem i z powrotem siÍ po≥oøy≥.")<<endl;
        cout<< PL("Pobieg≥eú dalej korytarzem, chcia≥eú jak najszybciej to zakoÒczyÊ.")<<endl;
        cout<<PL("Po paru minutach drogi dotar≥eú do wielkiej skalnej sali, pe≥nej skrzyÒ.")<<endl;
        cout<< PL("Nie mia≥eú czasu, ruszy≥eú w g≥πb sali szukajπc skrzyni z znakiem takim jak twoje znamiÍ.")<<endl;
          }
          else if (wybor[12]==2)
          {
              system("cls");
              cout<<PL("Postanawiasz zaufaÊ wilkowi, idziesz razem z nim w prawo.")<<endl;
              cout<<PL("Po paru minutach drogi wychodzicie w wielkiej skalnej sali. Pe≥nej skrzyÒ.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
              cout<<PL("Znowu mia≥eú racjÍ oraz ponownie mi pomog≥eú, dziÍkuje.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
              cout<<PL("Wilk wyszczerzy≥ k≥y jakby chcia≥ siÍ uúmiechnπÊ i ruszy≥ w g≥πb sali.")<<endl;
              cout<< PL("Ruszy≥eú za nim rozglπdajπc siÍ za skrzyniπ z znakiem takim jak twoje znamiÍ.")<<endl;
              cout<<PL("Jednak twoje poszukiwania przerwa≥o øa≥osne wycie wilka, spojrza≥eú w jego stronÍ")<<endl;
              cout<<PL("i dostrzeg≥eú na pod≥odze pe≥no od≥amkÛw szk≥a w ktÛre niestety wszed≥ wilk. ")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
              cout<<PL("Kurde...pokaø ≥apy.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
              cout<<PL("W ≥apach twÛj towarzysz ma pe≥no od≥amkÛw. Wyciπgasz z torby bandaøe z fiolkami od Elen i opatrujesz Nero.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
              cout<<PL("Nie ruszaj siÍ, znajdÍ czego potrzebujemy i wracamy.")<<endl;
              SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
              cout<<PL("Rozglπdasz siÍ ponownie po sali.")<<endl;

          }
        else if (wybor[12]>2)
        {
            cout<<PL("Moøesz wybraÊ tylko lewo lub prawo.")<<endl;
            Sleep(1000);
            system("cls");
            goto korytarze3;
        }
        cout<<PL("Dostrzeg≥eú jπ cudem w rogu sali, podbiegasz do skrzyni.")<<endl;
        if (wybor[0]==1)
        {
        cout<<PL("*Na jej wieku widnieje symbol ≥uku. Otwierasz jπ i znajdujesz ko≥czan wype≥nionymi srebrnymi strza≥ami.*")<<endl;
        }
        else if(wybor[0]==2)
        {
        cout<<PL("*Na jej wieku widnieje symbol miecza. Otwierasz jπ i znajdujesz srebrny sztylet.*")<<endl;
        }
        else if (wybor[0]==3)
        {
        cout<<PL("*Na jej wieku widnieje symbol roúliny. Otwierasz jπ i znajdujesz fiolkÍ wype≥nionπ czerwonym p≥ynem.*")<<endl;
        }

        cout<<PL("Ko≥o przedmiotu leøy zwiniÍty pergamin, zabierasz go i chowasz do torby wraz z nowπ zdobyczπ.")<<endl;
        exp=exp+100;

        if(wybor[12]==1)
        {
        cout<<PL("Zamykasz skrzynie i pÍdem wracasz do Nero.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Jak siÍ trzymasz stary?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Pytasz kiedy dobiegasz na miejsce gdzie zostawi≥eú wilka. Ten na twÛj widok siÍ oøywi≥ i wsta≥.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Czas wracaÊ, ale nie powinieneú jeszcze siÍ tak przemÍczaÊ. Zio≥a Elen zdzia≥a≥y cuda")<<endl;
        cout<<PL("ale musisz odpoczywaÊ.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("MÛwiπc to bierzesz Nero na rÍce i ruszasz w drogÍ powrotnπ.")<<endl;
        }
        else if (wybor[12]==2)
        {
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Czas wracaÊ.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("MÛwiπc to bierzesz Nero na rÍce i ruszasz w drogÍ powrotnπ.")<<endl;
        }
        cl();
        SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("JAKIå CZAS P”ØNIEJ")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("W koÒcu doszliúcie do wyjúcia, znÛw by≥a noc.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Straci≥em w tej kopalni poczucie czasu.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
       cout<<PL("WrÛci≥eú z Nero na polane na ktÛrej wczeúniej spaliúcie.")<<endl;
       cout<<PL("Delikatnie od≥oøy≥eú go na ziemiÍ i ruszy≥eú do lasu nazbieraÊ drewna.")<<endl;
       cout<<PL("Przy okazji uda≥o ci siÍ upolowaÊ dwa zajπce, idealnie na kolacjÍ.")<<endl;
       SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
       cout<<PL("CHWILA POZNIEJ")<<endl;
       SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
       cout<<PL("W trakcie kiedy wasze zajπce siÍ piek≥y w ognisku zmieni≥eú zarÛwno sobie jak i Nero bandaøe.")<<endl;
       cout<<PL("Na szczÍúcie rany dziÍki przedmiot od Elen bardzo szybko siÍ goi≥y.")<<endl;
       cout<<PL("Po zjedzonej kolacji wyciπgnπ≥eú pergamin ktÛry znalaz≥eú w skrzyni.")<<endl;
       cout<<PL(R"(
   __________________________________________________________________
 / \                                                                 \.
|   |1.Przedmiot ktÛry otrzyma≥eú jest niezbÍdny do zabicia Alucarda. |.
 \_ |2.Podnosi on twoje statystyki o 20 punktÛw.                      |.
    |3.Twoich towarzyszy w kampanii rÛwnieø, lecz o 15 punktÛw.       |.
    |4.Musisz sprytnie go uøyÊ, Alucard nie wie o jego istnieniu.     |.
    |   ______________________________________________________________|___
    |  /                                                                 /.
    \_/_________________________________________________________________/.
               )")<<endl;
    cout<<PL("Na odwrocie widnia≥ ostatni punkt.")<<endl;
      if ((wybor[0]==1)||(wybor[0]==2))
        {
        cout<<PL("*5.Srebro rani wampiry, musisz trafiÊ w jego serce aby go zabiÊ.*")<<endl;
        }
        else if (wybor[0]==3)
        {
        cout<<PL("*5.Zatruta krew, musi jπ wypiÊ.*")<<endl;
        }
        cout<<PL("Wiedzia≥eú juø co bÍdziesz robi≥ jutro. Wraz z Nero po≥oøyliúcie siÍ spaÊ.")<<endl;
        cout<<PL("Aby wypoczπÊ i byÊ gotowym na to co musi nadejúÊ.")<<endl;
        cl();
        if (exp==300);
                {
                    lvl++;
                    cout<<PL("Gratulacje uzyska≥eú kolejny level!Poziom: ")<<lvl<<endl;

                    exp=0;
                }
	    hp=hp+20;
            cout<<"HP="<<hp<<endl;
            str=str+20;
            cout<<PL("Si≥a=")<<str<<endl;
            dex=dex+20;
	    cout<<PL("ZrÍcznoúc=")<<dex<<endl;
cout<<endl;
    cout<<PL("GRATULACJE UKO—CZY£Eå TRZECII ROZDZIA£ HISTORII!")<<endl;
cout<<endl;
            cout<<PL("Statystki Nero: ")<<endl;
		hpn=hpn+15;
            cout<<PL("Øycie=")<<hpn<<endl;
		strn=strn+15;
            cout<<PL("Si≥a=")<<strn<<endl;
		fn=fn+15;
            cout<<PL("SzybkoúÊ=")<<fn<<endl;
            historia++;
            goto lokacje;
        }

        else if (lvl<3)
        {
            cout<<PL("Nie moøesz wejúÊ, za ma≥y poziom. Wybierz jeszcze raz.")<<endl;
            goto lokacje;
        }
        else if (historia>2)
            {
                cout<<PL("Juø ukoÒczy≥eú ten rozdzia≥.")<<endl;
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

            cout<<PL("Obudzi≥o ciÍ lizanie po twarzy. Nero jak zawsze mia≥ ciekawe pomys≥y na pobudkÍ.")<<endl;
            cout<<PL("Wsta≥eú rozglπdajπc siÍ woko≥o, nadal byliúcie na polanie.")<<endl;
            cout<<PL("Zauwaøy≥eú kosz obok ogniska. Na wierzchu leøa≥a kartka.")<<endl;
            cout<<R"(
.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.
|                                                                       |
|   GratulacjÍ! Uda≥o siÍ wam, niestety ale teraz musicie radziÊ        |
|     sobie sami. Alucard odkry≥ øe coú knujemy, wys≥a≥ do lasu         |
|     gobliny. MuszÍ zostaÊ ukryta w domu, Iwan wrÛci≥ do miasta        |
|     jak gdyby nigdy nic lecz mia≥ przed tym dostarczyÊ wam to.        |
!     Skoro to czytasz to oboje jesteúmy bezpieczni, a ty zapewne       !
:     masz to po co poszed≥eú do kopalni. Mam nadziejÍ øe oby≥o         :
:     siÍ bez wiÍkszych problemÛw.                                      :
.                                                                       .
.      Musicie siÍ poúpieszyÊ, jeúli Alucard dowie siÍ gdzie jesteúcie  .
:      wyúle za wami gobliny, a wtedy nie bÍdÍ mog≥a wam pomÛc.         :
:                                                                       :
!      Jego kaplica jest po drugiej stronie miasta, rzadko kiedy jπ     !
|      opuszcza. Musicie odzyskaÊ szybko si≥y i ruszyÊ mu na spotkanie. |
|      Im szybciej tym lepiej. Powodzenia.                              |
|                                                                       |
|       PS.                                                             |
|       Mam nadziejÍ øe wszytko co wam da≥am by≥o przydatne.            |
|                                                                       |
|                                                  Elen                 |
|                                                                       |
`-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'
            )"<<endl;
            cl();
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Zrobi≥a dla nas juø tyle...musimy im jak najszybciej pomÛc.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
             cout<<PL("Zaglπdasz do koszyka, pe≥no w nim jedzenia, bandaøy oraz kolejnych fiolek leczniczych.")<<endl;
             cout<<PL("Na szczÍúcie juø po wczorajszej dawce czujecie siÍ dobrze, a wasza regeneracja jest")<<endl;
             cout<<PL("przyúpieszona, dziÍki temu odzyskujecie powoli zdrowie.")<<endl;
             hp=hp+15;
            cout<<"Twoje øycie= "<<hp<<endl;
             hpn=hpn+15;
            cout<<PL("Øycie Nero= ")<<hpn<<endl;
            cout<<PL("Zmieni≥eú opatrunki zarÛwno sobie jak i wilkowi, po czym poda≥eú úniadanie.")<<endl;
            cout<<PL("Ca≥y czas jednak myúlami odbiega≥eú do nieuniknionego starcia z wampirem.")<<endl;
            cout<<PL("Obawia≥eú siÍ czy to co posiadasz na pewno da radÍ.")<<endl;
            cout<<PL("Nero wyczu≥ fakt øe zamartwiasz siÍ przysz≥oúciπ, usiad≥ naprzeciwko Ciebie")<<endl;
            cout<<PL("patrzπc ci prosto w oczy, jakby chcia≥ powiedzieÊ:")<<endl;
            cout<<PL("Hej, masz mnie. Damy sobie razem radÍ.")<<endl;
            cout<<PL("Uúmiechnπ≥eú siÍ i pog≥aska≥eú wilka po ≥bie.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Masz racjÍ, damy sobie rady.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Pozosta≥π czÍúÊ poranka rozmyúla≥eú nad planem pokonania krwiopijcy...")<<endl;
            cl();

            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("WIECZ”R")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout<<PL("Znajdujesz siÍ przed wielkπ starπ kaplicπ, wokÛ≥ pe≥no grobÛw.")<<endl;
            cout<<PL("NiektÛre widaÊ, øe niedawno zosta≥y zasypane úwieøπ ziemiπ.")<<endl;
            cout<<PL("Bierzesz g≥Íboki oddech...i ruszasz, otwierajπ siÍ przed tobπ ogromne wrota.")<<endl;
            cout<<PL("W úrodku, przed o≥tarzem dostrzegasz postaÊ.")<<endl;
            cout<<PL("Bierzesz g≥Íboki oddech i przekraczasz prÛg. Drzwi zamykajπ siÍ za Tobπ z hukiem.")<<endl;
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
            cout<<PL("Øycie: ")<<ahp<<endl;
            cout<<PL("SzybkoúÊ: ")<<af<<endl;
            cout<<PL("Si≥a: ")<<asl<<endl;
            Sleep(5000);
            system("cls");
            SetConsoleTextAttribute( hOut, FOREGROUND_RED );
            cout<<PL("Witaj wybraÒcu, czeka≥em na ciebie...haha mÛwiÍ to kaødemu kretynowi ktÛry odwaøy siÍ do mnie przyjúÊ.")<<endl;
            cout<<PL("Widzia≥eú groby przed kaplicπ? Jeden z nich stanie siÍ twoim grobem, hahaha.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("Nie jestem podrÛbkπ jak wszyscy ktÛrzy tu byli przedmπ.")<<endl;
            cout<<PL("Jestem prawdziwym wybraÒcem i pokonam ciÍ, aby w mieúcie znowu panowa≥ pokÛj!")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

            cout<<PL("W jednej sekundzie straci≥eú wampira z oczu, by≥ zbyt szybki.")<<endl;
            cout<<PL("Nagle znalaz≥ siÍ za Tobπ, poczu≥eú jego lodowatπ d≥oÒ na swoim karku.")<<endl;
            cout<<PL("Lecz zanim zdπøy≥eú cokolwiek zrobiÊ, ten rzuci≥ Tobπ w jednπ z kolumn kaplicy.")<<endl;
            hp=hp-10;
            cout<<PL("Zdrowie: ")<<hp<<endl;
            if (wybor[0]==1)
    {
        cout<<PL("Kaszlπc podnosisz siÍ z ziemi, chwytasz za ≥uk i zaczynasz strzelaÊ w wampira.")<<endl;
        cout<<PL("Ten jednak dalej popisuje siÍ swojπ prÍdkoúciπ, øadna strza≥a nie dosz≥a do celu.")<<endl;
    }
    else if(wybor[0]==2)
    {
            cout<<PL("Kaszlπc podnosisz siÍ z ziemi, wyciπgasz miecz i pomimo bÛlu biegniesz w kierunku wampira.")<<endl;
            cout<<PL("Ten jednak kiedy zamachnπ≥eú siÍ broniπ ponownie siÍ przeniÛs≥ na o≥tarz.")<<endl;
            cout<<PL("BroÒ z pustym úwistem przeciÍ≥a powietrze.")<<endl;
    }
    else if (wybor[0]==3)
    {
            cout<<PL("Kaszlπc podnosisz siÍ z ziemi, wyciπgasz fiolkÍ i rzucasz jπ w miejsce gdzie obecnie stoi wampir.")<<endl;
            cout<<PL("Ten jednak w momencie rozbicia naczynia ponownie uøy≥ prÍdkoúci i siÍ przeniÛs≥ na o≥tarz.")<<endl;
    }
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    cout<<PL("TWOJE MYåLI: Cholera jak ja mam go choÊby zadrapaÊ...")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<PL("Tym razem Alucard pojawi≥ siÍ przed Tobπ, nie mia≥eú czasu na reakcjÍ.")<<endl;
    cout<<PL("Oberwa≥eú od niego z piÍúci w brzuch, z twoich ust polecia≥a krew.")<<endl;
    hp=hp-10;
    cout<<PL("Zdrowie: ")<<hp<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    cout<<PL("TWOJE MYåLI: W takim tempie marnie skoÒczÍ...Kaødy jego atak zabiera 10 punktÛw zdrowia.")<<endl;
    cl();
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

    while (hp>=0)
    {
        if (d2==0)
        {
        cout<<PL("Nie mia≥eú nawet chwili aby pomyúleÊ nad kolejnym ruchem, pojawia≥ siÍ niewiadomo skπd zadajπc cios za ciosem.")<<endl;
        d2++;
        }
        hp=hp-dma;
        cout<<PL("Zdrowie: ")<<hp<<endl;
        Sleep(1000);
        cout<<endl;

        if (d2==1)
        {
        cout<<PL("Alucard ok≥adajπc ciÍ piÍúciami ca≥y czas szaleÒczo siÍ úmia≥. Wizja kolejnego trupa do kolekcji go bawi≥a.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        cout<<PL("No co jest, mia≥eú byÊ TYM WYBRA—CEM KT”RY MNIE ZABIJE hahahah.")<<endl;
        cout<<PL("A proszÍ, kto tu kogo zaraz zaszlachtuje?")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Nawet nie wiesz w ktÛrym momencie twoja broÒ znalaz≥a sie poza twoim zasiÍgiem.")<<endl;
        cout<<PL("Wyrwa≥ ci jπ w ktÛrymú momencie? Sam jπ upuúci≥eú? Juø sam nie wiedzia≥eú.")<<endl;
        }

        if (d2==1)
        {
        cout<<PL("Kaødy kolejny cios rÛwna≥ siÍ coraz wiÍkszej ka≥uøy krwi, wampir nie szczÍdzi≥ si≥y. Jego szpony")<<endl;
        cout<<PL("rani≥y ca≥e twoje cia≥o, opada≥eú z si≥. Koniec by≥ bliski.")<<endl;
        }

        if (d2==2)
        {
        cout<<PL("Zaczπ≥eú øa≥owaÊ øe tu przyszed≥eú, øe pomog≥eú wtedy Annie. Obarczono ciÍ misjπ zabicia wampira...")<<endl;
        }

         if (d2==3)
        {
        cout<<PL("Lecz jesteú za s≥aby...Przedmioty nie sπ na tyle mocne aby z nim siÍ mierzyÊ...")<<endl;
        }

         if (d2==4)
        {
        cout<<PL("To od poczπtku by≥a samobÛjcza misja...")<<endl;
        }

        if (hp<=10)
        {
            cl();
            cout<<PL("Ledwo øywy wy≥apa≥eú ruch ko≥o o≥tarza, Nero smutnym spojrzeniem obserwowa≥ jak obrywasz.")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<PL("TWOJE MYåLI: Trzymaj siÍ planu...Wytrzymam jeszcze chwilÍ...tak sπdzÍ...")<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            goto nero;
        }
        d2++;
        cout<<endl;
        Sleep(1500);
        //system ("cls");
    }

nero:
    cout<<PL("Alucard by≥ zbyt zajÍty Tobπ aby zwrÛciÊ uwagÍ na wilka, ktÛry niepostrzeøenie przeúlizgnπ≥ siÍ dziurπ z ty≥u kaplicy.")<<endl;
    if (wybor[0]==1)
    {
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        cout<<PL("Wiesz wybraÒcu, mam taki zwyczaj... Wypijam kielich krwi moich ofiar...poczekaj chwilÍ.")<<endl;
        cout<<PL("Twojej krwi takøe pragnÍ skosztowaÊ...")<<endl;
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
    cout<<PL("Alucard nagle znalaz≥ siÍ na o≥tarzu.")<<endl;
    cout<<PL("W tym momencie wyskoczy≥ na niego schowany Nero. PchniÍty wampir spad≥ z o≥tarza i wylπdowa≥ twarzπ na posadzce.")<<endl;
    cout<<PL("Nie by≥o duøo czasu, chwyci≥eú lezπcy obok ≥uk i wycelowa≥eú srebrnπ strza≥Í prosto w serce.")<<endl;
    cout<<PL("Ta w koÒcu trafi≥a cel..idealnie w serce. Alucard wyda≥ przeraüliwy krzyk bÛlu.")<<endl;

    }
    else if(wybor[0]==2)
    {
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        cout<<PL("Wiesz wybraÒcu, mam taki zwyczaj... Wypijam kielich krwi moich ofiar...poczekaj chwilÍ.")<<endl;
        cout<<PL("Twojej krwi takøe pragnÍ skosztowaÊ...")<<endl;
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
    cout<<PL("Alucard nagle znalaz≥ siÍ na o≥tarzu.")<<endl;
    cout<<PL("W tym momencie wyskoczy≥ na niego schowany Nero. PchniÍty wampir spad≥ z o≥tarza i wylπdowa≥ twarzπ na posadzce niedaleko Ciebie.")<<endl;
    cout<<PL("Nie by≥o duøo czasu, wyciπgnπ≥eú ukryty srebrny sztylet i ostatkiem si≥ rzuci≥eú w kierunku Alucarda, mierzπc miÍdzy oczy...")<<endl;
    cout<<PL("Ten idealnie podniÛs≥ g≥owÍ z ziemi, sztylet trafi≥, Alucard wyda≥ przeraüliwy krzyk bÛlu.")<<endl;
    }
    else if (wybor[0]==3)
    {
        cout<<PL("W pysku trzyma≥ fiolkÍ z zatrutπ krwiπ, wystarczy≥o aby dola≥ to do kielicha na o≥tarzu a wampir padnie.")<<endl;
        cout<<PL("Nero nie mÛg≥ znieúÊ øe pozwala katowaÊ ")<<nick<<"";
        cout<<PL(" ,lecz nie mÛg≥ nic na to poradziÊ. Jedynπ opcjπ by≥o poúwiÍcenie wybraÒca aby wampir zginπ≥.")<<endl;
        cout<<PL("Opcja ta nie podoba≥a mu siÍ ani trochÍ.")<<endl;
        cout<<PL("Zakrad≥ i wspiπ≥ siÍ na o≥tarz, szybko przechyli≥ ≥eb i wla≥ zawartoúÊ fiolki do kielicha sakralnego.")<<endl;
        cout<<PL("Teraz niech wampir to tylko wypije...")<<endl;
        cout<<PL("Wilk wycofa≥ siÍ i ukry≥ za jednπ z ≥aw koúcielnych.")<<endl;
        cout<<PL("Akurat w tym momencie wampir przesta≥ atakowaÊ")<<nick<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        cout<<PL("Wiesz wybraÒcu, mam taki zwyczaj... Wypijam kielich krwi moich ofiar...poczekaj chwilÍ.")<<endl;
        cout<<PL("Twojej krwi takøe pragnÍ skosztowaÊ...")<<endl;
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
    cout<<PL("Alucard nagle znalaz≥ siÍ na o≥tarzu.")<<endl;
       SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
       SetConsoleTextAttribute( hOut, FOREGROUND_RED );
    cout<<PL("Oh sekunda! Nie dopi≥em po twoim poprzedniku.")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<PL("Wampir za jednym razem wypi≥ ca≥a zawartoúÊ zatrutego kielicha.")<<endl;
    cout<<PL("Uúmiechnπ≥ siÍ oblizujπc usta, jednak zaraz zaczπ≥ siÍ dusiÊ.")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    cout<<PL("MÛwi≥em...j-jestem wybraÒcem...i..i..ciÍ zabijÍ...")<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

    }
        cout<<PL("Wampir zaczπ≥ siÍ rozpadaÊ..jakby by≥ z papieru. A z jego cia≥a zaczÍ≥o biÊ úwiat≥o ")<<endl;
        cout<<PL("tworzπc wielkπ ≥unÍ nad koúcio≥em, przypominajπcπ zorze polarnπ.")<<endl;

        cout<<PL("Lecz ty nie masz sposobnoúci zobaczyÊ tego zjawiska.")<<endl;
        cout<<PL("Padasz na ziemiÍ, powaønie krwawisz...Nero podbiega do Ciebie, widzπc twÛj tragiczny stan")<<endl;
        cout<<PL("chce lecieÊ po torbÍ z apteczkπ od Eleny...lecz zatrzymujesz zwierzaka.")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("Nie zdπøysz...zostaÒ ze mnπ do koÒca...")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Wilk k≥adzie sie obok ciebie opierajπc g≥owÍ o twÛj tors, z jego oczu lecπ ≥zy...")<<endl;
        cout<<PL("Tak samo zaczynasz p≥akaÊ wiedzπc øe to koniec...")<<endl;
        cout<<PL("Powoli odp≥ywasz...obraz zaczyna siÍ zamazywaÊ i ciemnieÊ...")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<PL("BÍdÍ za tobπ tÍskniÊ przyjacielu...")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<PL("Wypowiadasz ostatnim tchnieniem...i umierasz...")<<endl;
        hp=0;
        cl();

        cout<<PL("Ludzie widzπc ≥unÍ úwiat≥a nad kaplicπ, zaczÍli wychodziÊ szczÍúliwi z domÛw... ")<<endl;
        cout<<PL("Bawili siÍ, taÒczyli, úpiewali...nie wiedzπc jaka tragedia tam mia≥a miejsce...")<<endl;
        cout<<PL("Gobliny i inne potwory widzπc jπ natomiast zrozumia≥y klÍskÍ swego pana...wycofali siÍ znÛw do swoich kryjÛwek.")<<endl;
        cout<<endl;
        cout<<PL("Kiedy Anna, Elena, Iwan oraz Burmistrz dotarli do kaplicy, zastali ca≥a watahÍ czekajπca na zewnπtrz.")<<endl;
        cout<<PL("Przeraøeni spojrzeli po sobie i wbiegli do niej...Spostrzegli Nero pochylajπcego siÍ nad cia≥em ")<<nick<<endl;
        cout<<PL("Zrozumieli jak okrutna batalia to by≥a...")<<endl;
        cout<<endl;
        cout<<PL("Od tamtej pory kaplica jest miejscem, gdzie co wieczÛr przywÛdca watahy wznosi øa≥obne wycie za przyjacielem...")<<endl;
        cout<<PL("Kaødego wieczora...aø po swÛj ostatni dzieÒ.")<<endl;
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
            cout<<PL("Nie moøesz wejúÊ, za ma≥y poziom. Wybierz jeszcze raz.")<<endl;
            goto lokacje;
        }
    break;
    death:
        SetConsoleTextAttribute( hOut, BACKGROUND_RED );
        cout<<PL("NIE ØYJESZ - KONIEC GRY")<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        system("pause");
    return (0);
}
    }
