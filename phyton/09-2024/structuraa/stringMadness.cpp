#include <iostream>
#include <vector>
#include <string>
using namespace std;
class StaticStack {
private:
    vector<string> data;
    int size;
public:
    StaticStack(int capacity) : data(capacity), size(0) {}
    void add(const string& value) {
        if (size == data.size()) {
            cout << "list is full" << endl;
        } else {
            data[size] = value;
            size++;
        }
    }
    void pop() {
        if (size == 0) {
            cout << "No element to delete" << endl;
        } else {
            size--;
        }
    }
    string& at(int index) {
        return data[index];
    }
};
int main() {
    int size;
    cin >> size;
    int last = 0;
    StaticStack words(size);
    for (int n = 0; n < size; n++) {
        string word;
        cin >> word;
        words.add(word);
    }
    for (int n = 0; n < size - 1; n++) {
        int index1, index2;
        cin >> index1 >> index2;
        index1--; 
        index2--;
        words.at(index1) += words.at(index2);
        words.at(index2) = "";
        last = index1 + 1; 
    }
    cout << words.at(last - 1) << endl;
    return 0;
}