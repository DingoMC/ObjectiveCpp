#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#pragma GCC optimize("O2")
using namespace std;
template <typename T>
class Array {
    private:
        T* arr;
        unsigned arr_size;
        unsigned free_index;
    public:
        Array ();
        Array (unsigned array_size);
        ~Array ();
        void sort_asc ();
        T array_max ();
        void show ();
        void append (const T &element);
        T elem_at (unsigned index);
};
#include "array.tpp"
#endif // !ARRAY_H