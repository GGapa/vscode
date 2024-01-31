/*
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

struct peo
{
	string name;
	int nian;
	int yue;
	int ri;
	long long date;
	int shunxu;
};
peo student[100];
bool paixu(peo a, peo b)
{
	if (a.date == b.date)
		return a.shunxu > b.shunxu;
	else return a.date < b.date;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> student[i].name >> student[i].nian >> student[i].yue >> student[i].ri;
		student[i].date = student[i].nian * 10000 + student[i].yue * 100 + student[i].ri;
		student[i].shunxu = i;
	}
	sort(student, student + n, paixu);
	for (int i = 0; i < n; i++)
	{
		cout << student[i].name << endl;
	}
	return 0;
}
*/