#include <iostream>
using namespace std;

struct HotDrink
{
    virtual void Prepare(int volume) = 0;
};

struct Tea : HotDrink
{
    void Prepare(int volume) override
    {
        cout << "Prepare " << volume << " ml tea." << endl;
    }
};

struct Coffee : HotDrink
{
    void Prepare(int volume) override
    {
        cout << "Prepare " << volume << " ml coffee." << endl;
    }
};