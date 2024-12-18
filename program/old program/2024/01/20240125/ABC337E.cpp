#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int speo = __lg(n) + 1;
    if(n == (1 << speo - 1)) speo--;
    cout << speo << endl;
    for(int i = 0; i < speo; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++)  {
            if(j & (1 << i)) sum++;
        }
        cout << sum << " ";
        for(int j = 1; j <= n; j++) {
            if(j & (1 << i)) cout << j << " ";
        }
        cout << endl;
    }
    string s; int ans = 0;
    cin >> s;
	for(int i = 0; i < speo; i++)
		ans |= (1 << i) * (s[i] - '0');
	if(!ans) ans = n;
	cout << ans << endl;
 
    return 0;
}