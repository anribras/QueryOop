#ifndef _OR_QUERY_CPP_
#define _OR_QUERY_CPP_

#include "OrQuery.h"
#include <algorithm>



using namespace std;
typedef QueryResult::size_type size_type;

QueryResult OrQuery::eval(QueryText & t)
{
	auto r1 =  get_left()->eval(t);
	auto r2 =  get_right()->eval(t);
	auto s1 = r1.get_lines();
	auto s2 = r2.get_lines();
	//set_ineraction
	auto s3 = make_shared<set<size_type>>();
	set_union(begin(*s1),end(*s1),
			begin(*s2),end(*s2),
			inserter(*s3,begin(*s3)));
	return QueryResult(
			s3,
			r1.get_file(),
			"("+r1.get_query_word() + " | " + r2.get_query_word()+")" 
			);

}


#endif
