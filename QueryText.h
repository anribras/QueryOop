#ifndef QUERYTEXT_H
#define QUERYTEXT_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <memory>

using std::vector;
using std::string;
using std::ifstream;
using std::ostream;
using std::map;
using std::set;
using std::shared_ptr;

class QueryResult;

class QueryText {
	public:
		typedef set<string>::size_type size_type;
		QueryText(ifstream & file);
		QueryResult query(const string & str);
		ostream & display(ostream & os,QueryResult & result);
	private:
		shared_ptr<vector<string>> file;
		map<string,shared_ptr<set<size_type>>> indexs;
		string query_word;
		string & word_convert(string & word);
};
#endif
