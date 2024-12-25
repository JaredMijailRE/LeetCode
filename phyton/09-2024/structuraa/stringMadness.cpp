#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class LinkedList {
public:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        while (!booleanEmpty()) {
            popFront();
        }
    }
    bool booleanEmpty() const {
        return head == nullptr;
    }
    void pushFront(int key) {
        Node* nodo = new Node(key);
        nodo->next = head;
        head = nodo;
    }
    void popFront() {
        if (head == nullptr)
            throw runtime_error("Lista vacía. No se puede eliminar el elemento del frente.");
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void print(const vector<string> posts) const {
        Node* temp = head;
        bool first = true;  
        while (temp != nullptr) {
            if (!first) cout << " ";  
            cout << (posts[temp->data]);
            first = false;
            temp = temp->next;
        }
        cout << endl; 
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> posts(N);
    vector<LinkedList> linked(N);
    for (int i = 0; i < N; i++) {
        cin >> posts[i];
        LinkedList space;
        space.pushFront(i);
        linked[i] = space;
    }
    LinkedList space;
    space.pushFront(N); 
    int last;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; 
        last = a;
        if (linked[b].head->data != N) {
            linked[a].pushFront(b);
        }
        linked[b] = space;
    }
    linked[last].print(posts); 

    return 0;
}
