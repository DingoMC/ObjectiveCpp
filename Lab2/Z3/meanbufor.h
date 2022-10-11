#ifndef MEANBUFOR_H
#define MEANBUFOR_H
#include "bufor.h"
class MeanBufor : public Bufor {
    public:
        MeanBufor(unsigned buf_size) : Bufor(buf_size) {}
        double calculate () override {
            double avg = 0.0;
            for (unsigned i = 0; i < getIndex(); i++) {
                avg += getTab(i);
            }
            avg /= getIndex();
            return avg;
        }
};
#endif // !MEANBUFOR_H