/*
T367649 Lights
https://www.luogu.com.cn/problem/T367649?contestId=126183
*/

#include <iostream>
using namespace std;
const int maxn =  50;

int  n;
int a[maxn];

int it = 1;
void init() {
    char c;
    c = getchar();
    while(!isdigit(c)) {
        c = getchar();
    }
    while(isdigit(c)) {
        a[it++] = c - '0';
        c = getchar();
    }
    if(it == 2) {
        cout << 0 << endl;
        exit(0);
    }
    it--;
}
unsigned long long ans = 0;
void dfs() {
    bool bj = true;
    while(bj){
    bj = false;
    for(int i = 1; i <= it / 2; i++) {
        if(a[i] != a[it - i + 1]) {
            bj = true;
            break;
        }
    }
    if(!bj) {
        cout << ans << endl;
        exit(0);
    }
    a[it]++;
    ans++;
    for(int i = it; i >= 1;i --) {
        if(a[i] == 10) {
            a[i - 1] ++;
            a[i] = 0;
        }
    }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    dfs();
    cout << ans << endl;
    return 0;
}