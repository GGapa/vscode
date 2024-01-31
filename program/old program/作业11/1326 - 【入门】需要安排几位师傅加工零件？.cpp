/*
#include <iostream>
#include <algorithm>
using namespace std;
int a[101];
int paixu(int x, int y)
{
	return x > y;
}
int main()
{
	int m, n,num=0;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n,paixu);
	for (int i = 0; i < n; i++){
		num += a[i];
		if (num >= m){
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
*/