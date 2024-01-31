/*
#include <iostream>
#include <stack>
#include <string>
#include <set>
#include <queue>
using namespace std;
stack<int>a;
int m[200001]={0};
int n,num=0;
int main()
{
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			int y;
			cin >> y;
			a.push(y);
			num++;
			m[num] = max(m[num - 1], y);
		}
		else if (x == 1)
		{
			a.pop();
			if (num != 0)
				num--;
		}
		else if (x == 2)
		{
			cout << m[num] << endl;
		}
		
	}
	return 0;
}
*/