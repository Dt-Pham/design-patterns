#include "factory.h"

using namespace std;

int main()
{
    Point x = Point::Factory::NewCartesian(3, 4);
    Point y = Point::Factory::NewPolar(sqrt(2), M_PI_4);
    Point z = x + y;
    cout << z << endl;
}