#include <pybind11/pybind11.h>
#include <stdexcept>
#include <string>
#include <vector>

namespace py = pybind11;

template <typename T>
class StaticArrayList {
private:
    T* data;
    int max_size;
    int size;

public:
    StaticArrayList(int max_size) : max_size(max_size), size(0) {
        data = new T[max_size];
    }

    ~StaticArrayList() {
        delete[] data;
    }

    bool Empty() const {
        return size == 0;
    }

    void PushFront(const T& element) {
        if (size >= max_size) throw std::overflow_error("List is full");
        for (int i = size; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = element;
        size++;
    }

    void PushBack(const T& element) {
        if (size >= max_size) throw std::overflow_error("List is full");
        data[size++] = element;
    }

    void PopFront() {
        if (Empty()) throw std::underflow_error("List is empty");
        for (int i = 0; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void PopBack() {
        if (Empty()) throw std::underflow_error("List is empty");
        size--;
    }

    bool Find(const T& element) const {
        for (int i = 0; i < size; ++i) {
            if (data[i] == element) return true;
        }
        return false;
    }

    void Erase(const T& element) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (data[i] == element) {
                index = i;
                break;
            }
        }
        if (index == -1) throw std::runtime_error("Element not found");

        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void AddBefore(const T& target, const T& element) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (data[i] == target) {
                index = i;
                break;
            }
        }
        if (index == -1) throw std::runtime_error("Target not found");

        if (size >= max_size) throw std::overflow_error("List is full");

        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = element;
        size++;
    }

    void AddAfter(const T& target, const T& element) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (data[i] == target) {
                index = i;
                break;
            }
        }
        if (index == -1) throw std::runtime_error("Target not found");

        if (size >= max_size) throw std::overflow_error("List is full");

        for (int i = size; i > index + 1; --i) {
            data[i] = data[i - 1];
        }
        data[index + 1] = element;
        size++;
    }

    std::string PrintList() const {
        std::string output = "{ ";
        for (int i = 0; i < size; ++i) {
            output += std::to_string(data[i]);
            if (i < size - 1) output += ", ";
        }
        output += " }";
        return output;
    }
};

PYBIND11_MODULE(static_array_list, m) {
    py::class_<StaticArrayList<int>>(m, "StaticArrayList")
        .def(py::init<int>())
        .def("empty", &StaticArrayList<int>::Empty)
        .def("push_front", &StaticArrayList<int>::PushFront)
        .def("push_back", &StaticArrayList<int>::PushBack)
        .def("pop_front", &StaticArrayList<int>::PopFront)
        .def("pop_back", &StaticArrayList<int>::PopBack)
        .def("find", &StaticArrayList<int>::Find)
        .def("erase", &StaticArrayList<int>::Erase)
        .def("add_before", &StaticArrayList<int>::AddBefore)
        .def("add_after", &StaticArrayList<int>::AddAfter)
        .def("print_list", &StaticArrayList<int>::PrintList);
}
