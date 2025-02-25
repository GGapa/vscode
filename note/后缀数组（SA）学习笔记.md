鲜花：我不信这辈子我学不懂 SA。学了三次 SA 了，每学一次都有新的发现，完全不知道我之前在学什么。

---

### 定义

$sa(i)$ 代表字符串 $s$ 字典序排名为 $i$ 的后缀的起始位置。

$rk(i)$ 起始位置为 $i$ 的后缀在所有后缀中字典序的排名。

二者满足 $sa(rk(i)) = rk(sa(i)) = i$。

$height(i)$ 为排名为 $i$ 和 $i - 1$ 的后缀的最长公共前缀长度。

### 后缀排序

后缀排序需要用到倍增的思想。

假设我们知道了每个后缀只考虑前 $len$ 个字符的排名，那么可以推出只考虑前 $2len$ 个字符的排名，因此我们可以在 $O(\log n)$ 的时间完成后缀排序。

现可以使用 `std::sort` 实现 $O(n \log^2 n)$ 的后缀排序，具体地，在每次排序时对于后缀起始位置为 $i$ 的后缀，我们只需要建立一个二元组 $(rk_i, rk_{i + len})$，如果 $rk_{i} > n$ 则记 $rk_{i} = 0$，对这 $n$ 个二元组进行排序之后，后缀起始位置为 $i$ 的后缀构成的二元组在这 $n$ 个二元组中的排名便是新 $rk(i)$，注意如果两个二元组相同那么对应的 $rk$ 也应当相同。如果 $rk$ 是一个排列则说明后缀排序已经完成。

```cpp
string s; cin >> s; 
int n = s.size(); s = " " + s;
vector<int> rk(n + 1, 1), sa(n + 1);
iota(sa.begin(), sa.end(), 0);
vector<AI> A(n + 1);
rep(i, 1, n) A[i][0] = s[i];

for(int len = 1, cnt = 0; ; len <<= 1, cnt = 0) {
    sort(sa.begin() + 1, sa.end(), [&](const int x, const int y) {
        return (A[x] != A[y] ? A[x] < A[y] : x < y);
    });
    rep(i, 1, n) {
        if(A[sa[i]] == A[sa[i - 1]]) rk[sa[i]] = rk[sa[i - 1]];
        else rk[sa[i]] = ++cnt;
    }
    if(cnt == n) break;
    rep(i, 1, n) {
        A[i][0] = rk[i];
        A[i][1] = (i + len <= n ? rk[i + len] : 0);
    }
}

rep(i, 1, n) cout << sa[i] << " \n"[i == n];
```
如果要优化成 $O(n \log n)$ 需要用到计数排序和基数排序，就是先对第二关键字进行桶排，再对第一关键字进行桶排。因为常数十分巨大，甚至比不过 $O(n \log^2 n)$，考虑常数优化：

- 修改排序时桶的大小；
- 去掉第二关键字排序:
  若 $i + len > n$ 则 $rk_{i + len} = 0$ 这在第一次桶排的时候会排到最前面，所以我们先把满足条件的二元组放到最前面。

  而对于 $1 \sim n - len + 1$ 的位置，在第一次排序时会按照 $rk_{i + len}$ 递增出现，也就是在 $sa$ 中按照下标从小到大的顺序出现，考虑按下标从小到大枚举 $sa_i$，若 $sa_i > w$ 则加入 $sa_i - w$。第一次排序后的排列就等于所有大于 $w$ 的 $sa_i$ 减去 $w$ 后按照下标从小到大的排列。至此我们用常数较小的一次循环完成了第一次排序，也就是以 $sa_{i + len}$ 为第二关键字的排序。

```cpp
string s; 
int sa[N], rk[N], ork[N], buc[N], id[N], n;
void work() {
	int m = 1 << 7, p = 0;
	rep(i, 1, n) buc[rk[i] = s[i]]++;
	rep(i, 1, m) buc[i] += buc[i - 1];
	per(i, n, 1) sa[buc[rk[i]]--] = i;
	for(int w = 1 ; ; m = p, p = 0, w <<= 1) {
		rep(i, n - w + 1, n) id[++p] = i;
		rep(i ,1, n) if(sa[i] > w) id[++p] = sa[i] - w;
		memset(buc, 0, m + 1 << 2);
		memcpy(ork, rk, n + 1 << 2) ;
		p = 0;
		rep(i, 1, n) buc[rk[i]]++;
		rep(i, 1, m) buc[i] += buc[i - 1];
		per(i, n, 1) sa[buc[rk[id[i]]]--] = id[i];
		rep(i ,1, n) rk[sa[i]] = ork[sa[i - 1]] == ork[sa[i]] && ork[sa[i - 1] + w] == ork[sa[i] + w] ? p : ++p;
		if(p == n) return ;
	}
}
```

### Height 数组

**引理**：$height(rk(i)) \ge height(rk(i - 1)) - 1$。

由这个引理可以写出来代码：

```cpp
s += " ";
vector<int> ht(n + 1);
for(int i = 1, k = 0; i <= n; i++) {
    if(k) k--;
    while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;    // 这里需要保证 s[0] 和 s[n + 1] 为空，多测的时候需要注意！
    ht[rk[i]] = k;
}
```

$height$ 能够用来求任意两个后缀的 $lcp$ 也就是 $lcp(i, j)$，简单地说，后缀 $i$ 和后缀 $j$，的后缀长度就是二者排名之间的 $height$ 数组最小值。

感性理解便是在 $rk(i) + 1$ 到 $rk(j)$ 中所有的后缀都需要满足 $lcp(i, j)$ 相同，相当于我们需要寻找到 $i - 1$ 和 $i$ 最小的 $lcp$ 也就是限制最严的一个，故维护区间最小值即可。（感觉和求 $lca(u, v)$ 的深度的 trick 有点像，不知道有没有本质关系。）

### 参考资料

对定义讲的非常浅显易懂：[Demeanor_Roy 的专栏](https://www.luogu.com/article/d2w066pt)。

对算法流程讲的非常浅显易懂：[扶苏的博客](https://www.cnblogs.com/yifusuyi/p/11739881.html)。

良好的代码实现和证明：[Alex_Wei 的博客](https://www.cnblogs.com/alex-wei/p/Basic_String_Theory.html)。
