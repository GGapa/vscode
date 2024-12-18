/*
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, t[3][2], end = 0, begin = 999999999;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++)
	{
		cin >> t[i][0] >> t[i][1];
		if (t[i][0] < begin)
		{
			begin = t[i][0];
		}
		if (t[i][1] > end)
		{
			end = t[i][1];
		}
	}
	int num = 0;
	int ans = 0;
	for (int i = begin; i < end; i++)
	{
		num = 0;
		if (t[0][0] <= i && i < t[0][1])num++;
		if (t[1][0] <= i && i < t[1][1])num++;
		if (t[2][0] <= i && i < t[2][1])num++;
		if (num == 1)ans += a;
		if (num == 2)ans += b*2;
		if (num == 3)ans += c*3;
	}
	cout << ans << endl;
	return 0;

}
*/