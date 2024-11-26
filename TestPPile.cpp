#include "TestPPile.h"

template <typename T>
void TestPPile<T>::testEstVide() {
    PPile<T> pile;
    cout << "Test estVide: " << (pile.estVide() ? "Pass" : "Fail") << endl;
}

template <typename T>
void TestPPile<T>::testEmpile() {
        PPile<T> pile;
        pile.empile(1);
        cout << "Test empile: " << (pile.sommet() == 1 ? "Pass" : "Fail") << endl;
    }

template <typename T>
void TestPPile<T>::testDepile() {
        PPile<T> pile;
        pile.empile(1);
        pile.depile();
        cout << "Test depile: " << (pile.estVide() ? "Pass" : "Fail") << endl;
    }

template <typename T>
void TestPPile<T>::testSommet() {
        PPile<T> pile;
        pile.empile(1);
        cout << "Test sommet: " << (pile.sommet() == 1 ? "Pass" : "Fail") << endl;
    }

template <typename T>
void TestPPile<T>::testAffiche() {
        PPile<T> pile;
        pile.empile(1);
        pile.empile(2);
        cout << "Test affiche: ";
        pile.affiche();
    }

template <typename T>
void TestPPile<T>::testInvertStack() {
        PPile<T> pile;
        pile.empile(1);
        pile.empile(2);
        pile.invertStack();
        cout << "Test invertStack: " << (pile.sommet() == 1 ? "Pass" : "Fail") << endl;
    }

template <typename T>
void TestPPile<T>::testIsPalindrome() {
        PPile<T> pile;
        pile.empile(1);
        pile.empile(2);
        pile.empile(1);
        cout << "Test isPalindrome: " << (pile.isPalindrome() ? "Pass" : "Fail") << endl;
    }

template <typename T>
void TestPPile<T>::testCheckEquation() {
        PPile<char> pile;
        pile.empile('(');
        pile.empile('3');
        pile.empile('+');
        pile.empile('4');
        pile.empile(')');
        cout << "Test checkEquation: " << (pile.checkEquation() ? "Pass" : "Fail") << endl;
    }

template class TestPPile<int>;
template class TestPPile<char>;
template class TestPPile<float>;
template class TestPPile<double>;