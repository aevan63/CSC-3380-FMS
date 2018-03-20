// Written by Christian Lashover

#ifndef PRODUCTCOMPLEMENT_H
#define PRODUCTCOMPLEMENT_H
#include "ProductFeedback.h"
#include <string>
using namespace std;

class ProductComplement : public ProductFeedback {
public:
    ProductComplement(string, string, string, string);
};

#endif
