/*
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 1000005
long long a[maxn] = { 0 };

int main()
{
	long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	long long num = n;
	long long sum = 0;
	while (sum < m)
	{
		sum += (a[num] - a[num - 1]) * (n - num + 1);
		num--;
	}
	num++;
	cout << a[num-1] + (sum - m) / (n - num + 1) << endl;
	return 0;
}
*/