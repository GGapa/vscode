/*
#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char>a;
stack<char>b;
int main()
{
	int n, num = 0;
	cin >> n;
	while (n--)
	{
		for (int i = 0; i < 7; i++)
		{
			char x;
			cin >> x;
			if (x == '*')
				x = 'x';
			a.push(x);
		}
		while (a.size() != 1)
		{
			bool bj = true;
			while (!a.empty())
			{
				bool in = true;
				if (a.top() == '+' || a.top() == '-')
				{
					bj = false;
				}
				if (a.top() == 'x' && (b.top() == '+' || b.top() == '-'))
				{
					in = false;
					a.pop();
					int ls = (a.top() - '0') * (b.top() - '0');,
					if (a.top() == 'x')
					{
						a.pop();
						ls *= (a.top() - '0');
					}
					else
						a.pop();
					b.pop();
					b.push(ls + '0');
				}
				else if (a.top() == 'x')
				{
					in = false;
					int ls = b.top() - '0';
					b.pop();
					a.pop();
					b.push(ls * (a.top() - '0')+'0');
				}
				if (a.empty())
					continue;
				if (a.top() == '/' && (b.top() == '+' || b.top() == '-'))
				{
					in = false;
					a.pop();
					int ls = (a.top() - '0') / (b.top() - '0');
					a.pop();
					b.pop();
					b.push(ls + '0');
				}
				else if (a.top() == '/')
				{
					in = false;
					int ls = b.top() - '0';
					b.pop();
					a.pop();
					b.push(ls / (a.top() - '0') + '0');
				}
				if (a.empty())
					continue;
				else if (in || (a.top() == '+' || a.top() == '-'))
					b.push(a.top());
				a.pop();
			}
			while (!b.empty())
			{
				a.push(b.top());
				b.pop();
			}
			if (a.size() >= 3)
			{
				int x = a.top() - '0';
				a.pop();
				char y = a.top();
				a.pop();
				int z = a.top() - '0';
				a.pop();
				if (y == '+')
				{
					num += x + z;
					a.push(x + z + '0');
				}
				else if (y == '-')
				{
					num += z - x;
					a.push(z - x + '0');
				}
			}
		}
		if (a.top() - '0' == 24)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		num = 0;
		while (!a.empty())
			a.pop();
		while (!b.empty())
			b.pop();
	}
	return 0;
}
*/