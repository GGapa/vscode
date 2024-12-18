/*
#include <iostream>
using namespace std;

int main()
{
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		long long  a, b, c, d,ans=0;
		cin >> a >> b >> c >> d;
		if (a == b && b == c && c == d && d == a)cout << 1 << endl;
		else if (a + b == c + d || a + c == b + d || a + d == b + c)
		{
			if (a == b || a == c || a == d || b == c || b == d || c == d)cout << "4" << endl;
			else if (a != b && a != c && a != d && b != c && b != d && c != d)cout << "8" << endl;

		}
		else cout << 0 << endl;
	}
	return 0;
}
*/