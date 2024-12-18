/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int plusm(int x, int y)
{
	return x + y;
}
int redu(int x, int y)
{
	return x - y;
}
int muti(int x, int y)
{
	return x * y;
}
int bmod(int x, int y)
{
	return abs(x % y);
}
int ldiv(int x, int y)
{
	return floor(x / y);
}
int cdiv(int x, int y)
{
	double a = double(x) / double(y);
	if (x % y == 0)
		return x / y;
	else
		return ceil(a);
}


int main()
{
	int n, x, y;
	string input;
	cin >> n;
	while (n--)
	{
		cin >> input >> x >> y;
		if (input == "plus")cout << plusm(x, y) << endl;
		if (input == "redu")cout << redu(x, y) << endl;
		if (input == "muti")cout << muti(x, y) << endl;
		if (input == "bmod")cout << bmod(x, y) << endl;
		if (input == "ldiv")cout << ldiv(x, y) << endl;
		if (input == "cdiv")cout << cdiv(x, y) << endl;
	}
	return 0;
}
*/