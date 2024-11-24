/*
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

struct jilu
{
	int x, y, z;
};
jilu dian[50000];
bool paixu(jilu a,jilu b)
{
	return  a.z < b.z;
}


int main()
{
	int n;
	double ans=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> dian[i].x >> dian[i].y >> dian[i].z;
	}
	sort(dian, dian + n, paixu);
	for(int i=0;i<n-1;i++)
	{ 
		ans += sqrt(pow(dian[i].x - dian[i+1].x,2) + pow(dian[i].y - dian[i+1].y,2) + pow(dian[i].z - dian[i+1].z,2));
	}
	printf("%.3f", ans);
	return 0;
}
*/