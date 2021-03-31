#include "LZespolona.hh"


/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
  // if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
  //   return true;
  // else
  //   return false;
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika

  
  if ((std::abs(Skl1.re - Skl2.re) <= MIN_DIFF) && (std::abs(Skl1.im - Skl2.im) <= MIN_DIFF))
    return true;
  else
    return false;
  
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return
   Wynik;
}
/*Odejmowanie liczb
*/
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return
   Wynik;
}
/*Mnozenie liczb*/
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im*Skl2.im;
  Wynik.im = Skl1.re*Skl2.im + Skl1.im*Skl2.re;
  return
   Wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator/(LZespolona Skl1, double Skl2)
{
  LZespolona Wynik;
  if ( Skl2 == 0)
  {
    throw std::runtime_error("Nie dizel przez 0.");
  }
  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;

  return Wynik;
}
LZespolona  operator / (LZespolona  Skl1,  LZespolona Skl2){
  LZespolona  Wynik;
  LZespolona modul;
  if(Skl2 == LZespolona{0,0})
  {
    throw std::runtime_error("Nie dziel przez 0");
  }
  modul.re = 1 / Modul2(Skl2);
  modul.im = 0;

  Wynik = Skl1 * Sprzezenie(Skl2) * modul;
  return Wynik;
}
LZespolona Sprzezenie(LZespolona zespolona)
{
  LZespolona Wynik;
  Wynik.re = zespolona.re;
  Wynik.im = zespolona.im * (-1);
  return  Wynik;
}

double Modul2(LZespolona zespolona)
{
  double Wynik;
  Wynik = zespolona.re * zespolona.re + zespolona.im * zespolona.im;
  return Wynik;
}

void Wyswietl(LZespolona *zespolona)
{
  if(zespolona->im  > 0)
  {
    std::cout << "(" << zespolona->re << "+" << zespolona->im << "i" <<")";
  }
  else if(zespolona->im == 0)
  {
    std::cout << "(" << zespolona->re << ")";
  }
  else
  {
  std::cout << "(" << zespolona->re << zespolona->im << "i" <<")";
  }
}

std::ostream &operator<<(std::ostream &Wyjscie, const LZespolona &Zesp_Wyjscie)
{
  if( Zesp_Wyjscie.im >= 0)
  {
  Wyjscie << "(" << Zesp_Wyjscie.re << "+" << Zesp_Wyjscie.im << "i)";
  }
  else if(Zesp_Wyjscie.im == 0)
  {
    Wyjscie << "(" << Zesp_Wyjscie.re << ")";
  }
  else
  {
  Wyjscie << "(" << Zesp_Wyjscie.re << Zesp_Wyjscie.im << "i)";
  }
  return Wyjscie;
}
std::istream &operator>>(std::istream &Wejscie, LZespolona &Zesp_Wejscie)
{
  char smietnik, smietnik2;
  double rzeczysita, urojona;
  char znak, i;

  Wejscie >> smietnik;
  Wejscie >> rzeczysita;
  Wejscie >> znak; 
  Wejscie >> urojona;
  Wejscie >> i;
  Wejscie >> smietnik2;

  if (znak == '+')
  {
    Zesp_Wejscie.re = rzeczysita;
    Zesp_Wejscie.im = urojona;
  }
  else if (znak == '-')
  {
    Zesp_Wejscie.re = rzeczysita;
    Zesp_Wejscie.im = urojona * (-1);
  }
  if(smietnik != '(' || smietnik2 != ')')
  {
    throw std::runtime_error("zly nawias");
  }
  return Wejscie;
}
