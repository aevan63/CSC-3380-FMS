// Written by Christian Lashover

#include <string>
#include "ProductFeedback.h"
using namespace std;

ProductFeedback::ProductFeedback() {
    text = email = phone = tag = product = "";
}

ProductFeedback::ProductFeedback(const string* fields) {
    text = fields[0];
    email = fields[1];
    phone = fields[2];
    tag = fields[3];
    product = fields[4];
}
