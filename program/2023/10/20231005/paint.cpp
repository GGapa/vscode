/*
paint
*/
#include <iostream>
using namespace std;

string s;
int f[60][60];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    s.insert(0, " ");
    int n  = s.length() - 1;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) f[i][j] = 2e9;
    for(int i = 1; i <= n; i++) f[i][i] = 1;
    for(int l = 1; l <= n; l++) {
        for(int i = 1, j = l + 1; j <= n; j++, i++) {
            if(s[i] == s[j])
                f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            else for(int k = i; k < j; k++) 
                f[i][j]=min(f[i][j], f[i][k] + f[k + 1][j]);
        }
    }
    cout << f[1][n] << endl;
    return 0;
}