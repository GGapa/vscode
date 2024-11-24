/*
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> a;
	int n, m,num=1;
	cin >> n >> m;
	for (int i = 1; i<=n ; i++)
	{
		a.push(i);
	}
	while (!a.empty())
	{
		if (num == m)
		{
			cout<<a.front()<<" ";
			a.pop();
			num = 1;
		}
		else
		{
			int ls = a.front();
			a.pop();
			a.push(ls);
			num++;
		}
	}
	return 0;
}
*/