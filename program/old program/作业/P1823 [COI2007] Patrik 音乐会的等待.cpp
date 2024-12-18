/*
#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;
#define maxn 1000005
long long  an[maxn], n;
long long h[maxn];
stack<int>a;
int main()
{
	long long mans = INT_MIN, num = 0,ans=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];

	for (int i = 1; i <= n; i++)
	{
		while (!a.empty() && h[a.top()] < h[i])
		{
			ans++;
			a.pop();
		}
		a.push(i);
	}
	cout << ans*2 << endl;
	return 0;
}
*/