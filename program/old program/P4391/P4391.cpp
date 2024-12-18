// P4391 [BOI2009] Radio Transmission 无线传输
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n;
string a;

int Next[10000005];

int main()
{
	cin >> n >> a;
	int j = 0;
	a.insert(0," ");
	for (int i = 2; i <= n; ++i)
	{
		while (j && a[i] != a[j + 1])
			j = Next[j];
		if (a[i] == a[j + 1])
			++j;
		Next[i] = j;
	}
	cout << n - Next[n] << endl;
	return 0;
}