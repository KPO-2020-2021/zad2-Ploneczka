#include "Statystyki.hh"
#include <iostream>

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

double Podsumowanie(int dobrze, int zle)
{
    double wynik_proc = (dobrze * 100) / (dobrze + zle);
    std::cout << "Dobre odpowiedzi : " << dobrze << std::endl ;
    std::cout << "Zle odpowiedzi : " << zle << std::endl;
    std::cout << "Procent poprawnych odpowiedzi : " << wynik_proc << "%" << std::endl;
    return wynik_proc;
}
