/*
#include <iostream>
#include <algorithm>
using namespace std;

string ans;
void digui(string x)
{
	if (count(x.begin(), x.end(), '0') == x.length())
	{
		ans += "A";
	}
	else if (count(x.begin(), x.end(), '1') == x.length())
	{
		ans+="B";
	}
	else
	{	
		ans += "C";
		digui(x.substr(0, x.length() / 2));
		digui(x.substr(x.length() / 2, x.length() / 2));
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