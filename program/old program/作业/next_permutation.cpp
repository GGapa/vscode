/*
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 4
int main()
{
	int a[maxn] = { 1,2,3,4 },b[maxn]={4,3,2,1};
	cout << 1 << endl;
	while (next_permutation(a, a + maxn))
	{
		for (int i = 0; i < maxn ; i++)
			printf("%3d", a[i]);
		cout << endl;
	}
	cout << 2 << endl;
	cout << endl;
	while (next_permutation(b, b + maxn))
	{
		for (int i = 0; i < maxn; i++)
			printf("%3d", b[i]);
		cout << endl;
	}
	cout << 3 << endl;
	cout << endl;
	sort(b, b + maxn);
	while (next_permutation(b, b + maxn))
	{
		for (int i = 0; i < maxn; i++)
			printf("%3d", b[i]);
		cout << endl;
	}
	return 0;
}
*/