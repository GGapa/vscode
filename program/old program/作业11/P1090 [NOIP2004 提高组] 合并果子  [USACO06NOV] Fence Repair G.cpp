/*
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector <int>,greater<int> >a;

int main()
{
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l;
		cin >> l;
		a.push(l);
	}
	while (a.size() >= 2)
	{
		int temp1 = a.top();
		a.pop();
		int temp2 = a.top();
		a.pop();
		ans = ans + temp1 + temp2;
		a.push(temp1+temp2);
	}
	cout << ans << endl;
	return 0;
}
*/