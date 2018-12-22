#include "person.h"
#include <string>
using namespace std;

class AddressBuilder;
class WorkBuilder;

struct PersonBuilderBase
{
    Person &p_;

    explicit PersonBuilderBase(Person &p);
    operator Person();

    AddressBuilder lives() const;
    WorkBuilder works() const;
};

struct PersonBuilder : public PersonBuilderBase
{
    Person p_;
    PersonBuilder();
};

struct AddressBuilder : public PersonBuilderBase
{
    explicit AddressBuilder(Person &p) : PersonBuilderBase{p} {}
    AddressBuilder &at(string address);
    AddressBuilder &withzipcode(string zipcode);
    AddressBuilder &in(string city);
};

struct WorkBuilder : public PersonBuilderBase
{
    explicit WorkBuilder(Person &p) : PersonBuilderBase{p} {}
    WorkBuilder &at(string address);
    WorkBuilder &as_a(string job);
    WorkBuilder &earning(int income);
};