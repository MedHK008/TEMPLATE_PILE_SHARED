#include <iostream>
#include <vector>
#include <chrono>
#include "Pile.h"

using namespace std;
using namespace std::chrono;

void testSimpleVector() {
    const vector<int> vec = {1, 2, 3, 4, 5};

    auto start = high_resolution_clock::now();

    cout << vec.size() << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Simple vector operations took " << duration << " microseconds." << endl;
}

void testComplexVector() {
    vector<int> vec;

    for (int i = 0; i < 10000; i++) {
        vec.push_back(i);
    }


    const auto start = high_resolution_clock::now();

    cout << vec.size() << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Complex vector operations took " << duration << " microseconds." << endl;
}

class TestPPile {
public:
    void testCheckEquation() {
        PPile<char> pile1;
        pile1.empile('(');
        pile1.empile('3');
        pile1.empile('+');
        pile1.empile('4');
        pile1.empile(')');
        pile1.empile('*');
        pile1.empile('(');
        pile1.empile('5');
        pile1.empile('-');
        pile1.empile('2');
        pile1.empile(')');
        pile1.invertStack();
        pile1.affiche();
        if(pile1.checkEquation())
            {
            cout << "result is : " << pile1.solveEquation() << endl;}
        else
            cout << "Invalid equation" << endl;

        PPile<char> pile2;
        pile2.empile('(');
        pile2.empile('3');
        pile2.empile('+');
        pile2.empile('4');
        pile2.empile('*');
        pile2.empile('(');
        pile2.empile('5');
        pile2.empile('-');
        pile2.empile('2');
        pile2.empile(')');
        pile2.invertStack();
        pile2.affiche();
        if(pile2.checkEquation())
            {
            cout << "result is : " << pile2.solveEquation() << endl;}
        else
            cout << "Invalid equation" << endl;

        PPile<char> pile3;
        pile3.empile('3');
        pile3.empile('+');
        pile3.empile('4');
        pile3.empile('*');
        pile3.empile('5');
        pile3.empile('-');
        pile3.empile('2');
        pile3.invertStack();
        pile3.affiche();
        if(pile3.checkEquation())
            {
            cout << "result is : " << pile3.solveEquation() << endl;}
        else
            cout << "Invalid equation" << endl;

        PPile<char> pile4;
        pile4.empile('(');
        pile4.empile('3');
        pile4.empile('+');
        pile4.empile('4');
        pile4.empile(')');
        pile4.empile('*');
        pile4.empile('(');
        pile4.empile('5');
        pile4.empile('-');
        pile4.empile('2');
        pile4.empile(')');
        pile4.empile(')');
        pile4.invertStack();
        pile4.affiche();
        if(pile4.checkEquation())
            {
            cout << "result is : " << pile4.solveEquation() << endl;}
        else
            cout << "Invalid equation" << endl;
    }
};

int main() {

    TestPPile tester;
    tester.testCheckEquation();

    return 0;
}
