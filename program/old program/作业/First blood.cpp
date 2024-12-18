/*
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<string, string >competition;
map<string, string>people;
string name[10000];
int main()
{
	int n, m;
	string temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> temp, competition.insert({ temp,"none" }), name[i] = temp;
	for (int i = 0; i < m; i++)
	{
		string name, text;
		int grades;
		cin >> name >> text >> grades;
		if (grades == 100 && competition[text] == "none" && people[name] == "")
		{
			competition[text] = name;
			people[name] = text;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << name[i] <<" : " << competition[name[i]] << endl;
	}
}
*/