/*
#include <iostream>
#include <map>
#include <string>
#define maxn 100005
#define ll long long
using namespace std;
int n;
map<string, ll>a;
int main()
{
	cin >> n;
	while (n--)
	{
		int input;
		string name;
		ll score;
		cin >> input;
		if (input == 1)
		{
			cin >> name >> score;
			if (a.count(name) == 0)
			{
				a.insert({ name,score });
			}
			else
				a[name] = score;
			cout << "OK" << endl;
		}
		else if (input == 2)
		{
			cin >> name;
			if (a.count(name) != 0)
			{
				cout << a[name] << endl;
			}
			else
				cout << "Not found" << endl;
		}
		else if (input == 3)
		{
			cin >> name;
			if (a.count(name) != 0)
			{
				a.erase(name);
				cout << "Deleted successfully" << endl;
			}
			else
			{
				cout << "Not found" << endl;
			}
		}
		else
		{
			cout << a.size() << endl;
		}
	}
	return 0;
}

*/