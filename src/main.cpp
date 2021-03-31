#include "BazaTestu.hh"
#include <iostream>
#include "Statystyki.hh"



#include "LZespolona.hh"


// using namespace std;


int main(int argc, char **argv)
{
  // LZespolona zespolona;
  // zespolona.re = 10;
  // zespolona.im = 5;

  // LZespolona zespolona2;
  // zespolona2.re = 2;
  // zespolona2.im = 3;
  // LZespolona wynikzespolonej;
  // wynikzespolonej= zespolona /zespolona2;
  // std::cout << wynikzespolonej << std::endl;


  if (argc < 2) {
    std::cout << std::endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
    std::cout << std::endl;
    return 1;
  }

  // WyrazenieZesp Zesp1;
  // std::cin >> Zesp1;

  // std::cout << Oblicz(Zesp1) << std::endl;

  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
     std::cerr << " Inicjalizacja testu nie powiodla sie." <<  std::endl;
    return 1;
  }

  std::cout <<  std::endl;
  std::cout << " Start testu arytmetyki zespolonej: " << argv[1] <<  std::endl;
  std::cout <<  std::endl;
  int poprawna = 0, zla = 0, pomoc = 0;
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona odpowiedz;
  LZespolona rezultat;
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
     std::cout << " Oblicz : ";
     std::cout << WyrZ_PytanieTestowe << std::endl;
     std::cout << " Podaj odpowiedz : " << std::endl;
     while (pomoc < 3)
     { 
        try
        {
          std::cin >> odpowiedz ;
        }
        catch(const std::exception& e)
        { 
          pomoc++;
          std::cerr << e.what() << '\n';
          continue;
        }
        break;
     }
     
     rezultat = Oblicz(WyrZ_PytanieTestowe);
     if( odpowiedz == rezultat)
     {
       poprawna++;
     }
     else
     {
        zla++;
     }

  }
   std::cout <<  std::endl;
   std::cout << " Koniec testu" <<  std::endl;
   Podsumowanie(poprawna, zla);
   std::cout <<  std::endl;

}
