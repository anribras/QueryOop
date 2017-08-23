#ifndef _AND_QUERY_H
#define _AND_QUERY_H


#include "BinaryQuery.h"

class AndQuery : public BinaryQuery {
	public:
		friend class Query;
		QueryResult eval(QueryText & t);
		AndQuery(const Query & l,const Query & r):BinaryQuery(l,r) {}

};

#endif
