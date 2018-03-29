// Written by Christian Lashover

#ifndef PRODUCTCOMPLAINT_H
#define PRODUCTCOMPLAINT_H
#include <string>
#include "ProductFeedback.h"
using namespace std;

class ProductComplaint : public ProductFeedback {
public:
    ProductComplaint();
    ProductComplaint(const string*);
};

#endif
