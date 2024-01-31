/*
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define maxn 100005
int a, b, p, l[maxn], s[maxn], len = 0, f[maxn],bj[maxn];
map<int,int>v;
void su()
{
	for (int i = 2; i <= sqrt(b) + 1; i++)
	{
		for (int j = i * 2; j <= b; j += i)
		{
			l[j] = 1;
		}
	}
	for (int i = 2; i <= b; i++)
		if (l[i] == 0 && i >= p)
		{
			s[len++] = i;
			f[i] = i;
		}
}
int find(int x)
{
	return f[x] == x ? x : (f[x] = find(f[x]));
}
int main()
{
	cin >> a >> b >> p;
	int ans = a - b + 1;
	su();
	for (int i = a; i <= b; i++)f[i] = i;
	for (int i = a; i <= b; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i % s[j] == 0)
			{
				int X = find(i), Y = find(s[j]);
				if (X != Y)
				{
					f[Y] = f[X];
				}
			}
		}
	}
	ans = 0;
	for (int i = a; i <= b; i++)
	{
		if (v.count(find(i)) == 0&&bj[i]==0)
		{
			bj[i] = true; v.insert({ find(i),i });
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
*/