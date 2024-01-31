/*
#include <iostream>
using namespace std;
int a;
int main()
{
	int n, m=-1,ans=0,ma=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a > m)
		{
			ans++;
			ma = max(ma, ans); m = a;
		}
		else
		{
			m = a; ans = 1;
		}
	}
	cout << ma << endl;
	return 0;

}
*/