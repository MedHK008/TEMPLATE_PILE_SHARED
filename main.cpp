#include <iostream>
#include <memory>
#include "Pile.h"

using namespace std;

int main() {

    PPile<int>* myStack = new PPile<int>();
    myStack->empile(10);
    myStack->empile(20);
    myStack->empile(30);

    cout << "La pile initiale est :" << endl;
    myStack->affiche();

    myStack->invertStack();

    cout << "L'inverse de la pile est : " << endl;
    myStack->affiche();
    
    return 0;
}
