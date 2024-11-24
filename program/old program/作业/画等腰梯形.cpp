/*
#include <iostream>
using namespace std;

int main()
{
	int n, sp, x, msp = 0, num = 0;
	cin >> n;
	sp = n - 1;
	x = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < sp; j++)cout << " ";
		if (i >= 1&&i<n-1)
		{
			cout << "*";
			for (int j = 0; j < msp; j++)cout << " ";
			cout << "*";
			for (int j = 0; j < n - 1; j++)cout << " ";
			for (int j = 0; j < msp; j++)cout << " ";
			cout << "*";
			msp++;
		}
		else if (i == n - 1)
		{
			for (int j = 0; j < n + (n - 1) * 2; j++)cout << "*";
		}
		else for (int j = 0; j < x; j++)cout << "*";
		cout << endl;
		sp--;
	}
	return 0;
}
*/