/*
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <deque>
using namespace std;

int main()
{
	vector<int> a;
	cout << "vector" << endl;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	cout << a[2] << endl;
	cout << a[4] << endl;
	queue <int>b;
	cout << "queue" << endl;
	b.push(1);
	b.push(2);
	cout << b.front() << endl;
	cout << b.back() << endl;
	b.pop();
	cout << b.front() << endl;
	cout << "set" << endl;
	set <int> c;
	c.insert(2);
	c.insert(3);
	c.insert(1);
	c.insert(2);
	cout << c.size() << endl;
	cout << "multiset" << endl;
	multiset<int > d;
	d.insert(2);
	d.insert(3);
	d.insert(1);
	d.insert(2);
	cout << d.size() << endl;
	cout << "map" << endl;
	map<int, int> e;
	pair<int, int> ls{ 1,2 };
	e.insert(ls);
	cout << e[1] << endl;
	pair<int, int> ls1{ 1,3};
	e.insert(ls1);
	cout << e[1] << endl;
	cout << "multimap" << endl;
	multimap<int, int>f;
	pair<int, int>ls2{ 2,1 };
	f.insert(ls2);
	pair<int, int>ls3{ 2,2 };
	f.insert(ls3);
	cout << (f.erase(2)) << endl;
	cout << "stack" << endl;
	stack<int>g;
	g.push(1);
	g.push(2);
	cout << g.top() << endl;//后进先出
	g.pop();
	cout << g.top() << endl;
	cout << "list" << endl;
	int ls4[3] = { 1,2,3 };
	list<int>h(ls4,ls4+3);
	list<int>::iterator it;
	it = h.begin();
	h.insert(it, 5);
	it++;
	h.insert(it, 4);
	cout << h.size() << endl;
	cout << "deque" << endl;
	deque<int>n;
	n.push_back(1);
	n.push_back(2);
	n.push_front(3);
	n.push_front(4);
	cout << n.front() << endl;
	cout <<n.back() << endl;
	n.pop_back();
	cout << n.back() << endl;
	n.pop_front();
	cout << n.front() << endl;
	return 0;
}
*/