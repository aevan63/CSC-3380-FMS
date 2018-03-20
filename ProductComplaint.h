// Written by Christian Lashover

#ifndef PRODUCTCOMPLAINT_H
#define PRODUCTCOMPLAINT_H
#include "ProductFeedback.h"
#include <string>
using namespace std;

class ProductComplaint : public ProductFeedback {
public:
    ProductComplaint(string, string, string, string);
};

#endif
