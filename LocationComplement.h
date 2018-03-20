// Written by Christian Lashover

#ifndef LOCATIONCOMPLEMENT_H
#define LOCATIONCOMPLEMENT_H
#include "LocationFeedback.h"
#include <string>
using namespace std;

class LocationComplement : public LocationFeedback {
public:
    LocationComplement(string, string, string, string, string, string);
};

#endif
