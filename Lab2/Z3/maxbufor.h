#ifndef MAXBUFOR_H
#define MAXBUFOR_H
#include <iostream>
#include "bufor.h"
using namespace std;
class MaxBufor : public Bufor {
    public:
        MaxBufor(unsigned buf_size) : Bufor(buf_size) {}
        double calculate () override {
            double max = getFirst();
            for (unsigned i = 0; i < getIndex(); i++) {
                if (getTab(i) > max) max = getTab(i);
            }
            return max;
        }
        void add (int value) override {
            if (getIndex() >= getSize()) {
                cout<<"Error while parsing into buffer: No more space available!"<<endl;
                return;
            }
            setTab(getIndex(), value);
            setFirst(getIndex() + 1);
        }
};
#endif // !MAXBUFOR_H