#include <iostream>

using namespace std;

template <typename T>
class stack {
public:
    stack (int size): Size(size), top(-1) {
        arr = new T[size];
    }

    stack (const stack &s) : Size(s.Size), top(s.top) {
        arr = new T[Size];
        for (int i = 0; i <= s.top; i++) {
            arr[i] = s.arr[i];
        }
    }

    ~stack () {
        delete[] arr;
    }

    const stack & operator = (const stack &s) {
        for (int i = 0; i <= s.top; i++) {
            arr[i] = s.arr[i];
        }
        top = s.top;
        return *this;
    }

    bool empty () {
        if (top == -1) return true;
        return false;
    }

    void push (const T &x) {
        arr[++top] = x;
    }

    T pop () {
        return arr[top--];
    }

    int size () {
        return Size;
    }

friend ostream & operator << (ostream &out, const stack &s) {
    out << "[";
    for (int i = 0; i < s.top; i++) {
        out << s.arr[i] << ", ";
    }
    out << s.arr[s.top] << "]";
    return out;
}
private:
    int top;
    int Size;
    T* arr;
};

