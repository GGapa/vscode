/*
P5057 [CQOI2006] 简单题
https://www.luogu.com.cn/problem/P5057
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int c[maxn];
int n, m;

int lowbit(int x) {
    return x & -x;
}

int ask(int x) { //询问
    int ans = 0; //没赋初值挂了
    while(x) {
        ans ^= c[x];
        x -= lowbit(x);
    }
    return ans;
}

void add(int x) {  //增加
    while(x <= n) {
        c[x] ^= 1;
        x += lowbit(x);
    }
}

int main() {
    cin >> n >> m;
    while(m--) {
        int op, l, r;
        cin >> op;
        if(op == 1) {
            cin >> l >> r;
            add(l);
            add(r + 1);
        }
        else {
            cin >> l;
            cout << ask(l) << endl;
        }
    }
    return 0;
     
}