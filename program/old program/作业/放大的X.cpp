
#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (i == j || (j+i)==a-1)
			{
				cout << "X";
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

