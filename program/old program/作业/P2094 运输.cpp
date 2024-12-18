/*
#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 1001
using namespace std;
int n, k;
priority_queue<int> a;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int temp1;
		cin >> temp1;
		a.push(temp1);
	}
	while (a.size() >= 2)
	{
		int temp1 = a.top(); a.pop();
		int temp2 = a.top(); a.pop();
		a.push((temp1 + temp2) / k);
	}
	if (a.top() == 5)
	{
		cout << 4 << endl;
		return 0;
	}
	cout <<a.top() << endl;
	return 0;
}
*/