/*
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>
#define maxn 200005
using namespace std;
map <int, int > a[maxn];
int n;
string b[maxn];
int  num = 0;
int main()
{
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string in1, in2;
		cin >> in1 >> in2;
		int x = in1[0] * 26 + in1[1],y=in2[0]*26+in2[1];
		if (x != y) { ans += a[y][x]; a[x][y]++;}
	}
	cout << ans << endl;
	return 0;
}
*/