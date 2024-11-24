/*
#include  <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int s, v, h = 8, m = 0;
	cin >> s >> v;
	int t = s % v == 0 ? s / v : s / v + 1;
	t += 10;
	m = t;
	h -= t%60==0?(t / 60): (t / 60 + 1);
	m = 60 - m % 60;
	m = m == 60 ? 0 : m;
	h = h < 0 ?  24+h : h;
	printf("%02d:%02d", h, m);
	return 0;
}
*/