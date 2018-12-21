#include "drink.h"
#include <string>
#include <memory>
#include <map>

using namespace std;

struct HotDrinkFactory
{
    virtual unique_ptr<HotDrink> Make(int volume) = 0;
};

struct TeaFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> Make(int volume) override
    {
        unique_ptr<Tea> tea = make_unique<Tea>();
        tea->Prepare(volume);
        return tea;
    }
};

struct CoffeeFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> Make(int volume) override
    {
        unique_ptr<Coffee> coffee = make_unique<Coffee>();
        coffee->Prepare(volume);
        return coffee;
    }
};

struct DrinkFactory
{
    DrinkFactory()
    {
        factories["tea"] = make_unique<TeaFactory>();
        factories["coffee"] = make_unique<CoffeeFactory>();
    }
    unique_ptr<HotDrink> MakeDrink(string name, int volume)
    {
        return factories[name]->Make(volume);
    }

private:
    map<string, unique_ptr<HotDrinkFactory>> factories;    
};