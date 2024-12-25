#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Nodo {
    string dato;
    Nodo* siguiente;
    
    Nodo(string dato) : dato(dato), siguiente(nullptr) {}
};

class LinkedList {
public:
    Nodo* cabeza;
    Nodo* cola;

    LinkedList() : cabeza(nullptr), cola(nullptr) {}

    void addNode(const string& dato) {
        Nodo* nuevoNodo = new Nodo(dato);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        } else {
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
    }

    void addList(LinkedList* otra) {
        if (otra->cabeza == nullptr) {
            return;
        }
        if (cabeza == nullptr) {
            cabeza = otra->cabeza;
            cola = otra->cola;
        } else {
            cola->siguiente = otra->cabeza;
            cola = otra->cola;
        }
        otra->cabeza = nullptr;
        otra->cola = nullptr;
    }

    void print() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->dato;
            actual = actual->siguiente;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<LinkedList*> listas(n + 1);
    for (int i = 1; i <= n; i++) {
        listas[i] = new LinkedList();
        string linea;
        getline(cin, linea);
        listas[i]->addNode(linea);
    }

    int indiceResultado = 1;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cin.ignore();
        listas[a]->addList(listas[b]);
        indiceResultado = a;
    }

    listas[indiceResultado]->print();
    for (int i = 1; i <= n; i++) {
        delete listas[i];
    }

    return 0;
}
