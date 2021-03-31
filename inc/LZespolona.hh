#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <cmath>
#include <iostream>
#define MIN_DIFF 0.00001
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct LZespolona
{
  double re; /*! Pole repezentuje czesc rzeczywista. */
  double im; /*! Pole repezentuje czesc urojona. */
};

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

bool operator==(LZespolona Skl1, LZespolona Skl2);

LZespolona operator+(LZespolona Skl1, LZespolona Skl2);

LZespolona operator-(LZespolona Skl1, LZespolona Skl2);

LZespolona operator*(LZespolona Skl1, LZespolona Skl2);

LZespolona operator/(LZespolona Skl1, LZespolona Skl2);

LZespolona operator/(LZespolona Skl1, double Skl2);

LZespolona Sprzezenie(LZespolona zespolona);

double Modul2(LZespolona zespolona);

void Wyswietl(LZespolona *zespolona);

std::ostream &operator<<(std::ostream &Wyjscie, const LZespolona &Zesp_Wyjscie);

std::istream &operator >>(std::istream &Wyjscie, LZespolona &Zesp_Wyjscie);

#endif
