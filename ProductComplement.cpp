// Written by Christian Lashover

#include <string>
#include "ProductComplement.h"
using namespace std;

ProductComplement::ProductComplement() : ProductFeedback() { }

ProductComplement::ProductComplement(const string* fields) : ProductFeedback(fields) { }
