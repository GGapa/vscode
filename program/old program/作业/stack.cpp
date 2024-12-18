/*
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
stack<int> a;
stack<int> b;
int main()
{
	while (1)
	{
		int x, y;
		cin >> x;
		if (x == 1)
		{
			cin >> y;
			a.push(y);
		}
		if (x == 2)
		{
			if(!a.empty())a.pop();
			else
			{
				cout << "empty" << endl;
				continue;
			}
		}
		if (x == 3)
		{
			while (!a.empty())
			{
				b.push(a.top());
				a.pop();
			}
			while (!b.empty())
			{
				cout << b.top() << " ";
				a.push(b.top());
				b.pop();
			}
			cout << endl;
		}
		if (x == 4)
		{
			if (a.empty())
			{
				cout << "empty" << endl;
				continue;
			}
			int m1 = INT_MAX;
			while (!a.empty())
			{
				m1 = min(a.top(), m1);
				b.push(a.top());
				a.pop();
			}
			while (!b.empty())
			{
				a.push(b.top());
				b.pop();
			}
			cout << m1 << endl;
		}
		if (x == 5)
			break;
	}
	return 0;
}
*/