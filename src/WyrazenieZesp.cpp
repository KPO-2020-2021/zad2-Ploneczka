#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    LZespolona Wynik;
    if( WyrZ.Op == Op_Dodaj)
    {
    Wynik = WyrZ.Arg1 + WyrZ.Arg2;
    }
    else if ( WyrZ.Op == Op_Odejmij)
    {
        Wynik = WyrZ.Arg1 - WyrZ.Arg2;
    }
    else if ( WyrZ.Op == Op_Mnoz)
    {
        Wynik = WyrZ.Arg1 * WyrZ.Arg2;
    }
    else if ( WyrZ.Op == Op_Dziel)
    {
        Wynik = WyrZ.Arg1 / WyrZ.Arg2;
    }
    return Wynik;
}

std::ostream &operator <<(std::ostream &Wyjscie, const WyrazenieZesp &Zesp_Wyjscie)
{
    Wyjscie << Zesp_Wyjscie.Arg1;
    if (Wyjscie.fail())
    {
        throw std::system_error();
    }
    Wyjscie << Zesp_Wyjscie.Op;
    if (Wyjscie.fail())
    {
        throw std::system_error();
    }
    Wyjscie << Zesp_Wyjscie.Arg2;
    if (Wyjscie.fail())
    {
        throw std::system_error();
    }
    return Wyjscie;
}
std::istream &operator >>(std::istream &Wejscie, WyrazenieZesp &Zesp_Wejscie)
{
  
    Wejscie >> Zesp_Wejscie.Arg1;
    if (Wejscie.fail())
    {
        throw std::invalid_argument("1");
    }
    Wejscie >> Zesp_Wejscie.Op;
    if (Wejscie.fail())
    {
        throw std::invalid_argument("3");
    }
    Wejscie >> Zesp_Wejscie.Arg2;
    if (Wejscie.fail())
    {
        throw std::invalid_argument("4");
    }
    return Wejscie;
}
bool operator ==(const WyrazenieZesp &Zesp1, const WyrazenieZesp &Zesp2)
{
    if ( Zesp1.Arg1 == Zesp2.Arg1 && Zesp1.Op == Zesp2.Op && Zesp1.Arg2 == Zesp2.Arg2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
std::istream & operator>>(std::istream &Wejscie, Operator &oper)
{
    char pomoc;

    Wejscie >> pomoc;
    switch (pomoc)
    {
    case '+':
        oper = Op_Dodaj;
        break;
    case '-':
        oper = Op_Odejmij;
        break;
    case '*':
        oper = Op_Mnoz;
          break;
    case '/':
        oper = Op_Dziel;
          break;
    default:
        throw std::invalid_argument("5");
        break;
    }
    return Wejscie;
}
std::ostream & operator<<(std::ostream &Wyjscie, const Operator &oper)
{
    if ( oper == Op_Dodaj)
    {
        Wyjscie << '+';
    }
    else if ( oper == Op_Odejmij)
    {
        Wyjscie << '-';
    }
     else if ( oper == Op_Mnoz)
    {
        Wyjscie << '*';
    }
     else if ( oper == Op_Dziel)
    {
        Wyjscie << '/';
    }
    else{
        throw std::system_error();
    }
    return Wyjscie;
}