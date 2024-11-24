/*
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int P[13]={0}, K[13]={0}, H[13]={0}, T[13]={0};
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i += 3)
	{
		char l = a[i];
		if (l == 'P')
		{
			int h = int(a[i + 1] - 48) * 10 + int(a[i + 2] - 48) - 1;
			if (P[h] == 1)
			{
				cout << "GRESKA" << endl;
				return 0;
			}
			else
			{
				P[h] = 1;
			}
		}
		else if (l == 'K')
		{
			int h = int(a[i + 1] - 48) * 10 + int(a[i + 2] - 48)-1;
			if (K[h] == 1)
			{
				cout << "GRESKA" << endl;
				return 0;
			}
			else
			{
				K[h] = 1;
			}
		}
		else if (l == 'H')
		{
			int h = int(a[i + 1] - 48) * 10 + int(a[i + 2] - 48) - 1;
			if (H[h] == 1)
			{
				cout << "GRESKA" << endl;
				return 0;
			}
			else
			{
				H[h] = 1;
			}
		}
		else if (l == 'T')
		{
			int h = int(a[i + 1] - 48) * 10 + int(a[i + 2] - 48) - 1;
			if (T[h] == 1)
			{
				cout << "GRESKA" << endl;
				return 0;
			}
			else
			{
				T[h] = 1;
			}
		}
	
	}
	cout << count(begin(P), end(P), 0)<<" "<<count(begin(K), end(K), 0)<<" "<< count(begin(H), end(H), 0)<<" "<< count(begin(T), end(T), 0);
	return 0;
}
*/