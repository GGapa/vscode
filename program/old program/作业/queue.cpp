/*
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int>a;
	while (1)
	{
		int n,m;
		cin >> n;
		if (n == 1)
		{
			cin >> m;
			a.push(m);
		}
		else if (n == 2)
		{
			a.pop();
		}
		else if (n == 3)
		{
			for (int i = 0; i < a.size(); i++)
			{
				cout << a.front() << " ";
				a.push(a.front());
				a.pop();
			}
			cout << endl;
		}
	}
	return 0;
}
*/