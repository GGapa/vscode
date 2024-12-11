/*
P4824 [USACO15FEB] Censoring S
https://www.luogu.com.cn/problem/P4824
*/
#include <iostream>
using namespace std;
const int maxn = 1e6 + 5;

string a, b;
int na[maxn], nb[maxn]; //KMP 中的next
int st[maxn]; //模拟stack
int top = 0; //栈顶

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    a.insert(0, " "); b.insert(0, " ");
    int lena = a.length() - 1, lenb = b.length() - 1;
    for(int i = 2, j = 0; i < lenb; i++) { //b 和 b 自己进行判断
        while(j && b[i] != b[j + 1]) j = nb[j];
        if(b[i] == b[j + 1]) j++;
        nb[i] = j;
    }
    for(int i = 1, j = 0; i <= lena; i++) { // B compare A
        while(j && a[i] != b[j + 1]) j = nb[j];
        if(a[i] == b[j + 1]) j++;
        na[i] = j;
        st[++top] = i;
        if(j == lenb) //成功了awa
            top -= lenb, 
            j = na[st[top]];
    }
    for(int i = 1; i <= top; i++) 
        cout << a[st[i]];
    return 0;
}

/*
2023-10-04 16:30:45编程语言
C++14 (GCC 9)
代码长度
978B
用时
354ms
内存
13.87MB
*/