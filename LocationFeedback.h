// Written by Christian Lashover

#ifndef LOCATIONFEEDBACK_H
#define LOCATIONFEEDBACK_H
#include <string>
using namespace std;

class LocationFeedback {
private:
    string text;
    string name;
    string email;
    string phone;
    string tag;
    string location;
    string service;
    string employee;
public:
    LocationFeedback();
    LocationFeedback(const string*);
};

#endif
