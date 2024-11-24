/*
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 8005
struct d_
{
	int vaule, num;
};
int n, q;
d_ a[maxn], b[maxn];
int paixu(d_ x, d_ y)
{
	return x.vaule < y.vaule;
}
int main()
{
	int input;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].vaule;
		a[i].num = i;
	}
	for (int i = 1; i <= n; i++)
		b[i] = a[i];
	sort(b + 1, b + 1 + n, paixu);
	while (q--)
	{
		cin >> input;
		if (input == 1)
		{
			int x, v;
			cin >> x >> v;
			a[x].vaule = v;
			for (int i = 1; i <= n; i++)
				b[i] = a[i];
			sort(b + 1, b + 1 + n, paixu);
		}
		if (input == 2)
		{
			int x;
			cin >> x;
			for (int i = 1; i <= n; i++)
			{
				if (b[i].num == a[x].num)
					cout << i << endl;
			}
		}
	}
	return 0;
}
*/