/*
#include <iostream>
using namespace std;
#define maxn 1<<20
int a[maxn],n,q;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> q;
   	int ans = 0, N = n;
	while (n % 2 == 0)
	{
		n /= 2;
		ans++;
	}
	while (q--)
	{
		int in;
		cin >> in;
		cout << ans << endl;
	}
	return 0;
}

*/