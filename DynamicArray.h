#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

#include <iostream>

template<class T>
class DynamicArray {
private:
    T *data;
    int size;

public:
    DynamicArray() {
        this->size = 0;
        this->data = new T[0];
    }

    DynamicArray(T arr[], int size) {
        this->size = size;
        this->data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = arr[i];
    }

    DynamicArray(const DynamicArray &o) {
        this->size = o.size;
        this->data = new T[o.size];
        for (int i = 0; i < size; i++)
            data[i] = o.data[i];
    }

    int getSize() {
        return size;
    }

    void insert(T value, int pos) {
        this->size += 1;
        T *t = new T[size];
        for (int i = 0; i < size; i++) {
            if (i == pos)
                t[i] = value;
            else if (i < pos)
                t[i] = data[i];
            else
                t[i] = data[i - 1];
        }
        delete[] data;
        data = t;
    }

    void remove(int pos) {
        this->size -= 1;
        T *t = new T[size];
        for (int i = 0; i < size; i++) {
            if (i >= pos)
                t[i] = data[i + 1];
            else
                t[i] = data[i];
        }
        delete[] data;
        data = t;
    }

    void push_back(T value) {
        this->size += 1;
        T *t = new T[size];
        for (int i = 0; i < size - 1; i++)
            t[i] = data[i];
        t[size - 1] = value;
        delete[] data;
        data = t;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << "\n";
        }
    }

    ~DynamicArray() {
        delete[] data;
    }
};

#endif