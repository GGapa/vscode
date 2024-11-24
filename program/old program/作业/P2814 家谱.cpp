/*
#include <iostream>
#include <string>
#include <map>
using namespace std;
string input;
char p;
map<string, string>a;
string find(string x)
{
	if (x == a[x])return x;
	return a[x] = find(a[x]);
}
void join(string x, string y)
{
	string f1 = find(x), f2 = find(y);
	if (f1 != f2)a[f1] = f2;
}
int main()
{
	string father;
	while (true)
	{
		cin >> input;
		if (input[0] == '$')
			break;
		if (input[0] == '#')
		{
			input.erase(0, 1);
			father = input;
			a.insert({ father,father });
		}
		if (input[0] == '+')
		{
			input.erase(0, 1);
			if (a.count(input) == 0)a.insert({ input,father });
			else a[input] = father;
		}
		if (input[0] == '?')
		{
			input.erase(0, 1);
				cout << input << " " << find(input) << endl;
		}
	}
	return 0;
}
*/