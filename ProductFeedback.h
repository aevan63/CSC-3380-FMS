// Written by Christian Lashover
 
#ifndef PRODUCTFEEDBACK_H
#define PRODUCTFEEDBACK_H
#include "Feedback.h"
#include <string>
using namespace std;

class ProductFeedback : public Feedback {
private:
    string product;
    virtual void setSpecificFields(string*);
public:
    ProductFeedback();
    ProductFeedback(string, string, string, string);
};

#endif
