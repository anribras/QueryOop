#ifndef _WORDQUERY_H_
#define _WORDQUERY_H_

#include "Query_base.h"
#include "QueryResult.h"
#include "QueryText.h"


class WordQuery : public Query_base {
	public:
		WordQuery(const string & s):word(s){}
		QueryResult eval(QueryText & t);
	private:
		string word;

};
#endif
