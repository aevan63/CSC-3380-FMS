// Written by Christian Lashover

#include <string>
#include "EmployeeID.h"
using namespace std;

class Employee {
private:
    EmployeeID empID;
    string tag;
    void determineTag(string);
public:
    Employee(string, string, string);
    string getTag() const;
    EmployeeID getInfo() const;
};
