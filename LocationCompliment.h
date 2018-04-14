// Written by Christian Lashover

#ifndef LOCATIONCOMPLIMENT_H
#define LOCATIONCOMPLIMENT_H
#include <string>
#include "LocationFeedback.h"
using namespace std;

class LocationCompliment : public LocationFeedback {
public:
    LocationCompliment();
    LocationCompliment(const string*);
};

#endif
