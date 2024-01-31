/*
#include <iostream>
using namespace std;

int a[1000001] = { 0,1,2,3,4,1,2,3,4,5,2,1 };
int main()
{
	int n;
	cin >> n;
	for (int i = 12; i <= n; i++)
	{
		a[i] = min(min(a[i - 1], a[i - 5]), a[i - 11]) + 1;
	}
	cout << a[n] << endl;
}
*/