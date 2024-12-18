#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    rep(i, 1, 26) rep(j, 1, 26) rep(k, 1, 26) if(i + j + k == n) {
        cout << char(i + 'a' - 1) << char(j + 'a' - 1) << char(k + 'a' - 1) << '\n';
        return ;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

/*

A. 恢复一个小字符串

时间限制：1秒
内存限制：256兆字节
输入：标准输入
输出：标准输出

尼基塔有一个由恰好3个小写拉丁字母组成的单词。拉丁字母表中的字母编号从1到26，其中字母"a"的索引是1，字母"z"的索引是26。

他将这个单词编码为字母表中所有字符位置的总和。例如，单词"cat"的编码是3+1+20=24，因为字母"c"在字母表中的索引是3，字母"a"的索引是1，字母"t"的索引是20。

然而，这种编码方式被发现是有歧义的！例如，编码单词"ava"时，也得到整数1+22+1=24。

确定可能已经被编码的3个字母单词中，按字典顺序最小的是什么。

如果字符串a按字典顺序小于字符串b，则满足以下条件之一：

a是b的前缀，但a≠b；
在a和b不同的第一个位置，字符串a有一个字母在字母表中出现在字符串b的对应字母之前。
输入
输入的第一行包含一个整数t（1≤t≤100）——测试用例的数量。

然后是每个测试用例的描述。

每个测试用例的第一行是一个整数n（3≤n≤78）——编码过的单词。

输出
对于每个测试用例，输出可能已被编码的字母表中最小的三个字母单词，每行一个。
*/