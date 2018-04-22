// Written by Christian Lashover

#ifndef BUILDQUERY_H
#define BUILDQUERY_H
#include <string>
#include <map>
using namespace std;

class BuildQuery {
private:
    multimap<string, string> GETData;
    multimap<string, string> POSTData;
    string constructedQuery;
    void formToSQL();
public:
    BuildQuery(const multimap<string, string>&, const multimap<string, string>&);
    string getQuery() const;
};

#endif
