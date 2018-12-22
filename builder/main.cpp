#include <iostream>
#include "builder.h"
using namespace std;

ostream &operator<<(ostream &out, const Person &p)
{
    out << p.address_ << ", " << p.zipcode_ << ", " << p.city_ << ", ";
    out << p.workplace_ << ", " << p.job_ << ", " << p.income_;
    return out;
}

int main()
{
    Person p = Person::create()
                   .lives()
                   .at("address")
                   .withzipcode("zipcode")
                   .in("city")
                   .works()
                   .at("workplace")
                   .as_a("job")
                   .earning(100000);

    cout << p << endl;
}