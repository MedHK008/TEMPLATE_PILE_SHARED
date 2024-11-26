#ifndef PILE_H
#define PILE_H

#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>

class Noeud {
public:
    T val;
    unique_ptr<Noeud<T>> suivant;
    Noeud(T value);
};

template <typename T>
class PPile {
private:
    unique_ptr<Noeud<T>> sommetNoeud;
public:
    PPile() = default;
    bool estVide() const;
    void empile(T val);
    void depile();
    T sommet() const;
    void affiche();
    void invertStack();
    bool isPalindrome();
    bool checkEquation();
};



#endif // PILE_H
