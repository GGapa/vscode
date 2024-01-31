/*
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define maxn 100001
map<long long,long long> a;
int main()
{
	long long n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.insert({ x,i+1 });
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		cout << a[x] << endl;
	}
	return 0;
}
*/