// Written by Christian Lashover

#ifndef LOCATIONCOMPLEMENT_H
#define LOCATIONCOMPLEMENT_H
#include <string>
#include "LocationFeedback.h"
using namespace std;

class LocationComplement : public LocationFeedback {
public:
    LocationComplement();
    LocationComplement(const string*);
};

#endif
