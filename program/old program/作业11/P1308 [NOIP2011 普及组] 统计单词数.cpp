/*
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define npos string::npos
int main()
{
	string f, a;
	getline(cin, f);
	getline(cin, a);
	for (int i = 0; i < f.length(); i++)
		f[i] = tolower(f[i]);
	for (int i = 0; i < a.length(); i++)
		a[i] = tolower(a[i]);
	a = ' ' + a + ' ';
	f = ' ' + f + ' ';
	int wie = -1, cont = 0, num = 0;
	if (a.find(f) == npos)
	{
		cout << -1 << endl;
	}
	else
	{
		int alpha = a.find(f);
		int beta = a.find(f);
		while (beta != npos) {
			cont++;
			beta = a.find(f, beta + 1);
		}
		cout << cont << " " << alpha << endl;//输出第一个和总共有几个
	}
	return 0;
}
*/