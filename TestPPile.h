#ifndef TESTPPILE_H
#define TESTPPILE_H

#include <iostream>
#include "Pile.h"

using namespace std;

template <typename T>
class TestPPile {
public:
    void testEstVide();
    void testEmpile();
    void testDepile();
    void testSommet();
    void testAffiche();
    void testInvertStack();
    void testIsPalindrome();
    void testCheckEquation();
};

#endif // TESTPPILE_H