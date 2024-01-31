/*
#include <iostream>
#include <queue>
using namespace std;
queue<int>a[1005];
queue<int>ans;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
		{
			int input;
			cin >> input;
			a[i].push(input);
		}
	}
	bool notend = true;
	while (notend)
	{
		notend = false;
		for (int i = 0; i < n; i++)
		{
			if (a[i].size() == 0) 
				continue;
			ans.push(a[i].front());
			a[i].pop();
			notend = true;
		}
	}
	while (!ans.empty())
	{
		cout << ans.front() << " ";
		ans.pop();
	}
	return 0;
}
*/