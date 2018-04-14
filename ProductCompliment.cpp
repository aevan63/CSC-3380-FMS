// Written by Christian Lashover

#include <string>
#include "ProductCompliment.h"
using namespace std;

ProductCompliment::ProductCompliment() : ProductFeedback() { }

ProductCompliment::ProductCompliment(const string* fields) : ProductFeedback(fields) { }
