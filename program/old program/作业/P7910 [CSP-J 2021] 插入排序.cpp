/*
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 8005
long long n, m, b[maxn], c[maxn];
struct node
{
	long long vaule, pre;
};
node a[maxn];
int cus(node x, node y)
{
	if (x.vaule != y.vaule) 
		return x.vaule < y.vaule;
	return x.pre < y.pre;
}
int main()
{
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i].vaule;
		a[i].pre = i;
	}
	sort(a+1, a + n+1, cus);
	for (long long i = 1; i <= n; i++)
		b[a[i].pre] = i;
	for (long long i = 0; i < m; i++)
	{
		long long input;
		cin >> input;
		if (input == 1)
		{
			long long temp1, temp2, past, it;
			cin >> temp1 >> temp2;
			a[b[temp1]].vaule = temp2;
			for (int j = 2; j <= n; j++)
			{
				if (cus(a[j], a[j - 1]))
				{
					swap(a[j], a[j - 1]);
				}
			}
			for (int j = n; j >= 2; j--)
			{
				if (cus(a[j], a[j - 1]))
				{
					swap(a[j], a[j - 1]);
				}
			}
			for (int i = 1; i <= n; i++)
				b[a[i].pre] = i;
		}
		if (input == 2)
		{
			long long temp;
			cin >> temp;
			cout << b[temp] << endl;
		}
	}
	return 0;
}
*/