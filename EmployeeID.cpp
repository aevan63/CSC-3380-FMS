// Written by Christian Lashover

#include "EmployeeID.h"
using namespace std;

EmployeeID::EmployeeID(string name, string ID) {
    this->name = name;
    this->ID = ID;
}

string EmployeeID::getName() const {
    return name;
}

string EmployeeID::getID() const {
    return ID;
}
