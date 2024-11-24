/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int i, j, k,n,q,num;
	cin >> n >> q;
	vector< vector<int> > a(n+1);
	while (q--)
	{
		cin >> num;
		if (num == 1)
		{
			cin >> i >> j >> k;
			if (a[i].size() < j + 1)
				a[i].resize(j + 1);
			a[i][j] = k;
		}
		else if (num == 2)
		{
			cin >> i >> j;
			cout << a[i][j] << endl;
		}
	}
	return 0;
}
*/