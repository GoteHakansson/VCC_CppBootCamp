#include <iostream>

class shape {
    protected:
        int width, height;
    public:
        void setValues(int x, int y) {width = x; height = y;}
        virtual int area () = 0;
        virtual int perimeter() = 0;
        friend operator==bool()
};

class rectangle : public shape {
    public:
        int area() {return width * height;}
        int perimeter() {return width + height;}
};

class triangle : public shape {
    public:
        int area() {return (width * height)/2;}
        int perimeter() {return width + height;}
};

class circle : public shape {
    private:
        int pi = 2;
    public:
        int area(int r) {return pi*r*r*r;}
        int perimeter(int r) {return 2*pi*r;}
};


int main () {;}

/*
    Rectangle rect;
    Triangle tria;
    Polygon *pPoly = new Polygon;

    pPoly->setValues(5,8);
    std::cout << typeid(*pPoly).name() << ": " << pPoly->area() << std::endl;
    delete pPoly;

    pPoly=&rect;
    pPoly->setValues(10,10);
    std::cout << typeid(*pPoly).name() << ": " << pPoly->area() << std::endl;
    
    pPoly=&tria;
    pPoly->setValues(8,8);
    std::cout << typeid(*pPoly).name() << ": " << pPoly->area() << std::endl;
} */