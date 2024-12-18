/*
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
map<char, int>add;
int main()
{
	int n,ans=0;
	cin >> n;
	add.insert({ 'A',4 });
	add.insert({ 'K',3 });
	add.insert({ 'Q',2 });
	add.insert({ 'J',1 });
	add.insert({ 'X',0 });
	while (n--)
	{
		string input;
		cin >> input;
		for (int i = 0; i < input.length(); i++)
		{
			ans += add[input[i]];
		}
	}
	cout << ans << endl;
	return 0;
}
*/