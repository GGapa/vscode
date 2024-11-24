/*
#include <iostream>
using namespace std;
long long n, a[50010] = { 0 }, m = 0, num = 0, len = 0, l[50010] = { 0 }, mo[50010] = { 0 };
long long first[10] = { 0 }, last[10] = { 0 };
int main()
{
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		l[i] = l[i - 1] + a[i];
		mo[i] = l[i] % 7;
	}
	for (int i = 0; i <= n; i++)last[mo[i]] = i;
	for (int i = n; i >= 0; i--)first[mo[i]] = i;
	for (int i = 0; i < 7; i++)
		m = max(m, last[i] - first[i]);
	cout << m << endl;
	return 0;
}
*/