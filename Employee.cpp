// Written by Christian Lashover

#include "Employee.h"
using namespace std;

void Employee::determineTag(string HTML) {
    // Need to write this
}

Employee::Employee(string name, string ID, string HTML) : empID(name, ID) {
    determineTag(HTML);
}

string Employee::getTag() const {
    return tag;
}

EmployeeID Employee::getInfo() const {
    return empID;
}
