#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"
#include <iostream>

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */
std::istream &operator>>(std::istream &Wejscie, Operator &oper);
std::ostream &operator<<(std::ostream &Wyjscie, const Operator &oper);
std::ostream &operator<<(std::ostream &Wyjscie, const WyrazenieZesp &Zesp_Wyjscie);
LZespolona Oblicz(WyrazenieZesp  WyrZ);
std::istream &operator>>(std::istream &Wejscie, WyrazenieZesp &Zesp_Wejscie);
bool operator ==(const WyrazenieZesp &Zesp1, const WyrazenieZesp &Zesp2);

#endif
