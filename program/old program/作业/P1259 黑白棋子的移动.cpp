/*
#include <iostream>
#include <cstring>
using namespace std;
char a[210];
int n;

void print()
{
	for (int i = 0; i < 2 * n + 2; i++)
		cout << a[i];
	cout << endl;
}


void digui(int x, int y,int r)
{
	a[x+r] = a[x]; a[y + r] = a[y]; a[x] = '-'; a[y] = '-';
	print();
	if (x <= 3)
		return;
	a[x] = '*'; a[y] = '*'; a[x + r - 2] = '-'; a[y + r - 2] = '-';
	print();
	digui(x - 1, y - 1,r-1);
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = 'o';
	for (int i = n; i < 2 * n; i++)
		a[i] = '*';
	for (int i = n * 2; i < n * 2 + 2; i++)
		a[i] = '-';
	print();
	digui(n - 1, n,n+1);
	a[3] = a[7]; a[4] = a[8]; a[7] = a[8] = '-';
	print();
	a[7] = a[1]; a[8] = a[2]; a[1] = a[2] = '-';
	print();
	a[1] = a[6]; a[2] = a[7]; a[6] = a[7] = '-';
	print();
	a[6] = 'o'; a[7] = '*'; a[0] = a[1] = '-';
	print();
	return 0;
}
*/