/*
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;
#define maxn 30
map<string, int>m;
char op[maxn], ad[maxn];
bool cheak()
{
	int a, b, c, d, e, num;
	a = b = c = d = e = -1;
	if (sscanf_s(ad, "%d.%d.%d.%d:%d", &a, &b, &c, &d, &e) != 5)return false;
	if (a < 0 || a>255 || b < 0 || b>255 || c < 0 || c>255 || d < 0 || d>255 || e < 0 || e>65535)return false;
	char temp[maxn];
	sprintf_s(temp, "%d.%d.%d.%d:%d", a, b, c, d, e);
	return strlen(temp) == strlen(ad);
}
int main()
{
	int n, sn = 0, cn = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> op;
		cin >> ad;
		string temp(ad);
		if (op[0] == 'S')
		{
			
			if (!cheak())
			{
				cout << "ERR" << endl;
			}
			else if (m.count(temp)!=0)
			{
				cout << "FAIL" << endl;
			}
			else
			{
				cout << "OK" << endl;
				m.insert({temp, i});
			}

		}
		else
		{
			if (!cheak())
			{
				cout << "ERR" << endl;
			}
			else if (m.count(temp) == 0)
			{
				cout << "FAIL" << endl;
			}
			else
			{
				cout << m[temp] << endl;
			}
		}
	}
	return 0;
}

*/