/*
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int n, k, a[30005]={0};
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		a[input]++;
	}
	int num = 0;
	for (int i = 0; i <= 30000; i++)
	{
		a[i] > 0 ? num++ : 1;
		if (num == k)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << "NO RESULT" << endl;
	return 0;
}
*/