#include "TextQuery.h"
#include "QueryResult.h" // Include the "QueryResult" header
#include <sstream>
#include <memory> // Include the <memory> header
#include <set>
using std::string;
using std::set;


TextQuery::TextQuery(std::ifstream &is): file(new std::vector<std::string>) {
    std::string text;
    while(getline(is, text)) { // Use std::getline instead of getline
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream read_line(text);

        string word;
        while(read_line >> word) {
            auto &lines = wm[word];
            if (!lines) {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);
        }
    }
}


QueryResult TextQuery::query(const string &sought) const
{
    static std::shared_ptr<set<line_no>> nodata(new set<line_no>); // Add std:: before shared_ptr

    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    } else {
        return QueryResult(sought, loc->second, file);
    }
}
