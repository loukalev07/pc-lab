#include <iostream>

using namespace std;

template <typename T>
class Stack {
public:
    Stack (int size): cap(size), top(-1) {
        arr = new T[cap];
    }

    Stack (const Stack &s) : cap(s.cap), top(s.top) {
        arr = new T[cap];
        for (int i = 0; i <= s.top; i++) {
            arr[i] = s.arr[i];
        }
    }

    ~Stack () {
        delete[] arr;
    }

    const Stack & operator = (const Stack &s) {
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
        return (top + 1);
    }

friend ostream & operator << (ostream &out, const Stack &s) {
    out << "[";
    for (int i = 0; i < s.top; i++) {
        out << s.arr[i] << ", ";
    }
    if (s.top > -1) {
        out << s.arr[s.top];
    }
    out << "]";
    return out;
}
private:
    int top;
    int cap;
    T* arr;
};


