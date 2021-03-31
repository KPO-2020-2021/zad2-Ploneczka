#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
//Test LZespolona ==
TEST_CASE("test LZespolona porownanie true"){
    LZespolona x, y;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 1;
  
    CHECK(x == y);
}
TEST_CASE("test LZespolona porownanie false"){
    LZespolona x, y;

    x.re = 1;
    x.im = 1;

    y.re = 2;
    y.im = 2;
  
    CHECK_FALSE(x == y);
}
TEST_CASE("test LZespolona porownanie min false"){
    LZespolona x, y;

    x.re = 1.0001;
    x.im = 1.2007;

    y.re = 1.0008;
    y.im = 1.2000;
  
    CHECK_FALSE(x == y);
}
TEST_CASE("test LZespolona porownanie min false"){
    LZespolona x, y;

    x.re = 1.000001;
    x.im = 1.200001;

    y.re = 1.000003;
    y.im = 1.200000;
  
    CHECK(x == y);
}
//LZesp operator +
TEST_CASE("test LZespolona 1+"){
    LZespolona x, y, z;

    x.re = 1.1;
    x.im = 1.2;

    y.re = 0;
    y.im = 0;

    z.re = 1.1;
    z.im = 1.2;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona 2+"){
    LZespolona x, y, z;

    x.re = 1.1;
    x.im = 1.2;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 1.1;
    z.im = 1.2;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona 3+"){
    LZespolona x, y, z;

    x.re = 1.1;
    x.im = 1.2;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 1.10001;
    z.im = 1.20001;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona 4+"){
    LZespolona x, y, z;

    x.re = 0.00009;
    x.im = 0.00009;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.0001;
    z.im = 0.0001;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}
// LZesp operator -
TEST_CASE("test LZespolona 1-"){
    LZespolona x, y, z;

    x.re = 2.1;
    x.im = 2.2;

    y.re = 0;
    y.im = 0;

    z.re = 2.1;
    z.im = 2.2;
    
    CHECK(x-y == z);
}
TEST_CASE("test LZespolona 2-"){
    LZespolona x, y, z;

    x.re = 2.1;
    x.im = 2.2;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 2.1;
    z.im = 2.2;
    
    CHECK(x-y == z);
}
TEST_CASE("test LZespolona 3-"){
    LZespolona x, y, z;

    x.re = 1.1;
    x.im = 1.2;

    y.re = 0.000001;
    y.im = 0.000001;

    z.re = 1.1;
    z.im = 1.2;
    
    CHECK(x-y == z);
}
TEST_CASE("test LZespolona 4-"){
    LZespolona x, y, z;

    x.re = 0.009;
    x.im = 0.009;

    y.re = 0.001;
    y.im = 0.001;

    z.re = 0.008;
    z.im = 0.008;
    
    CHECK(x-y == z);
}
TEST_CASE("test LZespolona Odejmowanie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 0;
    z.im = 4;
    
    CHECK(x-y == z);
}
// LZesp operator *
TEST_CASE("test LZespolona 1*"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
    
    CHECK(x*y == z);
}
TEST_CASE("test LZespolona 2*"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 1;

    y.re = 1;
    y.im = 0;

    z.re = 2;
    z.im = 1;
    
    CHECK(x*y == z);
}
TEST_CASE("test LZespolona 3*"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 1;

    y.re = 0;
    y.im = 1;

    z.re = -1;
    z.im = 2;
    
    CHECK(x*y == z);
}
TEST_CASE("test LZespolona 4*"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 1;

    y.re = 1;
    y.im = 1;

    z.re = 1;
    z.im = 3;
    
    CHECK(x*y == z);
}