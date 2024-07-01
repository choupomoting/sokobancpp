#include <iostream>
using namespace std;

const int rozmiar = 10;

void wyswietl_plansza(char mapa[rozmiar][rozmiar]) {             //funkcja wypisujaca plansze
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {

            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}
void przypisz_plansze(char plansza1[rozmiar][rozmiar], char plansza2[rozmiar][rozmiar])   // funkcja przypisuje indeksom danej planszy indeksy innej planszy
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            plansza1[i][j] = plansza2[i][j];
        }
    }
}

void powitanie() {                                              //funkcja wyswietlajaca header powitalny
    cout << "==============|WITAJ W GRZE SOKOBAN.CPP|==============\n";
    cout << "==========|WYKONAL BARTLOMIEJ RADZIUN 186914|=========\n\n\n";
}

void wypisz_menu()                                              //funkcja wypisujaca menu powitalne
{
    cout << "| k - ZAGRAJ SOKOBAN    |" << endl;
    cout << "| h - OPIS GRY I ZASADY |" << endl;
    cout << "| q - WYJDZ Z PROGRAMU  |" << endl << endl;

}

void wypisz_zasady()                                            //funkcja wypisujaca zasady i opis gry
{
    cout << "Gra sokoban polega na chodzeniu magazynierem(w,a,s,d) i przesuwaniu skrzynek w wybrane miejsca" << endl;
    cout << "Skrzynie nie moga byc przepychane przez sciany i inne skrzynie" << endl;
    cout << "Gracz ma ograniczana liczbe ruchow." << endl;
    cout << "Warunkiem wygranej jest przepchniecie skrzyn w wyznaczone miejsca" << endl;
}

void menu_gry() {                                               //funkcja wypisujaca menu glowne gry, widzialne w kazdym etapie rozgrywki
    cout << "===========|MENU GRY|===========" << endl;
    cout << "|  q - WYJDZ Z GRY             |" << endl;
    cout << "|  e - WROC DO MENU STARTOWEGO |" << endl;
    cout << "|  w,a,s,d - RUCH GRACZEM      |" << endl;
    cout << "|  i - ZACZNIJ OD NOWA         |" << endl;
    cout << "|  b - WCZYTAJ ETAP 2          |" << endl;
    cout << "|  r - WCZYTAJ ETAP 3          |" << endl;
    cout << "================================" << endl;

}
void gracz(int& wiersz, int& kolumna, char plansza[rozmiar][rozmiar]) {        //funkcja zczytuje koordynaty gracza, zapisuje je do zmiennych wiersz i kolumna

    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {

            if (plansza[i][j] == 'X') {
                wiersz = i;
                kolumna = j;
            }

        }
    }
}

