#include<iostream>
#include "figure.h"
#include "circle.h"
using namespace std;
Circle::Circle (float r1) {
    r = r1;
    cout<<"Konstruktor w klasie Circle"<<endl;
}
Circle::~Circle () {
    cout<<"Destruktor w klasie Circle"<<endl;
}
void Circle::calculateArea () {
    float p = 3.141592653589 * r * r;
    setArea(p);
}
void Circle::calculatePerimeter () {
    float p = 3.141592653589 * r * 2;
    setPerimeter(p);
}