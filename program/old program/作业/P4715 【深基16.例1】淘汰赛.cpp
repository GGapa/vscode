/*
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
int n, b[1000] = { 0 }, num = 1;
struct a_
{
	int number;
	int power;
};
int main()
{
	queue<a_> a;
	cin >> n;
	n = 1 << n;
	while (n--)
	{
		int x;
		cin >> x;
		a_ team;
		team.number = num++;
		team.power = x;
		a.push(team);
	}
	while (a.size() > 2)
	{
		a_ l, r;
		l = a.front();
		a.pop();
		r = a.front();
		a.pop();
		if (l.power > r.power)
		{
			a.push(l);
		}
		else
			a.push(r);
	}
	a_ l, r;
	l = a.front();
	a.pop();
	r = a.front();
	a.pop();
	if (l.power > r.power)
	{
		cout << r.number << endl;
	}
	else
		cout << l.number << endl;

	return 0;
}
*/