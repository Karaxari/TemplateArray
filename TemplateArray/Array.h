#pragma once
#include<iostream>
using namespace std;

template <typename T> class Array
{
private:
    int _length{};
    T* _array{};

public:
    Array() = default;
    Array(int length);
    Array(const Array& a);
    ~Array();

    void erase();

    T& operator[](int index);
    void reallocate(int newLength);

    void resize(int newLength);
    Array& operator=(const Array& a);
    void insertBefore(T value, int index);
    void remove(int index);
    void showArray();
    T findElement(T num);

    void insertAtBeginning(T value) { insertBefore(value, 0); }
    void insertAtEnd(T value) { insertBefore(value, _length); }

    int getLength() const { return _length; }
};