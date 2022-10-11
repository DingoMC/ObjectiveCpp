#ifndef SQUARE_H
#define SQUARE_H
#include "figure.h"
class Square : public Figure {
    private:
        float a;
    public:
        Square (float a1);
        ~Square();
        virtual void calculateArea() override;
        virtual void calculatePerimeter() override;
        virtual void show() override;
};
#endif