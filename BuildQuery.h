// Written by Christian Lashover

#ifndef BUILDQUERY_H
#define BUILDQUERY_H
#include <string>
using namespace std;

class BuildQuery {
private:
    string environHTML;
    string constructedQuery;
    void formToSQL();
public:
    BuildQuery(string);
    string getQuery() const;
};

#endif
