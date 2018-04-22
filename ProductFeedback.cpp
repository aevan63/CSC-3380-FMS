// Written by Christian Lashover

#include <string>
#include "ProductFeedback.h"
using namespace std;

ProductFeedback::ProductFeedback() {
    text = name = email = phone = tag = product = "";
}

ProductFeedback::ProductFeedback(const string* fields) {
    text = fields[0];
    name = fields[1];
    email = fields[2];
    phone = fields[3];
    tag = fields[4];
    product = fields[5];
}
