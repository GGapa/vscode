/*
#include <iostream>
#include<queue>
#include <algorithm>
constexpr auto maxn = 100001;
using namespace std;
int num = 0,b[maxn]={0},ans=0;
int main()
{
	queue<int> people,Time,a;
	int n;
	cin >> n;
	while (n--)
	{
		int t, k, x, p;
		cin >> t >> k;
		Time.push(t);
		people.push(k);
		for (int i = 0; i < k; i++)
		{
			cin >> x;
			a.push(x);
			if (b[x] == 0)
				ans++;
			b[x]++;
		}
		while (Time.back() - Time.front() >= 86400)
		{
			int ls = people.front();
			while (ls--)
			{
				b[a.front()]--;
				if (b[a.front()] == 0)
					ans--;
				a.pop();
			}
			people.pop();
			Time.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
*/