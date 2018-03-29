// Written by Christian Lashover

#include <string>
#include "LocationComplaint.h"
using namespace std;

LocationComplaint::LocationComplaint() : LocationFeedback() { }

LocationComplaint::LocationComplaint(const string* fields) : LocationFeedback(fields) { }