int main() {
    bool gra1_trwa = true;                                   //informuja, ktory etap jest aktualnie rozgrywany
    bool gra2_trwa = false;
    bool gra3_trwa = false;
    char opcje_menu_poczatkowego;                            //do switch case dla menu glownego i poczatkowego
    char opcje_menu_glownego;
    int wiersz;                                              //koordynaty gracza, pozycja w pionie i poziomie
    int kolumna;
    int licznik1 = 0;                                        //liczniki zdobytych punktow dla 3 etapow
    int licznik2 = 0;
    int licznik3 = 0;
    int liczruch1 = 50;                                      //liczniki ruchow dla 3 etapow
    int liczruch2 = 60;
    int liczruch3 = 70;
    int licznik_ruchow;

    char plansza[rozmiar][rozmiar] = {                       //plansza dla etapu 1

        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', 'O', ' ', ' ', ' ', 'E', '#'},
        {'#', ' ', ' ', 'X', ' ', ' ', ' ', '#', '#', '#'},
        {'#', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', ' ', ' ', 'O', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', 'O', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', 'E', '#', '#', 'E', '#', ' ', '#', 'E', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };
    char plansza_poczatkowa[rozmiar][rozmiar] = {

        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', 'O', ' ', ' ', ' ', 'E', '#'},
        {'#', ' ', ' ', 'X', ' ', ' ', ' ', '#', '#', '#'},
        {'#', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', ' ', ' ', 'O', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', 'O', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', 'E', '#', '#', 'E', '#', ' ', '#', 'E', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };

    char plansza2[rozmiar][rozmiar] = {                        //plansza dla etapu 2

        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'X', '#', '#', ' ', 'O', ' ', ' ', 'E', '#'},
        {'#', ' ', ' ', '#', ' ', 'O', ' ', '#', '#', '#'},
        {'#', '#', ' ', '#', ' ', ' ', ' ', 'E', '#', '#'},
        {'#', '#', 'O', '#', ' ', ' ', ' ', '#', '#', '#'},
        {'#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'E', '#'},
        {'#', ' ', ' ', ' ', ' ', 'O', ' ', ' ', 'E', '#'},
        {'#', ' ', 'O', ' ', ' ', ' ', ' ', ' ', 'E', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };
    char plansza2_poczatkowa[rozmiar][rozmiar] = {

        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'X', '#', '#', ' ', 'O', ' ', ' ', 'E', '#'},
        {'#', ' ', ' ', '#', ' ', 'O', ' ', '#', '#', '#'},
        {'#', '#', ' ', '#', ' ', ' ', ' ', 'E', '#', '#'},
        {'#', '#', 'O', '#', ' ', ' ', ' ', '#', '#', '#'},
        {'#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'E', '#'},
        {'#', ' ', ' ', ' ', ' ', 'O', ' ', ' ', 'E', '#'},
        {'#', ' ', 'O', ' ', ' ', ' ', ' ', ' ', 'E', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };

    char plansza3[rozmiar][rozmiar] = {                       //plansza dla etapu 3

        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'E', ' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
        {'#', '#', ' ', '#', '#', 'O', ' ', '#', '#', '#'},
        {'#', '#', ' ', '#', '#', 'X', ' ', 'E', '#', '#'},
        {'#', '#', 'O', '#', '#', ' ', ' ', '#', '#', '#'},
        {'#', '#', ' ', ' ', ' ', ' ', 'O', '#', '#', '#'},
        {'#', '#', ' ', ' ', ' ', ' ', ' ', ' ', 'E', '#'},
        {'#', '#', '#', ' ', ' ', 'O', ' ', ' ', 'E', '#'},
        {'#', '#', 'E', ' ', 'O', ' ', ' ', ' ', 'E', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };

    char plansza3_poczatkowa[rozmiar][rozmiar] = {

        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'E', ' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
        {'#', '#', ' ', '#', '#', 'O', ' ', '#', '#', '#'},
        {'#', '#', ' ', '#', '#', 'X', ' ', 'E', '#', '#'},
        {'#', '#', 'O', '#', '#', ' ', ' ', '#', '#', '#'},
        {'#', '#', ' ', ' ', ' ', ' ', 'O', '#', '#', '#'},
        {'#', '#', ' ', ' ', ' ', ' ', 'O', ' ', 'E', '#'},
        {'#', '#', '#', ' ', ' ', 'O', ' ', ' ', 'E', '#'},
        {'#', '#', 'E', ' ', 'O', ' ', ' ', ' ', 'E', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };

    powitanie();
    wypisz_menu();
    do {                                     //petla ze switch case dla menu glownego
        cout << "PODAJ OPCJE: " << endl;
        cin >> opcje_menu_poczatkowego;
        system("cls");
        switch (opcje_menu_poczatkowego) {
        case 'k':
            gra1_trwa = true;                //domyslnie na starcie zaczynamy od etapu 1
            if (gra1_trwa == true && gra2_trwa == false && gra3_trwa == false) {                                    //f. przypisujace licznikowi ruchow wartosc, w zaleznosci od etapu
                licznik_ruchow = liczruch1;
            }
            if (gra1_trwa == false && gra2_trwa == true && gra3_trwa == false) {
                licznik_ruchow = liczruch2;
            }
            if (gra1_trwa == false && gra2_trwa == false && gra3_trwa == true) {
                licznik_ruchow = liczruch3;
            }
            do {

                system("cls");
                menu_gry();
                gracz(wiersz, kolumna, plansza);
                wyswietl_plansza(plansza);
                cout << "ZOSTALO CI: " << endl << licznik_ruchow << " RUCHOW" << endl << endl;
                cout << "WPISZ OPCJE: " << endl;
                cin >> opcje_menu_glownego;
                switch (opcje_menu_glownego) {
                case 'd':                                               //ruch w prawo

                    if (plansza[wiersz][kolumna + 1] != '#') {          //jezeli przed graczem nie ma sciany (warunek poczatkowy wykonania ruchu)

                        if (plansza[wiersz][kolumna + 1] == ' ') {       //jezeli przed graczem jest puste pole, wykonuje ruch (zmienia pozycje o 1, pole wczesniejsze zamienia sie w puste pole)
                            plansza[wiersz][kolumna + 1] = 'X';
                            plansza[wiersz][kolumna] = ' ';
                            kolumna = kolumna + 1;
                            licznik_ruchow = licznik_ruchow - 1;        //licznik ruchow zmniejsza sie o 1 - ta operacja zachodzi zawsze, gdy wykonany ruch jest legalny ruch
                        }
                        else if (plansza[wiersz][kolumna + 1] == 'O') {   //jezeli przed graczem jest skrzynia

                            if (plansza[wiersz][kolumna + 2] == '#') {    //jezeli przed skrzynia jest sciana, to nic sie nie zmienia
                                plansza[wiersz][kolumna + 2] = '#';
                                plansza[wiersz][kolumna + 1] = 'O';
                                plansza[wiersz][kolumna] = 'X';
                            }
                            else if (plansza[wiersz][kolumna + 2] == 'O') {    //jezeli przed skrzynia jest inna skrzynia, to nic sie nie zmienia
                                plansza[wiersz][kolumna + 2] = 'O';
                                plansza[wiersz][kolumna + 1] = 'O';
                                plansza[wiersz][kolumna] = 'X';
                            }
                            else if (plansza[wiersz][kolumna + 2] == ' ') {    //jezeli przed skrzynia jest puste puste pole, to wykonuje sie ruch przesuwajacy skrzynie i gracza o 1 pole
                                plansza[wiersz][kolumna + 2] = 'O';
                                plansza[wiersz][kolumna + 1] = 'X';
                                plansza[wiersz][kolumna] = ' ';
                                kolumna = kolumna + 1;
                                licznik_ruchow = licznik_ruchow - 1;        //legalny ruch = licznik ruchow zmniejsza sie o 1
                            }
                            else if (plansza[wiersz][kolumna + 2] == 'E') {    //jesli przed skrzynia jest pole, w ktore gracz ma postawic skrzynie, to E zamienia sie w W
                                plansza[wiersz][kolumna + 2] = 'W';
                                plansza[wiersz][kolumna + 1] = 'X';
                                plansza[wiersz][kolumna] = ' ';
                                if (gra1_trwa == true && gra2_trwa == false && gra3_trwa == false) {          //w zaleznosci od etapu licznik skrzyn ustawionych na polach sie zwieksza
                                    licznik1 = licznik1 + 1;
                                }
                                if (gra1_trwa == false && gra2_trwa == true && gra3_trwa == false) {
                                    licznik2 = licznik2 + 1;
                                }
                                if (gra1_trwa == false && gra2_trwa == false && gra3_trwa == true) {
                                    licznik3 = licznik3 + 1;
                                }
                                kolumna = kolumna + 1;
                                licznik_ruchow = licznik_ruchow - 1;
                            }

                            else if (plansza[wiersz][kolumna + 2] == 'W') {    //jesli przed skrzynia jest pole, na ktore gracz postawil juz skrzynie, to nic sie nie dzieje
                                plansza[wiersz][kolumna + 2] = 'W';
                                plansza[wiersz][kolumna + 1] = 'O';
                                plansza[wiersz][kolumna] = 'X';
                            }

                        }
                        else if (plansza[wiersz][kolumna + 1] == 'W') {      //jesli przed graczem jest pole, na ktore gracz postawil skrzynie, to nie wykonuje ruchu
                            plansza[wiersz][kolumna + 1] = 'W';
                            plansza[wiersz][kolumna] = 'X';

                        }
                        else if (plansza[wiersz][kolumna + 1] == 'E') {      //jesli przed graczem jest pole, na trzeba postawic skrzynie, to nie wykonuje ruchu
                            plansza[wiersz][kolumna + 1] = 'E';
                            plansza[wiersz][kolumna] = 'X';
                        }

                    }
                    break;
                    //ruch w lewo
                case 'a':                                                   // warunki dla opcji ruchu A,S,W dzialaja analogicznie jak dla D. Zmieniany jest kierunek przesuniecia i/lub os
                    if (plansza[wiersz][kolumna - 1] != '#') {

                        if (plansza[wiersz][kolumna - 1] == ' ') {
                            plansza[wiersz][kolumna - 1] = 'X';
                            plansza[wiersz][kolumna] = ' ';
                            kolumna = kolumna - 1;
                            licznik_ruchow = licznik_ruchow - 1;
                        }
                        else if (plansza[wiersz][kolumna - 1] == 'O') {

                            if (plansza[wiersz][kolumna - 2] == '#') {
                                plansza[wiersz][kolumna - 2] = '#';
                                plansza[wiersz][kolumna - 1] = 'O';
                                plansza[wiersz][kolumna] = 'X';
                            }
                            else if (plansza[wiersz][kolumna - 2] == 'O') {
                                plansza[wiersz][kolumna - 2] = 'O';
                                plansza[wiersz][kolumna - 1] = 'O';
                                plansza[wiersz][kolumna] = 'X';
                            }
                            else if (plansza[wiersz][kolumna - 2] == ' ') {
                                plansza[wiersz][kolumna - 2] = 'O';
                                plansza[wiersz][kolumna - 1] = 'X';
                                plansza[wiersz][kolumna] = ' ';
                                kolumna = kolumna - 1;
                                licznik_ruchow = licznik_ruchow - 1;
                            }
                            else if (plansza[wiersz][kolumna - 2] == 'E') {
                                plansza[wiersz][kolumna - 2] = 'W';
                                plansza[wiersz][kolumna - 1] = 'X';
                                plansza[wiersz][kolumna] = ' ';
                                if (gra1_trwa == true && gra2_trwa == false && gra3_trwa == false) {
                                    licznik1 = licznik1 + 1;
                                }
                                if (gra1_trwa == false && gra2_trwa == true && gra3_trwa == false) {
                                    licznik2 = licznik2 + 1;
                                }
                                if (gra1_trwa == false && gra2_trwa == false && gra3_trwa == true) {
                                    licznik3 = licznik3 + 1;
                                }
                                kolumna = kolumna - 1;
                                licznik_ruchow = licznik_ruchow - 1;
                            }
                            else if (plansza[wiersz][kolumna - 2] == 'W') {
                                plansza[wiersz][kolumna - 2] = 'W';
                                plansza[wiersz][kolumna - 1] = 'O';
                                plansza[wiersz][kolumna] = 'X';

                            }

                        }
                        else if (plansza[wiersz][kolumna - 1] == 'W') {
                            plansza[wiersz][kolumna - 1] = 'W';
                            plansza[wiersz][kolumna] = 'X';

                        }
                        else if (plansza[wiersz][kolumna - 1] == 'E') {
                            plansza[wiersz][kolumna - 1] = 'E';
                            plansza[wiersz][kolumna] = 'X';
                        }

                    }
                    break;
                case 'w':                                              //ruch w gore
                    if (plansza[wiersz - 1][kolumna] != '#') {

                        if (plansza[wiersz - 1][kolumna] == ' ') {
                            plansza[wiersz - 1][kolumna] = 'X';
                            plansza[wiersz][kolumna] = ' ';
                            wiersz = wiersz - 1;
                            licznik_ruchow = licznik_ruchow - 1;
                        }
                        else if (plansza[wiersz - 1][kolumna] == 'O') {
                            if (plansza[wiersz - 2][kolumna] == '#') {
                                plansza[wiersz - 2][kolumna] = '#';
                                plansza[wiersz - 1][kolumna] = 'O';
                                plansza[wiersz][kolumna] = 'X';
                            }
                            else if (plansza[wiersz - 2][kolumna] == 'O') {
                                plansza[wiersz - 2][kolumna] = 'O';
                                plansza[wiersz - 1][kolumna] = 'O';
                                plansza[wiersz][kolumna] = 'X';
                            }
                            else if (plansza[wiersz - 2][kolumna] == ' ') {
                                plansza[wiersz - 2][kolumna] = 'O';
                                plansza[wiersz - 1][kolumna] = 'X';
                                plansza[wiersz][kolumna] = ' ';
                                wiersz = wiersz - 1;
                                licznik_ruchow = licznik_ruchow - 1;
                            }
                            else if (plansza[wiersz - 2][kolumna] == 'E') {
                                plansza[wiersz - 2][kolumna] = 'W';
                                plansza[wiersz - 1][kolumna] = 'X';
                                plansza[wiersz][kolumna] = ' ';
                                if (gra1_trwa == true && gra2_trwa == false && gra3_trwa == false) {
                                    licznik1 = licznik1 + 1;
                                }
                                if (gra1_trwa == false && gra2_trwa == true && gra3_trwa == false) {
                                    licznik2 = licznik2 + 1;
                                }
                                if (gra1_trwa == false && gra2_trwa == false && gra3_trwa == true) {
                                    licznik3 = licznik3 + 1;
                                }
                                wiersz = wiersz - 1;
                                licznik_ruchow = licznik_ruchow - 1;
                            }
                            else if (plansza[wiersz - 2][kolumna] == 'W') {
                                plansza[wiersz - 2][kolumna] = 'W';
                                plansza[wiersz - 1][kolumna] = 'O';
                                plansza[wiersz][kolumna] = 'X';

                            }

                        }
                        else if (plansza[wiersz - 1][kolumna] == 'W') {
                            plansza[wiersz - 1][kolumna] = 'W';
                            plansza[wiersz][kolumna] = 'X';

                        }
                        else if (plansza[wiersz - 1][kolumna] == 'E') {
                            plansza[wiersz - 1][kolumna] = 'E';
                            plansza[wiersz][kolumna] = 'X';
                        }

                    }
                    break;
                case 's':                                                //ruch w dol
                    if (plansza[wiersz + 1][kolumna] != '#') {

                        if (plansza[wiersz + 1][kolumna] == ' ') {
                            plansza[wiersz + 1][kolumna] = 'X';
                            plansza[wiersz][kolumna] = ' ';
                            wiersz = wiersz + 1;
                            licznik_ruchow = licznik_ruchow - 1;
                        }
                        else if (plansza[wiersz + 1][kolumna] == 'O') {

                            if (plansza[wiersz + 2][kolumna] == '#') {
                                plansza[wiersz + 2][kolumna] = '#';
                                plansza[wiersz + 1][kolumna] = 'O';
                                plansza[wiersz][kolumna] = 'X';
                            }
                            else if (plansza[wiersz + 2][kolumna] == 'O') {
                                plansza[wiersz + 2][kolumna] = 'O';
                                plansza[wiersz + 1][kolumna] = 'O';
                                plansza[wiersz][kolumna] = 'X';
                            }
                            else if (plansza[wiersz + 2][kolumna] == ' ') {
                                plansza[wiersz + 2][kolumna] = 'O';
                                plansza[wiersz + 1][kolumna] = 'X';
                                plansza[wiersz][kolumna] = ' ';
                                wiersz = wiersz + 1;
                                licznik_ruchow = licznik_ruchow - 1;
                            }
                            else if (plansza[wiersz + 2][kolumna] == 'E') {
                                plansza[wiersz + 2][kolumna] = 'W';
                                plansza[wiersz + 1][kolumna] = 'X';
                                plansza[wiersz][kolumna] = ' ';
                                if (gra1_trwa == true && gra2_trwa == false && gra3_trwa == false) {
                                    licznik1 = licznik1 + 1;
                                }
                                if (gra1_trwa == false && gra2_trwa == true && gra3_trwa == false) {
                                    licznik2 = licznik2 + 1;
                                }
                                if (gra1_trwa == false && gra2_trwa == false && gra3_trwa == true) {
                                    licznik3 = licznik3 + 1;
                                }
                                wiersz = wiersz + 1;
                                licznik_ruchow = licznik_ruchow - 1;
                            }
                            else if (plansza[wiersz + 2][kolumna] == 'W') {
                                plansza[wiersz + 2][kolumna] = 'W';
                                plansza[wiersz + 1][kolumna] = 'O';
                                plansza[wiersz][kolumna] = 'X';

                            }

                        }
                        else if (plansza[wiersz + 1][kolumna] == 'W') {
                            plansza[wiersz + 1][kolumna] = 'W';
                            plansza[wiersz][kolumna] = 'X';
                        }
                        else if (plansza[wiersz + 1][kolumna] == 'E') {
                            plansza[wiersz][kolumna] = 'X';
                        }

                    }
                    break;
                case 'i':                                 //opcja resetu etapu. W zaleznosci biezacego etapu, przypisuje indeksom planszy aktualnej indeksy planszy poczatkowej
                    if (gra1_trwa == true && gra2_trwa == false && gra3_trwa == false) {
                        przypisz_plansze(plansza, plansza_poczatkowa);
                        licznik1 = 0;                                                           //resetowane sa liczniki(ruchow i zdobytych punktow)
                        licznik_ruchow = liczruch1;
                    }
                    if (gra1_trwa == false && gra2_trwa == true && gra3_trwa == false) {
                        przypisz_plansze(plansza, plansza2_poczatkowa);
                        licznik2 = 0;
                        licznik_ruchow = liczruch2;
                    }
                    if (gra1_trwa == false && gra2_trwa == false && gra3_trwa == true) {
                        przypisz_plansze(plansza, plansza3_poczatkowa);
                        licznik3 = 0;
                        licznik_ruchow = liczruch3;
                    }
                    break;
                case 'b':                                   //opcja b pozwala wczytac etap 2, przypisujac plansze, zmieniajac liczniki
                    gra1_trwa = false;
                    gra3_trwa = false;
                    gra2_trwa = true;
                    licznik1 = 0;
                    licznik2 = 0;
                    licznik3 = 0;
                    licznik_ruchow = liczruch2;
                    przypisz_plansze(plansza, plansza2_poczatkowa);
                    break;
                case 'r':                                   //analogicznie jak opcja b
                    gra1_trwa = false;
                    gra2_trwa = false;
                    gra3_trwa = true;
                    licznik1 = 0;
                    licznik2 = 0;
                    licznik3 = 0;
                    licznik_ruchow = liczruch3;
                    przypisz_plansze(plansza, plansza3_poczatkowa);
                    break;
                case 'q':
                    exit(0);
                    break;
                case 'e':
                    przypisz_plansze(plansza, plansza_poczatkowa);
                    gra1_trwa = false;
                    gra2_trwa = false;
                    gra3_trwa = false;
                    licznik1 = 0;
                    licznik2 = 0;
                    licznik3 = 0;
                    break;
                default:
                    cout << "Niepoprawna opcja!" << endl << endl;
                }
                //============================================================================================================================================================================
                if (licznik_ruchow == 0 && gra1_trwa == true && gra2_trwa == false && gra3_trwa == false) {         //warunki na przegrana poprzez skonczenie sie ruchow, w zaleznosci od biezacego etapu rozgrywki
                    system("cls");
                    wyswietl_plansza(plansza);
                    przypisz_plansze(plansza, plansza_poczatkowa);
                    licznik1 = 0;
                    licznik_ruchow = liczruch1;
                    gra1_trwa = true;
                    cout << "WYKORZYSTALES WSZYSTKIE RUCHY, PRZEGRYWASZ, ZACZNIJ ETAP OD NOWA" << endl;
                    system("pause");
                }
                if (licznik_ruchow == 0 && gra1_trwa == false && gra2_trwa == true && gra3_trwa == false) {          //dla etapu 2
                    system("cls");
                    wyswietl_plansza(plansza);
                    przypisz_plansze(plansza, plansza2_poczatkowa);
                    licznik2 = 0;
                    licznik_ruchow = liczruch2;
                    gra2_trwa = true;
                    cout << "WYKORZYSTALES WSZYSTKIE RUCHY, PRZEGRYWASZ, ZACZNIJ ETAP OD NOWA" << endl;
                    system("pause");
                }
                if (licznik_ruchow == 0 && gra1_trwa == false && gra2_trwa == false && gra3_trwa == true) {          //dla etapu 3
                    system("cls");
                    wyswietl_plansza(plansza);
                    przypisz_plansze(plansza, plansza3_poczatkowa);
                    licznik3 = 0;
                    licznik_ruchow = liczruch3;
                    gra3_trwa = true;
                    cout << "WYKORZYSTALES WSZYSTKIE RUCHY, PRZEGRYWASZ, ZACZNIJ ETAP OD NOWA" << endl;
                    system("pause");
                }
                //=========================================================================================================================================================================================
                if (gra1_trwa == true && licznik1 == 4) {                                                             //warunki na wygrana, poprzez przepchanie wymaganej ilosci skrzyn na wyznaczone pola
                    system("cls");
                    wyswietl_plansza(plansza);
                    przypisz_plansze(plansza, plansza2_poczatkowa);
                    gra1_trwa = false;
                    gra2_trwa = true;
                    licznik1 = 0;
                    licznik_ruchow = liczruch2;
                    cout << "GRATULACJE, UKONCZYLES ETAP 1" << endl;

                    system("pause");

                }
                if (gra2_trwa == true && licznik2 == 5) {                                                             //dla etapu 2
                    system("cls");
                    wyswietl_plansza(plansza);
                    przypisz_plansze(plansza, plansza3_poczatkowa);
                    gra2_trwa = false;
                    gra3_trwa = true;
                    licznik2 = 0;
                    licznik_ruchow = liczruch3;
                    cout << "GRATULACJE, UKONCZYLES ETAP 2" << endl;

                    system("pause");

                }
                if (gra3_trwa == true && licznik3 == 6) {                                                             //dla etapu 3
                    system("cls");
                    wyswietl_plansza(plansza);
                    przypisz_plansze(plansza, plansza_poczatkowa);
                    gra3_trwa = false;
                    gra2_trwa = false;
                    gra1_trwa = false;
                    licznik3 = 0;
                    licznik_ruchow = liczruch1;
                    cout << "GRATULACJE, UKONCZYLES ETAP 3" << endl;

                    system("pause");
                    break;
                }

            } while (opcje_menu_glownego != 'e'); //warunek koncowy wykonywania petli - klikajac e wraca do ekranu poczatkowego

            system("cls");
            powitanie();
            wypisz_menu();
            break;
        case 'h':                        //wyswietla opis i zasady gry
            powitanie();
            wypisz_zasady();
            system("pause");
            system("cls");
            powitanie();
            wypisz_menu();
            break;
        default:
            cout << "Niepoprawna opcja!" << endl << endl;
            wypisz_menu();
            break;
        }
    } while (opcje_menu_poczatkowego != 'q');

    return 0;
}