// Written by Christian Lashover
 
#ifndef PRODUCTFEEDBACK_H
#define PRODUCTFEEDBACK_H
#include <string>
using namespace std;

class ProductFeedback {
private:
    string text;
    string name;
    string email;
    string phone;
    string tag;
    string product;
public:
    ProductFeedback();
    ProductFeedback(const string*);
};

#endif
