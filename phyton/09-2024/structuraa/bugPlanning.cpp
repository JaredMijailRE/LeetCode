#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class SIA {
public:
    class StaticStack {
    private:
        vector<int> data;
        int size;

    public:
        StaticStack(int capacity) : data(capacity, 0), size(0) {}

        void pop() {
            if (size == 0) {
                cout << "No element to delete" << endl;
            } else {
                --size;
            }
        }

        void add(int value) {
            if (size == data.size()) {
                cout << "List is full" << endl;
            } else {
                data[size++] = value;
            }
        }

        int getLast() const {
            if (size > 0) {
                return data[size - 1];
            } else {
                throw runtime_error("Stack is empty");
            }
        }

        void printList() const {
            for (int i = 0; i < size; ++i) {
                cout << data[i];
                if (i < size - 1) cout << " ";
            }
            cout << endl;
        }

        int getSize() const {
            return size;
        }
    };

    void gis(const vector<int>& data, int size) {
        StaticStack answer(size);
        answer.add(data[0]);

        for (size_t i = 1; i < data.size(); ++i) {
            if (data[i] > answer.getLast()) {
                answer.add(data[i]);
            }
        }

        cout << answer.getSize() << endl;
        answer.printList();
    }
};

int main() {
    SIA answer;
    int size;
    cin >> size;
    vector<int> data(size);

    for (int i = 0; i < size; ++i) {
        cin >> data[i];
    }

    answer.gis(data, size);

    return 0;
}
