#ifndef QUERYTEXT_CPP_
#define QUERYTEXT_CPP_

#include "QueryText.h"
#include "QueryResult.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;
string & QueryText::word_convert(string & word)
{
	if (word[0] >= 'A' && word[0] <= 'Z')
			word[0] += 32;
	if (word[word.length() -1] == ',' ||
		word[word.length() -1] == '.' ||
		word[word.length() -1] == '!' ) {

		word = word.substr(0,word.length() -1);
	}

	return word;
}

QueryText::QueryText(ifstream & f)
{
	if(file == nullptr) {
		file = make_shared<vector<string>>();
	}
	char line[512];
	size_type lnum = 0;
	string word;
	while(f.getline(line,512)) {
		++lnum;
		file->push_back(line);
		istringstream  ss(line);
		while( ss >> word ) {
			word = word_convert(word);
			if (indexs.find(word) == indexs.end() ) {
				indexs.insert(make_pair(word,make_shared<set<size_type>>()));
			}
			indexs[word]->insert(lnum);
		}
	}
}

QueryResult QueryText::query(const string & str)
{
	query_word = str;
	// 如果找到了key
	auto it = indexs.find(str);
	if ( it != indexs.end() ) {
		// *it是 pair<string,share_ptr<set<size_type>>>
		return QueryResult(indexs[it->first],file,str);
	} 

	return QueryResult(make_shared<set<size_type>>(),file,str);
}
#endif
