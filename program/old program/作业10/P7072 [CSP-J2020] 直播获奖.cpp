/*
#include <iostream>
using namespace std;

int main()
{
	int a[601]={0}, n, num;
	double w;
	cin >> n >> w;
	for (int i = 1; i <= n; i++)
	{
		int ls;
		cin >> ls;
		a[ls]++;
		num = max(1, int(i * (w * 0.01)));
		ls = 0;
		for (int j = 600; j >= 0; j--)
		{
			ls += a[j];
			if (ls >= num) {
				cout << j << " ";
				break;
			}
		}

	}
	return 0;

}
*/