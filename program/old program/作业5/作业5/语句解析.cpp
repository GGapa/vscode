/*
#include <iostream>
#include <cstring>
using namespace std;
string P;
int i;
int a = 0, b = 0, c = 0,bj=0;
int panduan()
{
	int ls = 0;
	if (P[i + 3] == 'a')
		ls = a;
	else if (P[i + 3] == 'b')
		ls = b;
	else if (P[i + 3] == 'c')
		ls = c;
	else ls = int(P[i + 3]) - 48;
	bj++;
	return ls;
}


int main()
{
	cin >> P;
	char ls;
	int num;
	for (i = 0; i < 255; i += 5)
	{
		if (P[i] == '\0') break;
		if (P[i] == ';')num++;
	}
	for (i = 0; i < 255; i += 5)
	{
		if (P[i] == 'a' && P[i + 1] == ':' && P[i + 2] == '=')
		{
			a=panduan();
		}
		else if (P[i] == 'b' && P[i + 1] == ':' && P[i + 2] == '=')
		{
			b=panduan();
		}
		else if (P[i] == 'c' && P[i + 1] == ':' && P[i + 2] == '=')
		{
			c=panduan();
		}
		if (bj == num) break;
	}
	cout << a << " " << b << " " << c << endl;
}
*/