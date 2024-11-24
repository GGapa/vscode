/*
#include <iostream>
using namespace std;

int main()
{
	int x, y,ans=0,a[4000],ls=0;
	cin >> x >> y;
	for (int i = 0; i < 4000; i++)
	{
		a[i] = -1;
	}
	for (int i = x; i <= y; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
		{
			ans++;
			a[ls++] = i;
		}
	}
	ls = 0;
	cout << ans << endl;
	while (a[ls] != -1)
	{
		cout << a[ls] << " ";
		ls++;
	}
	cout << endl;
	return 0;
}
*/