#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;
class Car {
private:
    string brand, model, vin;
    int year;
public:
    Car (string brand1, string model1, string vin1, int year1) : brand(brand1), model(model1), vin(vin1), year(year1) {}
    void show () {
        cout<<this->brand<<" "<<this->model<<" "<<this->year<<", VIN: "<<this->vin<<endl;
    }
    string getBrand() const;
    string getVin() const;
    int getYear() const;
};

inline string Car::getBrand() const
{
    return brand;
}

inline string Car::getVin() const
{
    return vin;
}

inline int Car::getYear() const
{
    return year;
}

#endif // CAR_H
