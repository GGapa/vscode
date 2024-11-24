/*
#include <iostream>
#include<cmath>
#include <algorithm>
#include<cstring>
using namespace std;

int n = 4,m;
int a[22];
string  value[10000];
int idx = 0;


void print(int b)
{
	int cnt = 0;
	int v[22] = { 0 };
	value[idx] = "";

	for (int i = 0; i < n; i++)
	{
		if (((b >> i) & 1) == 1)
		{
			v[cnt] = a[i];
			cnt++;
			value[idx] += a[i];
			if (cnt > m)return;
			//cout << a[i]<<" ";
		}
		
	}
	if (cnt == m)
	{
		idx++;
	}
}


int main()
{
	cin >> n >>m;
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	int bz = 0;
	for (int i = 0; i < pow(2, n); i++)
	{
		bz++;
		print(bz);
	}

	sort(value, value + idx);
	for (int i = 0; i < idx; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%3d", value[i][j]);
		}
		cout << endl;
	}


	return 0;
}
*/