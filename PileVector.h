#ifndef PILE_H
#define PILE_H

#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
class VPile {
private:
    vector<T> elements;
public:
    PPile() = default;
    bool estVide() const;
    void empile(T val);
    void depile();
    T sommet() const;
    void affiche();
    void invertStack();
    bool isPalindrome();
};



#endif // PILE_H
