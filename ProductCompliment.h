// Written by Christian Lashover

#ifndef PRODUCTCOMPLIMENT_H
#define PRODUCTCOMPLIMENT_H
#include <string>
#include "ProductFeedback.h"
using namespace std;

class ProductCompliment : public ProductFeedback {
public:
    ProductCompliment();
    ProductCompliment(const string*);
};

#endif
