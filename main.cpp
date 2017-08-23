
#include "QueryResult.h"
#include "QueryText.h"
#include "Query.h"

#include <iostream>
#include <algorithm>


using namespace std;


void QueryResult_test()
{
	auto lines = make_shared<set<QueryResult::size_type>>();
	lines->insert(1);
	lines->insert(2);
	lines->insert(3);
	for_each(begin(*lines),end(*lines),[](const QueryResult::size_type & i){
			cout << i << " ";});
	cout << "\n";

	auto vecs = make_shared<vector<string>>();
	vecs->push_back("11");
	vecs->push_back("22");
	vecs->push_back("33");


	QueryResult res = QueryResult(lines,vecs,"query");
	res.display();
	
}

void QueryText_test(int argc ,char* argv[])
{
	if(argc < 2) {
		cout << "Need a word.\n";
		return;
	}
	ifstream fin("README.md");
	if(!fin) {
		cout << "File not exist\n";
		return ;
	}

	QueryText(fin).query(argv[1]).display();
}

void NotQuery_test(int argc, char* argv[])
{
	if(argc < 2) {
		cout << "Need a word.\n";
		return;
	}
	ifstream fin("README.md");
	if(!fin) {
		cout << "File not exist\n";
		return ;
	}
	Query q = ~Query(argv[1]);
	QueryText txt(fin);
	//Query::qbase指向 NotQuery
	//实际调用NotQuery::eval
	//NotQuery:eval 先调用qquery->eval
	//qquery指向了封装单词的Query(xx).
	//Query里又是虚函数，pbase->eval
	//此时的pbase指向一个WordQuery
	auto result =  q.eval(txt);
	result.display();
}

void set_difference_test()
{
	set<int> s1;

	auto s2 = make_shared<set<int>>();
	auto s3 = make_shared<set<int>>();
	for(int i = 0 ; i < 200; i ++)
		s1.insert(i);

	//s2.insert(1);
	//s2.insert(2);
	set_difference(begin(s1),end(s1),begin(*s2),end(*s2),
			inserter(*s3,begin(*s3)));

	for(auto it:(*s3)) {
		cout << it << " ";
	}
	cout <<"\n";
}

void AndQuery_test(int argc , char* argv[])
{
	if(argc < 3) {
		cout << "Need a word.\n";
		return;
	}
	ifstream fin("README.md");
	if(!fin) {
		cout << "File not exist\n";
		return ;
	}
	Query q = ~(Query(argv[1]) & Query(argv[2]));
	QueryText txt(fin);
	auto result =  q.eval(txt);
	result.display();

}

void OrQuery_test(int argc, char* argv[])
{
	ifstream fin("README.md");
	if(!fin) {
		cout << "File not exist\n";
		return ;
	}
	Query q = (~ Query(argv[1]) & Query(argv[2]) | Query(argv[3]) );
	QueryText txt(fin);
	auto result =  q.eval(txt);
	result.display();

}

	
int main(int argc ,char* argv[])
{
	//set_difference_test();
	//QueryResult_test();
	//QueryText_test(argc, argv);
	//NotQuery_test(argc,argv);
	//AndQuery_test(argc,argv);
	OrQuery_test(argc,argv);
	return 0;
}
