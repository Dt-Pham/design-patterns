#include <cmath>
#include <iostream>
using namespace std;

struct Point
{
    struct PointFactory
    {
        static Point NewCartesian(float x, float y)
        {
            return {x, y};
        }
        static Point NewPolar(float r, float theta)
        {
            return {r * cos(theta), r * sin(theta)};
        }
    };
    typedef PointFactory Factory;
    
    friend ostream& operator<<(ostream& o, Point p);
    friend Point operator + (Point a, Point b);

private:
    float x_;
    float y_;
    Point(float x, float y) : x_{x}, y_{y} {}
};

ostream& operator<<(ostream& o, Point p)
{
    o << p.x_ << ' ' << p.y_;
    return o;
}

Point operator + (Point a, Point b)
{
    return Point::Factory::NewCartesian(a.x_ + b.x_, a.y_ + b.y_);
}