// Written by Christian Lashover

#include "ProductFeedback.h"
#include "ProductComplement.h"
#include <string>
using namespace std;

ProductComplement::ProductComplement(string text, string email, string phone, string product) :
ProductFeedback(text, email, phone, product) {
    
};
