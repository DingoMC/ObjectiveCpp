#ifndef FIGURE_H
#define FIGURE_H
class Figure {
    private:
        float area;
        float perimeter;
    public:
        Figure();
        virtual ~Figure();
        float getArea();
        float getPerimeter();
        void setArea(float area1);
        void setPerimeter(float perim);
        virtual void calculateArea() = 0;
        virtual void calculatePerimeter() = 0;
        virtual void show();
};
#endif