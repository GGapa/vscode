#include <iostream>
#include <vector>
#include <algorithm>
/*
#include <queue>
#include <list>
#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
map <long long, long long> a;
inline long long read() 
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int main()
{
	long long t, n, num;
	t = read();
	while (t--)
	{
		n = read();
		num = 0;
		long long len = n;
		for (int i = 0; i < n; i++)
		{
			long long input;
			input = read();
			//vector<long long >::iterator it = count(a.begin(), a.end(), input);
			//int it = count(a.begin(), a.end(), input);

			if (a.insert({ input, input }).second == true)
			{
				printf_s("%d ", input);
				//a.insert(input,input)
			}
		}
		puts("");
		a.clear();
	}
	return 0;
}
*/