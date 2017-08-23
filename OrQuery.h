#ifndef _OR_QUERY_H
#define _OR_QUERY_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
	public:
		friend class Query;
		QueryResult eval(QueryText & t);
		OrQuery(const Query & l,const Query & r):BinaryQuery(l,r) {}

};

#endif
