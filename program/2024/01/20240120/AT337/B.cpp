#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
typedef long long ll;
using namespace std;

string a;
char nxt;
map<char, char> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	mp['A'] = 'B';
	mp['B'] = 'C';
	mp['C'] = 'D';
	cin >> a;
	a.insert(0, " ");
	rep(i, 1, a.length() - 2) {
		if(a[i] > a[i + 1]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
	
	return 0;	
}

