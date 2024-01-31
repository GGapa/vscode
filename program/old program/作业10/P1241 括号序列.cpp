/*
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack <int> a;
	string n, ans = "";
	bool bj[101] = { false };
	cin >> n;
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] == ')')
		{
			if (a.size() == 0)continue;
			if (n[a.top()] == '(')
			{
				bj[i] = bj[a.top()] = true;
				a.pop();
			}
		}
		else if (n[i] == ']')
		{
			if (n[i] == ']')
			{
				if (a.size() == 0)continue;
				if (n[a.top()] == '[')
				{
					bj[i] = bj[a.top()] = true;
					a.pop();
				}
			}
		}
		else a.push(i);
	}
	for (int i = 0; i < n.length(); i++)
	{
		if (bj[i])cout << n[i];
		else
		{
			if (n[i] == ')' || n[i] == '(')cout << "()";
			else cout << "[]";
		}
	}
	cout << endl;
	return 0;
}
*/