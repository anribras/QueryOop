#ifndef __QUERY_RESULT_CPP
#define __QUERY_RESULT_CPP

#include "QueryResult.h"
#include <algorithm>


using namespace std;

void QueryResult::display() const
{

	if(lines_set == nullptr) {
		cout << "Not found any " << query_word << " .";
		return;
	}
	//set
	auto lines = (*lines_set);
	//vector
	auto files = (*file);
	cout << "Found " << query_word << " " << size()  << " times:\n";
	for(auto it:lines) {
		//cout << it << endl;
		cout << "[" << it << "] " << files[it-1] << endl;
	}
	return;
}

#endif
