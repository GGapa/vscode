/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
vector<string> a[26];
vector<int> num[26];
int minn[26] = { 1 };
int sit[26] = { 0 };
int main()
{
	int k, n;
	for (int i = 0; i < 26; i++)minn[i] = 1;
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		string temp;
		cin >> temp;
		a[temp[0] - 'a'].push_back(temp);
		num[temp[0] - 'a'].push_back(0);
	}
	for (int i = 0; i < 26; i++)
	{
		sort(a[i].begin(), a[i].end());
	}
	while (n--)
	{
		char temp;
		cin >> temp;
		for (int i = sit[temp-'a']; i <= a[temp - 'a'].size(); i++)
		{
			bool br = false;
			if (num[temp - 'a'][i] == minn[temp - 'a'] - 1)
			{
				sit[temp - 'a']++;
				cout << a[temp - 'a'][i] << endl;
				num[temp - 'a'][i]++;
				br = true;
			}
			if (num[temp - 'a'][num[temp - 'a'].size() - 1] == minn[temp - 'a'])
			{
				sit[temp - 'a'] = 0;
				minn[temp - 'a']++;
			}
			if (br)break;
		}
	}
	return 0;
}
*/