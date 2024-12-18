/*
#include <iostream>
#include <cstring>
using namespace std;

struct xj
{
	int haoma;
	string ps;
};

int main()
{
	string big;
	xj a[20];
	int n,max=-1,hm;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].ps;
		a[i].haoma = i + 1;
		int t = a[i].ps.length();
		if (t > max)
		{
			max = t;
			hm = a[i].haoma;
			big = a[i].ps;
		}
		else if (t == max)
		{
			if (a[i].ps > big)
			{
				big = a[i].ps;
				hm = a[i].haoma;
			}
		}
	}
	cout << hm <<endl<<big << endl;
	return 0;
}
*/