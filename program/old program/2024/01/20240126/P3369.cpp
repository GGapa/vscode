#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#define int long long
const int MXN = 1000019;
const int INF = 1e9;

int na;
int ch[MXN][2];
int val[MXN], dat[MXN];
int size[MXN], cnt[MXN];
int tot, root;

int New(int v) {
    val[++tot] = v;
    dat[tot] = rand();
    size[tot] = 1;
    cnt[tot] = 1;
    return tot;
}

void pushup(int id) {
    size[id] = size[ch[id][0]] + size[ch[id][1]] + cnt[id];
}

void build() {
    root = New(-INF), ch[root][1] = New(INF);
    pushup(root);
}

void Rotate(int &id, int d) {
    int temp = ch[id][d ^ 1];
    ch[id][d ^ 1] = ch[temp][d];
    ch[temp][d] = id;
    id = temp;
    pushup(ch[id][d]), pushup(id);
}

void insert(int &id, int v) {
    if (!id) {
        id = New(v);
        return;
    }
    if (v == val[id]) {
        cnt[id]++;
    } else {
        int dir = (v < val[id]) ? 0 : 1;
        insert(ch[id][dir], v);
        if (dat[id] < dat[ch[id][dir]]) {
            Rotate(id, dir ^ 1);
        }
    }
    pushup(id);
}

void Remove(int &id, int v) {
    if (!id) return;
    if (v == val[id]) {
        if (cnt[id] > 1) {
            cnt[id]--;
            pushup(id);
            return;
        }
        if (ch[id][0] || ch[id][1]) {
            if (!ch[id][1] || dat[ch[id][0]] > dat[ch[id][1]]) {
                Rotate(id, 1), Remove(ch[id][1], v);
            } else {
                Rotate(id, 0), Remove(ch[id][0], v);
            }
            pushup(id);
        } else {
            id = 0;
        }
        return;
    }
    (v < val[id]) ? Remove(ch[id][0], v) : Remove(ch[id][1], v);
    pushup(id);
}

int get_rank(int id, int v) {
    if (!id) return 0;
    if (v == val[id]) return size[ch[id][0]] + 1;
    else if (v < val[id]) return get_rank(ch[id][0], v) ;
    else return size[ch[id][0]] + cnt[id] + get_rank(ch[id][1], v);
}

int get_val(int id, int rank) {
    if (!id) return INF;
    if (rank <= size[ch[id][0]]) return get_val(ch[id][0], rank);
    else if (rank <= size[ch[id][0]] + cnt[id]) return val[id];
    else return get_val(ch[id][1], rank - size[ch[id][0]] - cnt[id]);
}

int get_pre(int v) {
    int id = root, pre;

    while (id) {
        if (val[id] < v) pre = val[id], id = ch[id][1];
        else id = ch[id][0];
    }
    return pre;
}

int get_next(int v) {
    int id = root, next;
    while (id) {
        if (val[id] > v) next = val[id], id = ch[id][0];
        else id = ch[id][1];
    }
    return next;
}

signed main() {
    build();
    cin >> na;
    for (int i = 1; i <= na; i++) {
        int cmd, x;
        cin >> cmd >> x;
        if (cmd == 1) insert(root, x);
        else if (cmd == 2) Remove(root, x);
        else if (cmd == 3) cout << get_rank(root, x) - 1 << '\n';
        else if (cmd == 4) cout << get_val(root, x + 1) << '\n';
        else if (cmd == 5) cout << get_pre(x) << '\n';
        else if (cmd == 6) cout << get_next(x) << '\n';
    }
    return 0;
}

