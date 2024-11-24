/*
#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	for (int i = 1; i <= a * 2 - 1; i++)
	{
		for (int j = 1; j <= a * 3 - 2; j++)
		{
			if (i == 1 && a + 1 <= j && j < a * 2 - 1
				|| i + j == a+1
				|| j - i == a+(a-2)
				|| i + j == 3*a+(a-2)
				|| i - j == a-1
				|| i == a * 2 - 1 && a + 1 <= j && j < a * 2 - 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
*/