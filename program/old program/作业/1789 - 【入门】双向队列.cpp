/*
#include <queue>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
deque<int>a;
stack<int>error;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string n;
		cin >> n;
		if (n == "LIN")
		{
			int y;
			cin >> y;
			a.push_front(y);
		}
		if (n == "RIN")
		{
			int y;
			cin >> y;
			a.push_back(y);
		}
		if (n == "LOUT")
		{
			if (a.empty())
			{
				error.push(i);
			}
			else
			{
				a.pop_front();
			}
		}
		if (n == "ROUT")
		{
			if (a.size()==0)
			{
				error.push(i);
			}
			else
			{
				a.pop_back();
			}
		}
	}
	while(a.size()!=0)
	{
		cout << a.front() << " ";
		a.pop_front();
	}
	cout << endl;
	while (!error.empty())
	{
		cout << error.top() << " "<<"ERROR"<<endl;
		error.pop();
	}
	return 0;
}

*/