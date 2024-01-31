/*
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n, i,ls;
	string a;
	cin >> n;
	cin >> a;
	ls = n % 26;
	for (i = 0; i < 60; i++)
	{
		if (a[i] == '\0') break;
		int t =a[i] + ls;
		if (t > 'z') t -=26;
		
		cout << char(t);
	}
	return 0;
}
*/