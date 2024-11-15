#ifndef PILE_H
#define PILE_H

#include <memory>
#include <iostream>
using namespace std;

template <typename T>
class Noeud {
public:
    T val;
    unique_ptr<Noeud<T>> suivant;

    Noeud(T value) : val(value), suivant(nullptr) {}
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
};

template <typename T>
inline bool PPile<T>::estVide() const { return (!sommetNoeud); }

template <typename T>
inline void PPile<T>::empile(T val) {
    auto nouveau = make_unique<Noeud<T>>(val);
    nouveau->suivant = move(sommetNoeud);
    sommetNoeud = move(nouveau);
}

template <typename T>
inline void PPile<T>::depile() {
    if (estVide())
        cout << "pile vide" << endl;
    else
        sommetNoeud = move(sommetNoeud->suivant);
}

template <typename T>
inline T PPile<T>::sommet() const {
    return estVide() ? T() : sommetNoeud->val;
}

template <typename T>
inline void PPile<T>::affiche() {
    PPile<T> tempPile;
    while (!estVide()) {
        cout << sommet() << endl;
        tempPile.empile(sommetNoeud->val);
        depile();
    }
    while (!tempPile.estVide()) {
        empile(tempPile.sommet());
        tempPile.depile();
    }
}

template <typename T>
inline void PPile<T>::invertStack() {
    PPile<T> q;
    while (!estVide()) {
        q.empile(sommet());
        depile();
    }
    sommetNoeud = move(q.sommetNoeud);
}

#endif // PILE_H
