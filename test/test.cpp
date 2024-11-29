#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct Node {
	int mn, pos, mnpos;
	Node(const int a = 0, const int b = 0, const int c = 0) {mn = a, pos = b, mnpos = c; }
	bool operator<(const Node &x) const {return mn > x.mn || (mn == x.mn && pos > x.pos); }
	bool operator>(const Node &x) const {return x < *this; }
	bool operator==(const Node &x) const {return mn == x.mn && pos == x.pos && mnpos == x.mnpos; }
};

priority_queue<Node> q;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	q.emplace(Node(0, 1));
	q.emplace(Node(1, 1));
	q.emplace(Node(1, 2));
	q.top();
	return 0;
}
