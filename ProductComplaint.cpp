// Written by Christian Lashover

#include <string>
#include "ProductComplaint.h"
using namespace std;

ProductComplaint::ProductComplaint() : ProductFeedback() { }

ProductComplaint::ProductComplaint(const string* fields) : ProductFeedback(fields) { }
