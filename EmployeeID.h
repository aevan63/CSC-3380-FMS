// Written by Christian Lashover

#ifndef EMPLOYEEID_H
#define EMPLOYEEID_H
#include <string>
using namespace std;

class EmployeeID {
private:
    string name;
    string ID;
public:
    EmployeeID(string, string);
    string getName() const;
    string getID() const;
};

#endif
