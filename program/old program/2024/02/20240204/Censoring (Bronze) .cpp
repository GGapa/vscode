// USACO 2015 Feb B. Censoring (Bronze)
#include <bits/stdc++.h>
using namespace std;
int main() {
 ios::sync_with_stdio(false), cin.tie(0);
 string S, T, R;
 cin >> S >> T;
 for (char c : S) {
 R += c;
 int d = R.size() - T.size();
 if (d >= 0 && R.substr(d) == T) R.resize(d);
 }
 cout << R << "\n";
 return 0;
}
