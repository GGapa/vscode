/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ls, a;
	cin >> ls;
	int len = ls.length();
	a += ls;
	for (int i = 0; i < len-1; i++)
	{
		cin >> ls;
		a += ls;
	}
	cout << len << " ";
	int ans = 1;
	if (a[0] != '0')cout << 0 << " ";
	for (int i = 0; i < a.length()-1; i++)
	{
		if (a[i] == a[i + 1])ans++;
		else
		{
			cout << ans << " ";
			ans = 1;
		}
	}
	cout << ans << endl;
	return 0;
}
*/