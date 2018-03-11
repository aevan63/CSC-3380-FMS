// Written by Christian Lashover

#include "Feedback.h"
#include <string>
using namespace std;

Feedback::Feedback() {
    text = email = phone = tag = "";
}

Feedback::Feedback(string text, string email, string phone) {
    this->text = text;
    this->email = email;
    this->phone = phone;
    tag = "";
}
