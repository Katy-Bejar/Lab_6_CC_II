#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Iterator.h"
using namespace std;

int main(){
    //cout << "Lista ordenada "<<endl;
    LinkedList<string> lista;
    lista.push_front("Carlos");
    lista.push_front("Luisa");
    lista.push_back("Carmen");
    lista.push_back("Mario");
    lista.push_front("Nadia");
    lista.push_front("Juan");
	cout << lista << endl;

    lista.removeByPosition(2);
    cout << lista << endl;

    lista.pop_front();
    cout << lista << endl;

    lista.push_back("Fabiola");
    cout << lista << endl;

    lista.push_back("Luis");
    cout << lista << endl;

    lista.push_front("Pedro");
    cout << lista << endl;

    lista.pop_front();
    cout << lista << endl;

    //LinkedList<string> list;
    Iterator<string, LinkedList<string>> it(&lista);
    for (it = lista.begin(); it != lista.end(); ++it){
        cout << *it << endl;
    }

    //LinkedList b = move(lista);

    return 0;
}
