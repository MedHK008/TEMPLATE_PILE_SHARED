#include "Pile.h"



template <typename T>
Noeud<T>::Noeud(T value) : val(value), suivant(nullptr) {}

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
        cout << sommet() << " ";
        tempPile.empile(sommetNoeud->val);
        depile();
    }
    cout << endl;
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

template <typename T>
inline bool PPile<T>::isPalindrome(){
    if (estVide()) return true;

    PPile<T> tempPile;
    PPile<T> reversedPile;
    auto current = sommetNoeud.get();

    while (current) {
        tempPile.empile(current->val);
        reversedPile.empile(current->val);
        current = current->suivant.get();
    }

    reversedPile.invertStack();

    while (!tempPile.estVide() && !reversedPile.estVide()) {
        if (tempPile.sommet() != reversedPile.sommet()) {
            return false;
        }
        tempPile.depile();
        reversedPile.depile();
    }

    return true;
}

template <typename T>
inline bool PPile<T>::checkEquation() {
    if (estVide()) return true;
    invertStack();
    PPile<T> tempPile;
    auto current = sommetNoeud.get();
    bool lastWasOperand = false;

    while (current) {
        if (current->val == '(') {
            tempPile.empile(current->val);
            lastWasOperand = false;
        }
        else if (current->val == ')') {
            if (tempPile.estVide()) return false;
            if (tempPile.sommet() == '(') {
                tempPile.depile();
            } else {
                return false;
            }
            lastWasOperand = false;
        }
        else if (isdigit(current->val)) {
            if (lastWasOperand) return false;
            lastWasOperand = true;
        }
        else if (current->val == '+' || current->val == '-' || current->val == '*' || current->val == '/') {
            lastWasOperand = false;
        } else {
            return false;
        }
        current = current->suivant.get();
    }

    return tempPile.estVide();
}

template class PPile<char>;
template class PPile<int>;
template class PPile<float>;
template class PPile<double>;