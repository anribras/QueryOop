#ifndef  __WORDQUERY_CPP___
#define  __WORDQUERY_CPP___

#include "WordQuery.h"

using namespace std;

QueryResult WordQuery::eval(QueryText & t)
{
	return t.query(word);
}

#endif
