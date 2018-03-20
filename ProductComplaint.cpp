// Written by Christian Lashover

#include "ProductFeedback.h"
#include "ProductComplaint.h"
#include <string>
using namespace std;

ProductComplaint::ProductComplaint(string text, string email, string phone, string product) :
ProductFeedback(text, email, phone, product) {
    
};
