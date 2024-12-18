#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m), ca(k + 1), cb(k + 1);
    for(auto & i : a) cin >> i;
    for(auto & i : b) cin >> i;
    for(auto i : a) if(i <= k) ca[i]++;
    for(auto i : b) if(i <= k) cb[i]++;
    int cnta = 0, cntb = 0;
    rep(i, 1, k) {
        if(ca[i] == 0  && cb[i] == 0) {
            cout << "NO\n";
            return ; 
        }
        cnta += max((ca[i] != 0) - (cb[i] != 0), 0);
        cntb += max((cb[i] != 0) - (ca[i] != 0), 0);
    }
    if(cnta > k / 2 || cntb > k / 2) {
        cout << "NO\n";
        return ; 
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

/*
给定一个包含 n 个整数的数组 a，一个包含 m 个整数的数组 b，以及一个偶数 k。
你的任务是确定是否可以从两个数组中选择恰好 k^2 个元素，使得在选择的元素中，包含从 1 到 k 的每个整数。
例如：
如果 a=[2,3,8,5,6,5]，b=[1,3,4,10,5]，k=6，那么可以从数组 a 中选择值为 2、3、6 的元素，从数组 b 中选择值为 1、4、5 的元素。在这种情况下，从 1 到 k=6 的所有数字都包含在所选元素中。
如果 a=[2,3,4,5,6,5]，b=[1,3,8,10,3]，k=6，则无法按照要求选择元素。
注意，你不需要找到选择元素的方法 —— 你的程序只需检查是否可以以所需方式选择元素。
输入
第一行输入一个整数 t（1≤t≤104） —— 测试用例数。接下来是每个测试用例的描述。

每个测试用例的第一行包含三个整数 n、m 和 k（1≤n,m≤2⋅105，2≤k≤2⋅min(n,m)，k 为偶数） —— 数组 a 的长度，数组 b 的长度以及要选择的元素数量。

每个测试用例的第二行包含 n 个整数 a1,a2,…,an（1≤ai≤106） —— 数组 a 的元素。

每个测试用例的第三行包含 m 个整数 b1,b2,…,bm（1≤bj≤106） —— 数组 b 的元素。

保证在一个测试中，n 和 m 的值的总和不会超过 4⋅105。

输出
输出 t 行，每行为相应测试用例的答案。作为答案，如果可以选择 k^2 个元素，使得在选择的元素中包含从 1 到 k 的每个整数，则输出 "YES"。否则，输出 "NO"。

你可以以任何大小写形式输出每个字母，例如字符串 "yEs"、"yes"、"Yes" 和 "YES" 都将被接受为肯定答案。
*/