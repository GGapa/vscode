/*
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int t, n, x, a[100], iffind = 0;
	cin >> t;
	while (t--)
	{
		cin >> n >> x;
		iffind = 0;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)cin >> a[i];
		if (x > 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i] > 0)
				{
					cout << "Yes" << endl;
					iffind = 1;
					break;
				}
			}
			if (iffind == 0)
			{
				for (int i = 0; i < n; i++)
				{
					if (x % a[i] != 0)
					{
						cout << "Yes" << endl;
						iffind = 1;
						break;
					}
				}
			}
		}
		else if (x < 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i] < 0)
				{
					cout << "Yes" << endl;
					iffind = 1;
					break;
				}
			}
			if (iffind == 0)
			{
				for (int i = 0; i < n; i++)
				{
					if (x % a[i] != 0)
					{
						cout << "Yes" << endl;
						iffind = 1;
						break;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i] != 0)
				{
					cout << "Yes" << endl;
					iffind = 1;
					break;
				}
			}
			if (iffind == 0)
			{
				for (int i = 0; i < n; i++)
				{
					if (x % a[i] != 0)
					{
						cout << "Yes" << endl;
						iffind = 1;
						break;
					}
				}
			}
		}
		if (iffind == 0)cout << "No" << endl;
	}
}
*/