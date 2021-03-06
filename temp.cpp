/*************************************************/

#include <iostream>
using namespace std;
#include <string>
typedef std::string T;
class Stack{
	T a[5];
	int cur;
public:
	Stack():cur(0){}
	void push(const T& d)throw(const char*);//数据入栈成为栈顶
	T pop()throw(const char*);//栈顶数据出栈，下一个数据成为栈顶
	const T& top()const throw(const char*);//取得栈顶数据
	bool empty()const{return cur==0;}//是否空栈
	bool full()const{return cur==5;}//是否已满
	void clear(){cur=0;}//栈清空（复位）
	int size()const{return cur;}//栈中数据个数
};
void Stack::push(const T& d)throw(const char*){
	if(full()) throw "满";
	a[cur++] = d;
}
T Stack::pop()throw(const char*){
	if(empty()) throw "空";
	return a[--cur];
}
const T& Stack::top()const throw(const char*){
	if(empty()) throw "空";
	return a[cur-1];
}
int main()
{
	Stack s;
	try{
	s.push("芙蓉");
	s.push("凤姐");
	s.push("春哥");
	s.push("曾哥");
	s.push("权哥");
	s.push("犀利");
	}
	catch(const char* e){
		cout << "异常:" << e << endl;
	}
	while(!s.empty()){
		cout << s.pop() << endl;
	}
}
