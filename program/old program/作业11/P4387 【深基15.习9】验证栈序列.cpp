/*
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define maxn 100001
stack<int> pushed;


int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		int n; 
		int a[maxn]={0}, b[maxn]={0}, num = 0;
		bool bj = true;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		for (int i = 0; i < n; i++)
		{
			pushed.push(a[i]);
			while (pushed.top() == b[num])
			{
				num++;
				pushed.pop();
				if (pushed.empty())
					break;
			}
		}
		if (pushed.empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		while (!pushed.empty())
			pushed.pop();
	}
	return 0;
}
*/