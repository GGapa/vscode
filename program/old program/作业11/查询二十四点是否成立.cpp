/*
#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> a;
int main()
{
	int n, num = 0;
	cin >> n;
	while (n--)
	{
		int size = 3;
		string ls;
		cin >> ls;
		for (int i = 0; i < 7; i++)
		{
			for (int i = 0; i < ls.length() && ls.length() >= 3; i++)
			{
				int x = ls[i] - '0';
				char y = ls[i + 1];
				int z = ls[i + 2] - '0';
				if (y == '*')
				{
					ls.erase(i, 2);
					ls[i] = x * z + '0';
				}
				else if (y == '/')
				{
					ls.erase(i, 2);
					ls[i] = x / y + '0';
				}
				else if (y == '+')
				{
					ls.erase(i, 2);
					ls[i] = x + z + '0';
				}
				else if (y == '-')
				{
					ls.erase(i, 2);
					ls[i] = x - z + '0';
				}
				size += 2;
			}
			if (ls.length() == 1)
				num = ls[0] - '0';
		}
		if (num == 24)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
*/