#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"
#include <sstream>

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.66667;
    y.im = 0.66667;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez liczbe zespolona") {
    LZespolona x, y, z;

    
    x.re = 2;
    x.im = 3;

    y.re = 2;
    y.im = 1;

    z.re = 1.4;
    z.im = 0.8;
   
    CHECK(x/y == z);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}
TEST_CASE("Test LZespolona sprzezenie") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = -2;

    y.re = 2;
    y.im = 2;
 
   CHECK(Sprzezenie(x) == y);
}
TEST_CASE("Test LZespolona sprzezenie z 0i") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 0;

    y.re = 2;
    y.im = 0;
 
   CHECK(Sprzezenie(x) == y);
}
TEST_CASE("Test LZespolona wyswietl") {
    LZespolona x;
    
    x.re = 2;
    x.im = 3.2;
    
   std::stringstream ss;
   ss << x;

   CHECK(ss.str()== "(2+3.2i)");
}
TEST_CASE("Test LZespolona wczytanie") {
    LZespolona x, y;
    y.re = 5.1;
    y.im = 4.9;

    std::stringstream ss2;
    ss2 << "(5.1+4.9i)";
    ss2 >> x;

    CHECK( x ==y );
}
TEST_CASE("Test WyrazenieZespolone wyswietlenie") {
    WyrazenieZesp x;

    x.Arg1 = LZespolona{3,2.1};
    x.Op = Op_Dodaj;
    x.Arg2 = LZespolona{2,5.7};
    
   std::stringstream ss;
   ss << x;

   CHECK(ss.str()== "(3+2.1i)+(2+5.7i)");
}
TEST_CASE("Test WyrazenieZespolone wczytywanie") {
    WyrazenieZesp x, y;

    y = {{3.2,5}, Op_Odejmij, {2,3.7}};
    
    std::stringstream ss2;
    ss2 << "(3.2+5i)-(2+3.7i)";
    ss2 >> x;

   CHECK(ss2.str()== "(3.2+5i)-(2+3.7i)");
}
TEST_CASE("Test LZespolona sprzezenie z 0i") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 0;

    y.re = 2;
    y.im = 0;
 
   CHECK(Sprzezenie(x) == y);
}
TEST_CASE("Test LZespolona modul") {
    LZespolona x;
    
    x.re = 1.2;
    x.im = 4;
    

   CHECK(Modul2(x)== 17.44);
}

TEST_CASE("Test wyliczanie % statystyki"){
    int dobrze = 3, zle = 2 ;
    double x = Podsumowanie(dobrze, zle);
    
    CHECK( x == 60); 
}

