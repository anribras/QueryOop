#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <set>
#include <string>
#include <memory>
#include <vector>
#include <iostream>


using std::set;
using std::string;
using std::shared_ptr;
using std::vector;
using std::cout;

class QueryResult {
	public:
		typedef set<string>::size_type size_type;
		QueryResult() = default;
		~QueryResult() = default;
		QueryResult(shared_ptr<set<size_type>> p, shared_ptr<vector<string>> f,const string & s) : lines_set(p),file(f),query_word(s) {}
		//查询结果的行数
		size_type size() const { return (*lines_set).size();} //引用set,避免拷贝
		//行号
		shared_ptr<set<size_type>> get_lines() const {return lines_set;} 
		//查询字串
		string get_query_word() {return query_word;}
		//行号修改
		void set_lines(shared_ptr<set<size_type>> l) {
			lines_set = l;
		}
		//查询显示字串修改
		void set_query_word(const string & s) { query_word = s; }
		//获取序列化文件
		shared_ptr<vector<string>> get_file() {return file;}

		void display() const;
		//文件的行数
		size_type total_lines() {return file->size();}
	private:
		shared_ptr<set<size_type>> lines_set; //引用set,避免拷贝
		shared_ptr<vector<string>> file; //引用vector，避免拷贝
		string query_word;
};
#endif
