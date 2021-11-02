
// shape declaration
class shape
{
protected:
    int Perimeter = 0, Area = 0;
    int P1, P2;

public:
    shape() = default;
    shape(const int _P1, int _P2);
    virtual ~shape() = 0;
    virtual int area() = 0;
    virtual int perimeter() = 0;
    void setShapeBasicValues(int _Area, int _Perimeter);
    bool operator==(const shape &_shape);
    bool operator>(const shape &_shape);
    bool operator<(const shape &_shape);
};

// rectangle declaration
class rectangle : public shape
{
private:
    int Base, Hight;

public:
    int area();
    int perimeter();
    rectangle() = default;
    rectangle(int _Base, int _Hight);
    ~rectangle();
};

// triangle declaration
class triangle : public shape
{
private:
    int Base, Hight;

public:
    int area();
    int perimeter();
    triangle() = default;
    triangle(int _Base, int _Hight);
    ~triangle();
};

// circle declaration
class circle : public shape
{
private:
    int Radius, Pi;

public:
    int area();
    int perimeter();
    circle() = default;
    circle(int _Radius, int _Pi);
    ~circle();
};
