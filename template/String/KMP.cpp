#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 5;
 
char a[maxn], b[maxn];
int nxt[maxn];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freoepn("akioi.out", "w", stdout);
    cin >> (a + 1) >> (b + 1);
    int len1 = strlen(a + 1), len2 = strlen(b + 1 );
    for(int i = 2, j = 0; i <= len2; i++) {
        for(; j && b[i] != b[j + 1]; j = nxt[j]);
        j += (b[i] == b[j + 1]);
        nxt[i] = j;
    }
    for(int i = 1, j = 0; i <= len1; i++) {
        for(; j && a[i] != b[j + 1]; j = nxt[j]);
        j += (a[i] == b[j + 1]);
        if(j == len2) {
            cout << i - len2 + 1 << &#039;n&#039;;
            j = nxt[j];
        }
    }
    for(int i = 1; i <= len2; i++) 
        cout << nxt[i] << " n"[i == len2];
    return 0;
}