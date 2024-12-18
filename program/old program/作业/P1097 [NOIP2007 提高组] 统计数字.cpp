/*
#include <iostream>
#include <map>
#include <set>
using namespace std;
map<long long, long long> a;
set <long long>b;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		a[input]++;
		b.insert(input);
	}
	for (set<long long>::iterator i = b.begin(); i != b.end(); i++)
		cout << *i << " " << a[*i] << endl;
	return 0;
}
*/