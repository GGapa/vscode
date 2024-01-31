/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
struct aaa
{
	string unix, number, timu;
	int grades;
}text[200006];
map<string, vector< long long> >grades;
set<string>student;
map<long long, bool>used;
map<long long, long long>s;
map<string, bool>bj;
bool cmp(aaa x, aaa y)
{
	if (x.unix == y.unix)
	{
		return x.timu < y.timu;
	}
	return x.unix < y.unix;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * 2; i++)
	{
		string input;
		cin >> input >> text[i].grades;
		text[i].unix = input.substr(0, 10);
		text[i].number = input.substr(10, 14);
		if (student.count(text[i].number) == 0)student.insert(text[i].number);
		text[i].timu = input.substr(24, 3);
	}
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		s.insert({ temp,temp });
	}
	sort(text, text + (2 * n), cmp);
	for (int i = 0; i < 2 * n; i += 2)
	{
		int tep = i, sum = 0;
		while (text[tep].unix != text[tep + 1].unix && tep + 1 < 2 * n)
		{
			sum = ceil(double(text[tep].grades + text[tep + 1].grades) / 2);
			tep += 2;
		}
		grades[text[i].number].push_back(sum);
		i = tep;
	}
	for (set<string>::iterator i = student.begin(); i != student.end(); i++)
	{
		int num = 0;
		bool ifa = false;
		for (int j = 0; j < grades[*i].size(); j++)
		{
			ifa = false;
			if (used[grades[*i][j]])continue;
			for (int q = 0; q < m; q++)
			{
				if (s[q] == grades[*i][j])
				{
					num++;
					ifa = true;
				}
			}
			if (ifa = false)
				break;
			else
			{
				for (int ii = 0; ii < 2 * n; ii++)
				{
					if (text[ii].number == *i&&bj[text[ii].unix]==false)
					{
						bj[text[ii].unix] = true;
						cout << text[ii].unix << endl;
					}
				}
				return 0;
			}
		}
	}
	return 0;
}
*/