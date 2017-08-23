#ifndef QUERY_CPP_
#define QUERY_CPP_


#include "Query.h"
#include "AndQuery.h"
#include "NotQuery.h"
#include "OrQuery.h"
#include "WordQuery.h"

#include <memory>

using namespace std;

Query::Query(const string & s)
{
	word = s;
	//pbase应该指向一个纯粹的WordQuery
	//WordQuery 接受string为构造函数
	pbase = make_shared<WordQuery>(s);
}

Query operator~(const Query & q)
{
	//创建一个shared_ptr<NotQuery>,调用了NotQuery的构造函数
	//NotQuery(const Query & )
	//构造NotQuery时，内部指针(也是shared_ptr)指向了q
	//最终重载运算符构建了新个query
	//query->base 指向新的NotQuery对象
	return Query(make_shared<NotQuery>(q));
}

Query operator&(const Query & l, const Query & r)
{
	return Query(make_shared<AndQuery>(l,r));
}

Query operator|(const Query & l, const Query & r)
{

	return Query(make_shared<OrQuery>(l,r));
}


#endif
