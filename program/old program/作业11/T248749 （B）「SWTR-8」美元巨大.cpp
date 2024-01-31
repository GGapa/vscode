/*
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 25000
long long a[maxn], s, n, x, y, t, b[maxn], an[maxn], ans = 0, num = 0;
void digui()
{

}
int main()
{
	cin >> s >> t;
	while (t--)
	{
		cin >> n >> x >> y;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i] = pow(2, a[i]);
		}
		for (int i = 0; i < x; i++)
		{
			b[i] = 0;
		}
		for (int i = x; i < x + y; i++)
		{
			b[i] = 1;
		}
		while (next_permutation(b, b + x + y - 1))
		{
			num = 0;
			for (int i = 0; i < x + y; i++)
			{
				if (!b[i])
				{
					num += a[i] ^ a[i + 1];
				}
				else
				{
					num += a[i] | a[i + 1];
				}
			}
			if (num > ans)
			{
				for (int i = 0; i < x + y; i++)
				{
					an[i] = b[i];
				 }
				ans = num;
			}
		}
		printf("%s\n", ans);
		for (int i = 0; i < x + y; i++)
		{
			if (!b[i])
			{
				cout << "^";
			}
			else
			{
				cout << "|";
			}
		}
		cout << endl;
	}
	return 0;
}
*/