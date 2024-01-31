/*
#include <iostream>
#include <string>
#define chu 1000000007;
using namespace std;

string T;
int ans = 0, n, m;
string S, R;
void digui(string a, string b, int f)
{
	if (b == T)
	{
		ans++;
		ans %= chu;
		a = S; b = "";
		return;
	}
	if (f == 1)
	{
		while (a != "")
		{
			if (a[0] == '-')
			{
				b.erase(b.length()-1);
				a.erase(0, 1);
				digui(a, b, 0);
			}
			else
			{
				b += a[0];
				a.erase(0, 1);
			}
		}
	}
	else
	{
		while (a != "")
		{
			if (a[0] == '-')
			{
				b[0] += a[0];
				b.erase(0, 1);
				a.erase(0, 1);
				digui(a, b, 0);
			}
			else
			{
				b += a[0];
				a.erase(0, 1);
			}
		}
	}
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m>>S>>T;
		digui(S, R, 1);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
*/