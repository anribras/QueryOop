#ifndef NOT_QUERY_H_
#define NOT_QUERY_H_


#include "Query_base.h"
#include "QueryResult.h"
#include "QueryText.h"
#include "Query.h"

class NotQuery : public Query_base {
	public:
		friend class Query;
		QueryResult eval(QueryText & t);
		NotQuery(const Query & q);
	private:
		shared_ptr<Query> pquery; //用来保存~(xx)里的xx,也是个query对象

};

#endif
