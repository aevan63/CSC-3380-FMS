// Written by Christian Lashover

#ifndef PRODUCTCOMPLEMENT_H
#define PRODUCTCOMPLEMENT_H
#include <string>
#include "ProductFeedback.h"
using namespace std;

class ProductComplement : public ProductFeedback {
public:
    ProductComplement();
    ProductComplement(const string*);
};

#endif
