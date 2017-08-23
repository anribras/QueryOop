#ifndef _BINARY_QUERY_H
#define _BINARY_QUERY_H

#include "Query_base.h"
#include "Query.h"

#include <memory>

using std::make_shared;

class BinaryQuery : public Query_base {
	public:
		friend class Query;
		BinaryQuery(const Query & l,const Query & r) :pleft(make_shared<Query>(l)),
				pright(make_shared<Query>(r)){}
		shared_ptr<Query> get_left() {return pleft;}
		shared_ptr<Query> get_right() {return pright;}
	private:
		shared_ptr<Query> pleft;	
		shared_ptr<Query> pright; 

};


#endif
