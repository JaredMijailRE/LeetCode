#include <iostream>
#include "string"
using namespace std;
// -> acceso a miembros

struct Node {
    int data;       
    Node* next;     

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() : head(nullptr) {}

        void pushFront(int key){ // add to front
            Node* nodo = new Node(key); // save new node pointer in node
            nodo->next = head; // new node points to the old head
            head = nodo; // head points to new node
        }

        int keyFront(){ // return front item
            return head == nullptr ? // operador ternario
            throw std::runtime_error("List is empty") : head->data;  // if not null return data from head
        }

        void popFront(){ // remove front item
            if (head != nullptr){ // if list not null
                head = head->next;  // new head pointer to next node
            }else{
                throw std::runtime_error("List is empty");
            }
        }

        void pushBack(int key){ // add to back
            Node* temp = head;
            Node* nodo = new Node(key);
            if(head != nullptr){
                while(temp->next != nullptr){ // loop to find null pointer
                    temp = temp->next; // get next reference
                }
                temp->next = nodo; // asign to back next node
            }else head = temp;
        }

        int keyTopBack(){ // return back item
            if(head != nullptr){
                Node* temp = head;
                while(temp->next != nullptr){ // loop to find null pointer
                    temp = temp->next; // get next reference
                }
                return temp->data; // return data dinal node
            }else{
                throw std::runtime_error("List is empty");
            }
        }

        int popBack(){ // remove back item
            if(head != nullptr){
                Node* temp = head;
                while(temp->next != nullptr){ // loop to find null pointer
                    if(temp->next->next == nullptr){
                        temp->next = nullptr;
                        return 0;
                    }
                    temp = temp->next->next; // get next reference
                }
                temp = nullptr;
                return 0;
            }else{
                throw std::runtime_error("List is empty");
                return 0;
            }
        }

        bool booleanFind(int key){ // is key in list?
            if(head != nullptr){
                Node* temp = head;
                while(temp != nullptr){ // loop to find null pointer
                    if(key == temp->data){
                        return true;
                    }
                    temp = temp->next; // get next reference
                }
            }
            return false;
        }

        int erase(int key){ // remove key from list
            Node* temp = head;
            while(temp != nullptr){
                if(temp->data == key){

                }
            }
            throw std::runtime_error("Key doesnt exist");

        }

        bool booleanEmpty(){ // empty list?
            if(head != nullptr){
                return false;
            }else return true;
        }

        void addBefore(Node* node ,int key){ // adds key before node
        Node* temp1 = head;
        Node* temp2;
            if(temp1 != nullptr){
                while(true){ // loop to find null pointer
                    if(temp1 == node) temp1->next = temp2->next;
                    temp2 = temp1->next; // get next reference
                    if(temp2 == nullptr ) break;
                    if(temp1->data == key) temp2->next = temp1->next;
                    temp1 = temp2->next; // get next+1 reference
                    if(temp1 == nullptr ) break;
                    
                }
            throw std::runtime_error("That reference to a node wasnt found");

        }}

        void addAfter(Node* node  ,int key){ // adds key after node
            Node* newNodo = new Node(key);
            newNodo->next = node->next;
            node->next = newNodo;
        }

        void printList(){
            char texto;
            if(head != nullptr){
                Node* temp = head; 
                texto = texto + char(temp->data);
                while(temp != nullptr){ // loop to find null pointer
                    texto = texto + ', ';
                    temp = temp->next; // get next reference
                }
            }
            cout << '{' << texto << '}';
        }
};