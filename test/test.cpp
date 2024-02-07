// USACO 2016 Open B. Diamond Collector
#include <bits/stdc++.h>
using namespace std;
int main() {
 ios::sync_with_stdio(false), cin.tie(0);
 int n, k;
 cin >> n >> k; // 钻石的数量 n 和最大尺寸差 k
 vector<int> A(n);
 for (int &a : A) cin >> a;
 sort(A.begin(), A.end()); // 对钻石尺寸进行排序
 int ans = 0; // 初始化最大展示钻石数量为 0
 for (int i = 0; i < n; ++i) // 遍历每个钻石
 for (int j = i + 1, cnt = 1; j < n && A[j] - A[i] <= k;
 ++j) { // 从当前钻石的下一个位置开始，遍历后续的钻石
 ans = max(ans, ++cnt); // 更新最大展示钻石数量为当前数量 cnt 的最大值
 }
 cout << ans;
 return 0;
}