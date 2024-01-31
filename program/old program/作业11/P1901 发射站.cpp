/*
#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;
#define maxn 1000005
long long  an[maxn], n;
int h[maxn], p[maxn];
stack<int>a;
int main()
{
	long long mans = INT_MIN, num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i] >> p[i];

	for (int i = 1; i <= n; i++)
	{
		while (!a.empty() && h[a.top()] < h[i])
		{
			an[i] += p[a.top()];
			a.pop();
		}
		if (!a.empty()&&(h[a.top()] >= h[i]))
		{
			an[a.top()] += p[i];
		}
		a.push(i);
	}
	for (int i = 1; i <= n; i++)
	{
		mans = max(mans, an[i]);
	}
	cout << mans << endl;
	return 0;
}
*/