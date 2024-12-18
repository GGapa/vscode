/*
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m,a[100000],ls=0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	while (next_permutation(a, a + n))
	{
		ls++;
		if (ls == m)
		{
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			return 0;
		}
	}
}
*/