/*
#include <iostream>
#include <map>
#include <string>
using namespace std;
;
string a, b;
void dfs(string x, string y)
{
	if (x.length() == 0)
		return;
	char father = y[y.length() - 1];
	cout << father;
	int it = x.find(father);
	dfs(x.substr(0, it), y.substr(0, it));
	dfs(x.substr(it + 1, x.length() - 1 - it), y.substr(it, y.length() - 1 - it));
}
int main()
{
	cin >> a >> b;
	dfs(a, b);
	cout << endl;
	return 0;
}

*/