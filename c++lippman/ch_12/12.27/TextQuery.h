#pragma once 

#include <vector> 
#include <map>
#include <set>
#include <string>
#include <fstream> 

using std::string;

class QueryResult; // declaration

class TextQuery {
public:
    using line_no = std::vector<string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;
private:
    std::shared_ptr<std::vector<string>> file;
    std::map<string,
            std::shared_ptr<std::set<line_no>>> wm;
};