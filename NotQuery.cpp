#ifndef NOT_QUERY_CPP
#define NOT_QUERY_CPP


#include "NotQuery.h"
#include <memory>
#include <algorithm>
#include <iterator>

using namespace std;
typedef QueryResult::size_type size_type;

NotQuery::NotQuery(const Query & q)
{
	pquery = make_shared<Query>(q);
}

QueryResult NotQuery::eval(QueryText & t)
{
	size_type i = 0;
	auto result = pquery->eval(t);
	auto foundlines = result.get_lines();
	//auto foundsize = result.size();
	auto totalsize = result.total_lines();
	//构造一个1到totalsize的行号set
	set<size_type> tmp_set;
	for(i = 1; i <= totalsize; i++) {
		tmp_set.insert(i);
	}
	shared_ptr<set<size_type>> pset = make_shared<set<size_type>>();
	// 用set_difference
	set_difference(
			begin(tmp_set),end(tmp_set),
			begin(*foundlines),end(*foundlines),
			inserter(*pset, begin(*pset)));

	result.set_lines(pset);
	result.set_query_word("~(" +result.get_query_word() + ")" );

	return result;
}

#endif
