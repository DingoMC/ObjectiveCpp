#include <iostream>
template <typename T> Array<T>::Array () {
    this->arr_size = 10;
    this->free_index = 0;
    this->arr = new T[arr_size];
}
template <typename T> Array<T>::Array (unsigned array_size) {
    this->arr_size = array_size;
    this->free_index = 0;
    this->arr = new T[arr_size];
}
template <typename T> Array<T>::~Array () {
    delete [] this->arr;
    delete this;
}
template <typename T> void Array<T>::sort_asc () {
    for (unsigned i = 0; i < this->free_index; i++) {
        for (unsigned j = i + 1; j < this->free_index; j++) {
            if (this->arr[i] > this->arr[j]) swap(this->arr[i], this->arr[j]);
        }
    }
}
template <> void Array<string>::sort_asc () {
    for (unsigned i = 0; i < this->free_index; i++) {
        for (unsigned j = i + 1; j < this->free_index; j++) {
            if (this->arr[i].length() > this->arr[j].length()) swap(this->arr[i], this->arr[j]);
        }
    }
}
template <typename T> T Array<T>::array_max () {
    T arr_max = this->arr[0];
    for (unsigned i = 1; i < this->free_index; i++) {
        if (this->arr[i] > arr_max) arr_max = this->arr[i];
    }
    return arr_max;
}
template <> string Array<string>::array_max () {
    string arr_max = this->arr[0];
    unsigned max_len = arr_max.length();
    for (unsigned i = 1; i < this->free_index; i++) {
        if (this->arr[i].length() > max_len) {
            arr_max = this->arr[i];
            max_len = this->arr[i].length();
        }
    }
    return arr_max;
}
template <typename T> void Array<T>::show () {
    cout<<"[";
    for (unsigned i = 0; i < this->free_index; i++) {
        cout<<arr[i];
        if (i < this->free_index - 1) cout<<" , ";
    }
    cout<<"]"<<endl;
}
template <typename T> void Array<T>::append (const T &element) {
    if (this->free_index == this->arr_size) {
        cout<<"Error at "<<__PRETTY_FUNCTION__<<": Array is full!"<<endl;
        return;
    }
    this->arr[this->free_index] = element;
    this->free_index++;
}
template <typename T> T Array<T>::elem_at (unsigned int index) {
    if (index >= this->free_index) {
        cout<<"Error at "<<__PRETTY_FUNCTION__<<": Index out of bounds!"<<endl;
        return this->arr[0];
    }
    return this->arr[index];
}