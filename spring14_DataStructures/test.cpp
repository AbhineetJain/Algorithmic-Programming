#include<iostream>
#include<stack>

using namespace std;

struct node {
	int a;
	int b;
};


int main()
{
	stack<node> s;
	node obj;
	obj.a = 12;
	obj.b = 14;
	node obj2;
	obj2.a = 13;
	obj2.b = 15;
	s.push(obj);
	s.push(obj2);
	cout << s.top().a;
	return 0;
}
