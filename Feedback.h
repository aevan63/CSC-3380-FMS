// Written by Christian Lashover

#ifndef FEEDBACK_H
#define FEEDBACK_H
#include <string>
using namespace std;

class Feedback {
private:
    string text;
    string email;
    string phone;
    string tag;
    virtual void setSpecificFields(string*) = 0;
public:
    Feedback();
    Feedback(string, string, string);
};

#endif
