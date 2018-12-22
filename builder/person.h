#pragma once
#include <string>
#include <iostream>

using namespace std;

class PersonBuilder;

struct Person
{
    string address_;
    string zipcode_;
    string city_;

    string workplace_;
    string job_;
    int income_;

    static PersonBuilder create();
};
