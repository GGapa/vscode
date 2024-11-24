/*
#include <queue>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int m, it = 0;
string s, t, add;
struct number_
{
	int  step = -1;
	string vaule;
};
queue <number_> number;
number_ ls;
map<string, int> an;


void cl(int step, string v)
{
	if (an.count(v) != 0) return;
	number_ lls;
	lls.vaule = v;
	lls.step = number.front().step + 1;
	number.push(lls);
	an.insert({ lls.vaule,lls.step });
}

int main()
{
	cin >> s >> m;
	ls.vaule = s;
	ls.step = 0;
	number.push(ls);
	an.insert({ s, 0 });
	while (!number.empty())
	{
		number_ tmp = number.front();
		for (int i = 0; i < tmp.vaule.length(); i++)
		{
			for (int j = i + 1; j < tmp.vaule.length(); j++)
			{
				add = tmp.vaule;
				swap(add[i], add[j]);
				cl(tmp.step, add);
			}
		}
		if (tmp.vaule.length() > 1)
		{
			for (int i = 0; i < tmp.vaule.length(); i++)
			{
				add = tmp.vaule;
				add.erase(i, 1);
				cl(tmp.step, add);
			}
		}


		if (tmp.vaule.length() < s.length())
		{
			string temp = tmp.vaule;
			for (int i = 0; i < temp.length() - 1; i++)
			{
				for (char j = temp[i] + 1; j < temp[i + 1]; j++)
				{
					add = temp;
					add.insert(i + 1, 1, j);
					cl(tmp.step, add);
				}
			}
		}

		number.pop();
	}
	while (m--)
	{
		cin >> t;
		bool fin = true;
		cout << (an.count(t) > 0 ? an[t] : -1) << endl;
	}
	return 0;
}
*/