/*
#include <iostream>
using namespace std;

int main()
{
	int i[100]{};
	int j, a;
	for (int q = 0; q < 500; q = q + 5)
	{
		j = q / 5;
		i[j] = q;
	}
	cin >> a;
	for (int p = 0; p < 100; p++)
	{
		if (a % 5 == 0)
		{
			cout << a << endl;
			break;
		}
		if (a > 495)
		{
			cout << 495 << endl;
			break;
		}
		if (i[p] < a && a < i[p + 1])
		{
			cout << i[p] <<""<< i[p + 1] << endl;
			break;
		}
	}
	return 0;
}
*/