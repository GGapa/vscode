/*
#include <iostream>
using namespace std;

bool bj;
int n, i;
struct student
{
	string name;
	int xuehao, c1, c2, peo;
	int all()
	{
		return c1 + c2;
	}
	int pj()
	{
		return c1 * 0.7 + c2 * 0.3;
	}
	int panduan()
	{
		return (all() > 140 && pj() >= 80);
	}
};

int main()
{
	cin >> n;
	student peo[1000];
	for (i = 0; i < n; i++) cin >> peo[i].xuehao >> peo[i].c1 >> peo[i].c2;
	for (i = 0; i < n; i++)
	{
		if (peo[i].panduan())cout << "Excellent";
		else cout << "Not excellent";
		cout << endl;
	}
	return 0;
}
*/