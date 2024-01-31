
#/*include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	char b;
	int l[500][2]={0};
	cin >> n >> b;

	int ans = 0;
	for (int i = 0; i < n * 4; i++)
	{
		char x,y;
		cin >> x>>y;
		if (y == b)
		{
			switch (x)
			{
			case('A'):
				ans += 11;
				continue;
			case('K'):
				ans += 4;
				continue;
			case('Q'):
				ans += 3;
				continue;
			case('J'):
				ans += 20;
				continue;
			case('T'):
				ans += 10;
				continue;
			case('9'):
				ans += 14;
				continue;
			case('8'):
				ans += 0;
				continue;
			case('7'):
				ans += 0;
				continue;
			}
		}
		else
		{
			switch (x)
			{
			case('A'):
				ans += 11;
				continue;
			case('K'):
				ans += 4;
				continue;
			case('Q'):
				ans += 3;
				continue;
			case('J'):
				ans += 2;
				continue;
			case('T'):
				ans += 10;
				continue;
			case('9'):
				ans += 0;
				continue;
			case('8'):
				ans += 0;
				continue;
			case('7'):
				ans += 0;
				continue;
			}
		}
	}
	cout << ans << endl;
}
*/