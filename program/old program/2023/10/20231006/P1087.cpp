/*
P1087 [NOIP2004 普及组] FBI 树
https://www.luogu.com.cn/problem/P1087
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

void dfs(string x) {
    if(x.length() > 1) {
        int mid = x.length() / 2;
        string x1 = x.substr(0, mid);
        string x2 = x.substr(mid, mid);
        dfs(x1);
        dfs(x2);
    }
    bool B, I;
    B = I = true;
    for(char i : x) {
        if(i != '0') B = false;
        if(i != '1') I = false;
    }
    if(B == false && I == false) cout << "F";
    else if(B) cout << "B";
    else cout << "I";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    n = 1 << n;
    string s;
    cin >> s;
    dfs(s);
}

/*
2023-10-06 22:33:04
编程语言
C++14 (GCC 9)
代码长度
771B
用时
32ms
内存
852.00KB
*/