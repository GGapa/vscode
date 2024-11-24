/*
#include <iostream>
#include <map>
using namespace std;
#define maxn 1<<20
int a[maxn], n, q;
map <int, int>n2;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= 20; i++)
		n2[1 << i] = (1 << i);
	int ans = 0, N = 1;
	while ((1 << (N)) <= n)
	{
		N++;
	}
	N--;
	N = 1 << N;
	while (N % 2 == 0)
	{
		N /= 2;
		ans++;
	}
	cin >> q;
	while (q--)
	{
		int in;
		cin >> in;
		for (int i = 1; i <= n; i++)
		{
			if (n == n2[n])
			{
				cout << ans << endl;
				break;
			}
			else if (a[i] == in)
			{
				cout << (i % 2 == 0 ? ans + 1 : ans) << endl;
			}
		}
	}
	return 0;
}
*/