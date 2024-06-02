#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;


#define int long long

void solve() {
    int n, k; cin >> n >> k;
    vector<array<ll, 2>> a(n + 1);
    vector<ll> c(n + 1);
    rep(i, 1, n) cin >> a[i][1];
    rep(i, 1, n) cin >> a[i][0], a[i][0] = abs(a[i][0]);
    sort(a.begin() + 1, a.end());
    ll sum = 0; bool tag = true;
    rep(i, 1, n) {
        sum += a[i][1];
        if(1ll * k * a[i][0] < sum) tag = false;
    }
    cout << (tag ? "YES" : "NO") << '\n';
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
你正在玩一款电脑游戏。当前游戏的关卡可以被建模成一条直线。你的角色位于坐标轴的原点 0 处。有 n 只怪物试图杀死你的角色；第 i 只怪物的初始健康值为 ai，初始位置为 xi。

每秒钟发生以下事件：

首先，你向怪物发射最多 k 颗子弹。每颗子弹只瞄准一只怪物，并使其健康值减少 1。对于每颗子弹，你可以任意选择目标（例如，你可以将所有子弹射向一只怪物，将所有子弹分别射向不同的怪物，或选择其他任何组合）。任何怪物都可以成为子弹的目标，不考虑其位置和其他因素；
然后，所有健康值为 0 或更低的存活怪物死亡；
接着，所有存活怪物向你靠拢 1 个坐标点（位于你左侧的怪物的坐标加 1，位于你右侧的怪物的坐标减 1）。如果任何怪物到达你的角色（移动到坐标轴原点 0 处），你就输了。

你能在任何怪物到达你的角色之前生存并消灭所有 n 只怪物吗？

输入
输入的第一行包含一个整数 t（1≤t≤3⋅104）— 测试用例的数量。

每个测试用例包括三行：

第一行包含两个整数 n 和 k（1≤n≤3⋅105；1≤k≤2⋅109）；
第二行包含 n 个整数 a1,a2,…,an（1≤ai≤109）；
第三行包含 n 个整数 x1,x2,…,xn（−n≤x1<x2<x3<⋯<xn≤n；xi≠0）。

输入的附加约束：所有测试用例中 n 的总和不超过 3⋅105。

输出
对于每个测试用例，如果你能在怪物到达你的角色之前杀死所有 n 只怪物，则输出YES，否则输出NO。

你可以以任何大小写形式输出答案中的每个字母（大写或小写）。例如，字符串 yEs、yes、Yes 和 YES 都将被识别为肯定的回答。






*/