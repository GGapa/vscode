
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string A, B;
	int a[500];
	int i;
	bool bj = false;
	cin >> A >> B;
	for (i = 0; i < 500; i++)
	{
		a[i] = 0;
	}
	for (i = A.length(); i >= 0; i--)
		a[A.length() - i] = A[i] - '0';
	for (i = 1; i < B.length() + 1; i++)
	{
		a[i] += (B[B.length() - i] - '0');
		if (a[i] >= 10)
		{
			a[i + 1] += 1;
			a[i] -= 10;
		}
	}
	for (i = 1; i < 500; i++)
	{
		if (a[500 - i] != 0)bj = true;
		if (bj)cout << a[500 - i];
	}
	if (!bj)cout << 0;
	cout << endl;
	return 0;

}

