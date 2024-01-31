/*
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string n;
	int m, d,ans=0;
	cin >> n;
	m = (n[0] - '0') * 10 + (n[1] - '0');
	d = (n[3] - '0') * 10 + (n[4] - '0');
	switch (m)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		if (0>=d||d > 31)
			ans++;
		break;
	case 4:case 6:case 9:case 11:
		if (0 >= d || d > 30)
			ans++;
		break;
	case 2:
		if (0 >= d || d > 28)
			ans++;
		break;
	default:
		ans++;
		int l = n[0] - '0', m=0,m1=0;
		switch (l)
		{
		case 1:case 3:case 5:case 7:case 8:case 0:case 2:
			if (0 >= d || d > 31)
				m++;
			break;
		case 4:case 6:case 9:case 11:
			if (0 >= d || d > 30)
				m++;
			break;
		default:
			m++;
			break;
			int l = m / 10;
		}
		l = n[1] - '0';
		switch (l)
		{
		case 1:case 3:case 5:case 7:case 8:case 0:case 2:
			if (0 >= d || d > 31)
				m1++;
			break;
		case 4:case 6:case 9:case 11:
			if (0 >= d || d > 30)
				m1++;
			break;
		default:
			m1++;
			break;
		}
		ans += max(m, m1);

	}
	cout << ans << endl;
	return 0;

}
*/