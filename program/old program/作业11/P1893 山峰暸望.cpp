/*
#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
int hight[20005];
struct mou
{
	int iterator, hight = INT_MIN;
}mountian[20005];
int main()
{
	int n, ans = INT_MIN, wide = 0, wide2 = 0, it = 1;
	bool ifmax = false, up = true, down = false;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> hight[i];
		if (mountian[it].hight > hight[i] && !down)
		{
			it++;
			down = true;
			up = false;
		}
		if (up)mountian[it].hight = max(hight[i], mountian[it].hight), mountian[it].iterator = i;
		if (down)mountian[it].hight = min(hight[i], mountian[it].hight);
		if (down && mountian[it].hight < hight[i])down = false, up = true;
	}
	hight[0] = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		wide = 1;
		if (mountian[i].iterator == 0)break;
		int temp = mountian[i].iterator;
		while (hight[temp] >= hight[temp - 1] && temp - 1 > 0)temp--, wide++;
		temp = mountian[i].iterator;
		while (hight[temp] >= hight[temp + 1] && temp + 1 <= n)temp++, wide++;
		ans = max(ans, wide);
	}
	cout << ans << endl;
	return 0;
}
*/