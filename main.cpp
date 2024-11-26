#include <iostream>
#include <vector>
#include <chrono>
#include "Pile.h"
#include "TestPPile.h"

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

int main() {
    TestPPile<int> tester;
    tester.testEstVide();
    tester.testEmpile();
    tester.testDepile();
    tester.testSommet();
    tester.testAffiche();
    tester.testInvertStack();
    tester.testIsPalindrome();
    tester.testCheckEquation();

    return 0;
}
