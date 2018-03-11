// Written by Christian Lashover

#ifndef LOCATIONFEEDBACK_H
#define LOCATIONFEEDBACK_H
#include "Feedback.h"
#include <string>
using namespace std;

class LocationFeedback : public Feedback {
private:
    string location;
    string service;
    string employee;
    virtual void setSpecificFields(string*);
public:
    LocationFeedback();
    LocationFeedback(string, string, string, string, string, string);
};

#endif
