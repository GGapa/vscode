/*
author:ggapa
*/
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;

int n, m;
string a;
int c[30][maxn];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int y, int ch) {
    while(x <= n) {
        c[ch][x] += y;
        x += lowbit(x);
    }
}

int ask(int x, char ch) {
    int y = 0;
    while(x != 0) {
        y += c[ch][x];
        x -= lowbit(x);
    }
    return y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> a;
    a.insert(0, " ");
    for(int i = 1; i <= n; i++) {
        add(i, 1, a[i] - 'a');
    }
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y;
            cin >> x >> y;
            int sum = 0;
            for(char i = 'a'; i <= 'z'; i++) {
                if((ask(y, i - 'a') - ask(x - 1, i - 'a')) % 2 == 1) sum++;
            }
            cout << sum << endl;
        }
        if(op == 2) { 
            int x;
            char y;
            cin >> x >> y;
            add(x, -1, a[x] - 'a');
            add(x, 1, y - 'a');
            a[x] = y;
        }
    }
}