// Written by Christian Lashover

#ifndef LOCATIONCOMPLAINT_H
#define LOCATIONCOMPLAINT_H
#include <string>
#include "LocationFeedback.h"
using namespace std;

class LocationComplaint : public LocationFeedback {
public:
    LocationComplaint();
    LocationComplaint(const string*);
};

#endif
