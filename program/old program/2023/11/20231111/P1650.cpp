//P1650 ÃÔº…»¸¬Ì
//https://www.luogu.com.cn/problem/P1650
//2023-11-11
#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 5;

int n;
int a[maxn], b[maxn];
int al, ar, bl, br, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	ar = br = n; al = bl = 1;
	while(al <= ar && bl <= br) {
		if(a[ar] < b[br]) {
			ar--;
			br--;
			ans++;
		}
		else if(a[ar] > b[br]) {
			ans--;
			ar--; 
			bl++;
		}
		else {
			if(a[al] < b[bl]) {
				al++; bl++;
				ans++;	
			}
			else{
				if(b[bl] < a[ar]) ans--;
				bl++, ar--;	
			}
		}
	}
	cout << ans * 200 << endl;
	return 0;
}
