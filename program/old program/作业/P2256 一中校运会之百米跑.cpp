/*
#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string, string>a;
int n, m,k;
string find(string x)
{
	return a[x] == x ? x : (a[x] = find(a[x]));
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		a.insert({ input,input });
	}
	for (int i = 0; i < m; i++)
	{
		string in1, in2;
		cin >> in1 >> in2;
		string x = find(in1), y = find(in2);
		if (x != y)a[x] = y;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		string in1, in2;
		cin >> in1 >> in2;
		string x = find(in1), y = find(in2);
		if (x != y)cout << "No."<<endl;
		else cout << "Yes."<<endl;
	}
	return 0;
}
*/