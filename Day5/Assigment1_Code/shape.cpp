#include <iostream>
#include <math.h>
#include "shape.hpp"

// Shape definitions:
//==================
void shape::setShapeBasicValues(int _Area, int _Perimeter)
{
    Area = _Area;
    Perimeter = _Perimeter;
}
shape::shape(const int _P1, int _P2) : P1(_P1), P2(_P2)
{
    std::cout << "In contructor of class shape\n";
}
shape::~shape() { std::cout << "In destructor of class shape\n"; }

bool shape::operator==(const shape &_shape)
{
    bool ret = false;
    if ((this->Area == _shape.Area) && (this->Perimeter == _shape.Perimeter))
    {
        ret = true;
    }
    return ret;
}

bool shape::operator>(const shape &_shape)
{
    bool ret = false;
    if (this->Area > _shape.Area)
    {
        ret = true;
    }
    else if ((this->Area == _shape.Area) && (this->Perimeter > _shape.Perimeter))
    {
        ret = true;
    }
    return ret;
}

bool shape::operator<(const shape &_shape)
{
    bool ret = false;
    if (this->Area < _shape.Area)
    {
        ret = true;
    }
    else if ((this->Area == _shape.Area) && (this->Perimeter < _shape.Perimeter))
    {
        ret = true;
    }
    return ret;
}

// rectangle definitions:
//======================
int rectangle::area() { return shape::Area; }
int rectangle::perimeter() { return shape::Perimeter; }
rectangle::rectangle(int _Base, int _Hight) : Base(_Base), Hight(_Hight), shape(_Base, _Hight)
{
    setShapeBasicValues(Base * Hight, 2 * (Base + Hight));
    std::cout << "In constructor of class rectangle\n";
}
rectangle::~rectangle() { std::cout << "In destructor of class rectangle\n"; }

// triangle definitions:
//=====================
int triangle::area() { return shape::Area; }
int triangle::perimeter() { return shape::Perimeter; }
triangle::triangle(int _Base, int _Hight) : Base(_Base), Hight(_Hight), shape(_Base, _Hight)
{
    setShapeBasicValues((Base * Hight) / 2, Base + Hight + sqrt(Base * Base + Hight * Hight));
    std::cout << "In contructor of class triangle\n";
}
triangle::~triangle() { std::cout << "In desctructor of class triangle\n"; }

// circle definitions:
//====================
int circle::area() { return shape::Area; }
int circle::perimeter() { return shape::Perimeter; }
circle::circle(int _Radius, int _Pi) : Pi(_Pi), Radius(_Radius), shape(_Radius, _Pi)
{
    setShapeBasicValues(Pi * Radius * Radius, 2 * Pi * Radius);
    std::cout << "In contructor of class circle\n";
}
circle::~circle() { std::cout << "In desctructor of class circle\n"; }
