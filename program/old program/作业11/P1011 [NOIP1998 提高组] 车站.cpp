/*
#include <iostream>
using namespace std;

int main()
{
	int a,n,m,x,y[26],z[26]={0};
	cin >> a >> n >> m >> x;
	y[2] = 1;
	y[3] = 2;

	for (int i = 4; i < n; i++)
	{
		y[i] = y[i - 1] + y[i - 2] - 1;
		z[i] = z[i - 1] + z[i - 2] + 1;
	}
	cout << a * y[x] + ((m - a * y[n - 1]) / z[n - 1]) * z[x]<<endl;
	return 0;
}
*/