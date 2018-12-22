#include "person.h"
#include "builder.h"
using namespace std;

PersonBuilderBase::PersonBuilderBase(Person &p) : p_(p){};
PersonBuilderBase::operator Person()
{
    return move(p_);
}

AddressBuilder PersonBuilderBase::lives() const
{
    AddressBuilder b(p_);
    return b;
}

WorkBuilder PersonBuilderBase::works() const
{
    WorkBuilder b(p_);
    return b;
}

PersonBuilder::PersonBuilder() : PersonBuilderBase(p_) {}

AddressBuilder &AddressBuilder::at(string address)
{
    p_.address_ = address;
    return *this;
}
AddressBuilder &AddressBuilder::withzipcode(string zipcode)
{
    p_.zipcode_ = zipcode;
    return *this;
}

AddressBuilder &AddressBuilder::in(string city)
{
    p_.city_ = city;
    return *this;
}

WorkBuilder &WorkBuilder::at(string address)
{
    p_.workplace_ = address;
    return *this;
}
WorkBuilder &WorkBuilder::as_a(string job)
{
    p_.job_ = job;
    return *this;
}
WorkBuilder &WorkBuilder::earning(int income)
{
    p_.income_ = income;
    return *this;
}
