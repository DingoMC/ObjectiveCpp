#ifndef ADDING_H
#define ADDING_H
using namespace std;
template <typename T>
class Adding {
    private:
        T element;
    public:
        Adding(const T &value);
        void add(T value);
        void show();
};
template <typename T>
Adding<T>::Adding(const T &value) {
    element = value;
}
template <typename T>
void Adding<T>::add(T value) {
    element = element+value;
}
template <typename T>
void Adding<T>::show() {
    cout<<"Element: "<<element<<endl;
}
#endif // !ADDING_H