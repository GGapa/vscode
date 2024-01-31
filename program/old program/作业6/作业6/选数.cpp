/*
#include <iostream>
using namespace std;

int a[20],n;
int k;
bool zhishu(int x) 
{
	for (int i = 2; i*i <= x; i++)
		if (x % i == 0)return false;
	return true;
}

int xuanshu(int x, int y, int z) 
{
	int sum = 0;
	if (x == 0)return zhishu(y);
	for (int i = z; i < n; i++) {
		sum += xuanshu(x - 1, y + a[i], i+1);
	}
	return sum;
}

int main()
{
	int i;
	cin >> n >> k;
	for (i = 0; i < n; i++) cin >> a[i];
	cout << xuanshu(k, 0, 0) << endl;
	return 0;
}
*/