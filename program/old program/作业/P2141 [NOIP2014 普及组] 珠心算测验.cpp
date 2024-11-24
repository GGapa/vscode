/*
#include <iostream>
using namespace std;

int main()
{
	int a[100], n, ans = 0, ls;
	bool br = false;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		br = false;
		for (int j = 0; j < n; j++)
		{
			for (int q = 0; q < n; q++)
			{
				if (q != i && q != j&&i!=j)
				{
					if (a[j] + a[q] == a[i])
					{
						ans++;
						br = true;
						break;
					}
				}
				
			}
			if (br)break;
		}
	}
	cout << ans << endl;
	return 0;
}
*/