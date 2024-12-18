/*
#include<iostream>
using namespace std;

int jisuan(int a, int b, int c)
{
	if((a%b)==0) return ((a / b) * c);
	else return ((a / b + 1) * c);
}

int main()
{
	int small = 10001, n, h, m;
	cin >> n;
	cin >> h >> m;
	small = jisuan(n, h, m);
	cin >> h >> m;
	if (jisuan(n, h, m) < small) small = jisuan(n, h, m);
	cin >> h >> m;
	if (jisuan(n, h, m) < small) small = jisuan(n, h, m);
	cout << small << endl;
	return 0;
}
*/