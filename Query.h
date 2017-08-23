#ifndef QUERY_H_
#define QUERY_H_

#include <memory>
#include <string>

#include "QueryResult.h"
#include "Query_base.h"

using std::shared_ptr;
using std::string;

class Query_base;
class QueryResult;
class QueryText;


class Query {
	public:
		Query(const string & s);
		friend class Query_base;
		friend Query operator~(const Query & q);
		friend Query operator&(const Query & l, const Query & r);
		friend Query operator|(const Query & l, const Query & r);
		QueryResult eval(QueryText & txt) {return pbase->eval(txt);}
		//void display() {pbase->display();}
	private:

		Query(shared_ptr<Query_base> p) : pbase(p) {}
		string word;
		shared_ptr<Query_base> pbase;
		QueryResult result;
};
#endif
