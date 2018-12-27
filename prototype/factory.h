#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct Address
{
    Address(string street, int suite): street_(street), suite_(suite) {}
    Address(const Address &other)
    {
        street_ = other.street_;
        suite_ = other.suite_;
    }
    string street_;
    int suite_;
};

struct Employee
{
    Employee(string name, string street, int suite) : name_(name), address_(new Address(street, suite)) {}
    Employee(Employee &other)
    {
        name_ = other.name_;
        address_ = new Address(*other.address_);
    }
    string name_;
    Address *address_;
};

static Employee Main("", "street 1", 0);
static Employee Aux("", "street 2", 0);

struct EmployeeFactory
{
    static unique_ptr<Employee> NewMainEmployee(string name, int suite)
    {
        unique_ptr<Employee> employee = make_unique<Employee>(Main);
        employee->name_ = name;
        employee->address_->suite_ = suite;
        return employee;
    }
    
    static unique_ptr<Employee> NewAuxEmployee(string name, int suite)
    {
        unique_ptr<Employee> employee = make_unique<Employee>(Aux);
        employee->name_ = name;
        employee->address_->suite_ = suite;
        return employee;
    }
};