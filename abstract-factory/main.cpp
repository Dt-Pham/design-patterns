#include "factory.h"
using namespace std;

int main()
{
    DrinkFactory factory;
    unique_ptr<HotDrink> tea = factory.MakeDrink("tea", 20);
    unique_ptr<HotDrink> coffee = factory.MakeDrink("coffee", 20);    
}