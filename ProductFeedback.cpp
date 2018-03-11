// Written by Christian Lashover

#include "ProductFeedback.h"
#include "Feedback.h"
#include <string>
using namespace std;

void ProductFeedback::setSpecificFields(string* fields) {
    product = fields[0];
}

ProductFeedback::ProductFeedback() : Feedback() {
    product = "";
}

ProductFeedback::ProductFeedback(string text, string email, string phone, string product) :
Feedback(text, email, phone) {
    setSpecificFields(&product);
}
