#include "factory.h"
#include <memory>
using namespace std;

ostream &operator<<(ostream &o, unique_ptr<Employee> &employee)
{
    o << employee->name_ << ' ';
    o << "works at " << employee->address_->street_ << ", ";
    o << "building " << employee->address_->suite_;
}

int main()
{
    unique_ptr<Employee> Bob = EmployeeFactory::NewMainEmployee("Bob", 1);
    unique_ptr<Employee> John = EmployeeFactory::NewAuxEmployee("John", 2);

    cout << Bob << endl;
    cout << John << endl;
}