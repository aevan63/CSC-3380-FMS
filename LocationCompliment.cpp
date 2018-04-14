// Written by Christian Lashover

#include <string>
#include "LocationCompliment.h"
using namespace std;

LocationCompliment::LocationCompliment() : LocationFeedback() { }

LocationCompliment::LocationCompliment(const string* fields) : LocationFeedback(fields) { }
