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
            if (current->val == ')' && tempPile.sommet() == '(') {
                tempPile.depile();
            } else {
                return false;
            }
            lastWasOperand = false;
        }
        else if (isalnum(current->val)) {
            if (lastWasOperand) return false; // Two operands in a row
            lastWasOperand = true;
        }
        else {
            lastWasOperand = false;
        }
        current = current->suivant.get();
    }

    return tempPile.estVide();
}

template <typename T>
double PPile<T>::solveEquation() {
    if (!checkEquation()) return 0;

    PPile<T> values;
    PPile<T> ops;
    auto current = sommetNoeud.get();

    while (current) {
        if (current->val == '(') {
            ops.empile(current->val);
        } else if (isdigit(current->val)) {
            values.empile(current->val - '0');
        } else if (current->val == ')') {
            while (!ops.estVide() && ops.sommet() != '(') {
                char op = ops.sommet();
                ops.depile();

                double val2 = values.sommet();
                values.depile();

                double val1 = values.sommet();
                values.depile();

                switch (op) {
                    case '+': values.empile(val1 + val2); break;
                    case '-': values.empile(val1 - val2); break;
                    case '*': values.empile(val1 * val2); break;
                    case '/': values.empile(val1 / val2); break;
                }
            }
            ops.depile();
        } else {
            while (!ops.estVide() && precedence(ops.sommet()) >= precedence(current->val)) {
                char op = ops.sommet();
                ops.depile();

                double val2 = values.sommet();
                values.depile();

                double val1 = values.sommet();
                values.depile();

                switch (op) {
                    case '+': values.empile(val1 + val2); break;
                    case '-': values.empile(val1 - val2); break;
                    case '*': values.empile(val1 * val2); break;
                    case '/': values.empile(val1 / val2); break;
                }
            }
            ops.empile(current->val);
        }
        current = current->suivant.get();
    }

    while (!ops.estVide()) {
        char op = ops.sommet();
        ops.depile();

        double val2 = values.sommet();
        values.depile();

        double val1 = values.sommet();
        values.depile();

        switch (op) {
            case '+': values.empile(val1 + val2); break;
            case '-': values.empile(val1 - val2); break;
            case '*': values.empile(val1 * val2); break;
            case '/': values.empile(val1 / val2); break;
        }
    }

    return values.sommet();
}

template <typename T>
int PPile<T>::precedence(char op) const {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

template class PPile<char>;
template class PPile<int>;
template class PPile<float>;
template class PPile<double>;