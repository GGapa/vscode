/*
#include <iostream>
#include <string>
using namespace std;
int ans;
void digui(string x)
{
	bool bj = true;
	int len = x.length();
	if (len%2!=0)
	{
		ans = len;
		return;
	}
	int i = 0,j = len-1;
	while (i <j&&j>i)
	{
		if (x[i] != x[j])
		{
			ans = len;
			bj = false;
			return;
		}
		i++; j--;
	}
	if (bj)
	{
		digui(x.substr(0, len / 2));
	}
}
int main()
{
	string a;
	cin >> a;
	digui(a);
	cout << ans << endl;
}
*/