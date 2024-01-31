/*
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a[1001][3], n, i, j,q,num=0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (q = i+1; q < n; q++)
		{
			if(fabs(a[i][0]-a[q][0])<=5
			&& fabs(a[i][1] - a[q][1]) <= 5
			&& fabs(a[i][2] - a[q][2]) <= 5
			&& fabs((a[i][0]+a[i][1]+ a[i][2])- (a[q][0] + a[q][1] + a[q][2]))<=10) num++;
		}
	}
	cout << num << endl;
	return 0;
}
*/