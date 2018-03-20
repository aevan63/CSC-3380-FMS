// Written by Christian Lashover

#ifndef LOCATIONCOMPLAINT_H
#define LOCATIONCOMPLAINT_H
#include "LocationFeedback.h"
#include <string>
using namespace std;

class LocationComplaint : public LocationFeedback {
public:
    LocationComplaint(string, string, string, string, string, string);
};

#endif
