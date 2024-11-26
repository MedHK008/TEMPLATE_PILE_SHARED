#include "PileVector.h"

template <typename T>
bool VPile<T>::estVide() const {
    return elements.empty();
}

template <typename T>
void VPile<T>::empile(T val) {
    elements.push_back(val);
}

template <typename T>
void VPile<T>::depile() {
    if (!elements.empty()) {
        elements.pop_back();
    } else {
        cout << "Pile is empty" << endl;
    }
}

template <typename T>
T VPile<T>::sommet() const {
    if (!elements.empty()) {
        return elements.back();
    } else {
        cout << "Pile is empty" << endl;
        exit (-1);
    }
}

template <typename T>
void VPile<T>::affiche() {
    vector<T> temp;
    while (!elements.empty()) {
        T val = elements.back();
        cout << val << " " << ;
        temp.push_back(val);
        elements.pop_back();
    }
    cout << endl;
    while (!temp.empty()) {
        T val = elements.back();
        elements.push_back(val);
        temp.pop_back();
    }
}

template <typename T>
void VPile<T>::invertStack() {
    reverse(elements.begin(), elements.end());
}

template <typename T>
bool VPile<T>::isPalindrome() {
    return equal(elements.begin(), elements.begin() + elements.size() / 2, elements.rbegin());
}

template class VPile<int>;
template class VPile<char>;
template class VPile<float>;
template class VPile<double>;
template class VPile<string>;
