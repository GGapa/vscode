/*
#include <iostream>
using namespace std;
#define maxn 1005
int n, a[maxn][maxn], man = 0, num = 0;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	for (int i = n; i >= 1; i--)
		for (int j = i; j >= 1; j--)
			a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
	cout << a[1][1] << endl;
	return 0;
}
*/