/*
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
map< string, int> a[1005];
int n, m, len[1005];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> len[i];
		for (int j = 0; j < len[i]; j++)
		{
			string temp;
			cin >> temp;
			a[i].insert({ temp, i + 1 });
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < n; j++)
		{
			if (a[j].count(input) > 0)
				cout << j + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}
*/