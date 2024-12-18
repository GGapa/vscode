#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 2000 + 5;

char a[maxn][maxn];
int n;
int f1[maxn][maxn], f2[maxn][maxn];
unsigned long long ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            f2[i][j] = f2[i][j-1] + (a[i][j] == 'o');
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            f1[i][j] = f1[i-1][j] + (a[i][j] == 'o');
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            f1[i][j] += (f1[i][j] == 0) ? 0 : -1;
            f2[i][j] += (f2[i][j] == 0) ? 0 : -1;
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            if(a[i][j] == 'x') continue;
            ans += (f1[i][j] - f1[1][j]) * (f2[i][j] - f2[i][1]); //上左
            ans += (f1[n][j] - f1[i][j]) * (f2[i][j] - f2[i][1]); //下左
            ans += (f1[i][j] - f1[1][j]) * (f2[i][n] - f2[i][j]); //上右
            ans += (f1[n][j] - f1[i][j]) * (f2[i][n] - f2[i][j]); //下右
        }
    cout << ans;
    return 0;
}