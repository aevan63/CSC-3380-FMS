// Written by Christian Lashover

#include <sstream>
#include "BuildQuery.h"
using namespace std;

void BuildQuery::formToSQL() {
    // Needs to be written
}

// This isn't the final constructor
BuildQuery::BuildQuery(string environHTML) {
    this->environHTML = environHTML;
    formToSQL();
}

string BuildQuery::getQuery() const {
    return constructedQuery;
}
