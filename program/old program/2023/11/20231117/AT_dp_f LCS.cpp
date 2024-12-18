/**
 * @Problem      : AT_dp_f LCS
 * @URL          : https://www.luogu.com.cn/problem/AT_dp_f
 * @Author       : GGapa
 * @Date         : 2023-11-17 17:28:15
 * @LastEditTime : 2023-11-17 17:51:18
**/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[3005][3005];
char s1[100010], s2[100010], ans[1000010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freoepn("akioi.out", 'w', stdout);
    cin >> (s1 + 1) >> (s2 + 1);
	int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
	for(int i = 1; i <= len1; i++)
		for(int j = 1; j <= len2; j++)
			f[i][j] = max({f[i - 1][j], f[i][j - 1], (s1[i] == s2[j] ? f[i - 1][j - 1] + 1 : 0)});
	int i = len1, j = len2;
	while(f[i][j] > 0) {
		if(s1[i] == s2[j]) {
            ans[f[i][j]] = s1[i];
            i--, j--;
        }
		else {
			if(f[i][j] == f[i - 1][j]) i--;
			else j--;
		}
	}
	cout << (ans + 1);
    return 0;
}
// AC 100