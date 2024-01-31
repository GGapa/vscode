/*
#include <iostream>
#include <set>
#define maxn 10
using namespace std;
multiset<int> a;
inline int read()
{
	long long x = 0;
	bool flag = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')
			flag = 0;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return (flag ? x : ~(x - 1));
}
int main()
{
	long long l, r, x, n;
	cin >> n;
	while (n--)
	{
		a.clear();
		int num = 0;
		cin >> l >> r >> x;
		if (l/x == r/x)cout << l / x << endl;
		else cout << 1 << endl;
	}
	return 0;
}
*/