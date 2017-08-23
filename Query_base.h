#ifndef Query_base__H___
#define Query_base__H___

#include "QueryText.h"
#include "QueryResult.h"

class Query_base {
	public:
		virtual QueryResult eval(QueryText & t) = 0;
		//virtual void display(QueryResult & r) = 0;
		Query_base(){}
		virtual ~Query_base(){}
};
#endif
