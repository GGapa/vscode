/*
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
queue<long>a;
int b[4] = { 2,3,5,7 };
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ls;
		cin >> ls;
		a.push(ls);
	}
	while (!a.empty())
	{
		bool bj = true;
		for (int i = 2; i < sqrt(a.front()) + 1; i++)
		{
			if (a.front() % i == 0)
			{
				if (count(b, b + 4, i) != 1)
				{
					bj = false;
					break;
				}
			}
		}
		if (bj)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
		a.pop();
	}
	return 0;
}
*/