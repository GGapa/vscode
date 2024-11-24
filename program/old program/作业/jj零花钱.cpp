/*
#include <iostream>
using namespace std;
int main()
{
	int i, j, q, all=0, mom=0, liu=0,n,a[12],b;
	for (i = 0; i < 12; i++) cin >> a[i];
	for (i = 0; i < 12; i++)
	{
		all+=300;
		all -= a[i];
		if (all < 0)
		{
			cout << "-" << i + 1 << endl;
			return 0;
		}
		b = all / 100;
		mom += b * 100;
		all -= b * 100;
	}
	all += mom * 1.2;
	cout << all << endl;

}
*/