/*
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue <int>a;
	int n, m, ans = 0;
	bool b[1000]={false};
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		a.push(-1);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (b[num]==false)
		{
			a.push(num);
			b[num] = true;
			if(a.front() != -1)b[a.front()] = false;
			a.pop();
			ans++;
		}
	}
	cout << ans << endl;
	return 0;

}
*/