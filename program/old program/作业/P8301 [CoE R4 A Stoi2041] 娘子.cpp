/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string a, b;
	int n;
	cin >> n;
	cin >> a >> b;
	int x, y, c, d,ans=0;
	x = count(a.begin(), a.end(), '1');
	y = count(b.begin(), b.end(), '1');
	c = count(a.begin(), a.end(), '0');
	d = count(b.begin(), b.end(), '0');
	while (x!=y||c!=d)
	{
		if (x > y)
		{
			ans += 1;
			x--; c++;
		}
		else if (x < y)
		{
			ans += 1;
			x++; c--;
		}
	}
	cout << ans << endl;
}
*/