//Blocked Billboard II 
#include <bits/stdc++.h>
using namespace std;

bool covered(int x, int y, int x1, int y1, int x2, int y2) {
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

int main() {
     int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4; // cc: A:4 个角有几个被覆盖了?
    int cc = covered(x1, y1, x3, y3, x4, y4) + covered(x1, y2, x3, y3, x4, y4) +
    covered(x2, y1, x3, y3, x4, y4) + covered(x2, y2, x3, y3, x4, y4);
    int ans = -1;
    if (cc < 2) // <2 个角被盖上，整个矩形 A 都要 C 覆盖
        ans = (x2 - x1) * (y2 - y1);
    else if (cc == 4) // 4 个角都被覆盖了，不用管了
        ans = 0;
    else {
        int xl = max(x1, x3), xr = min(x2, x4), yl = max(y1, y3), yr = min(y2, y4);
        ans = (x2 - x1) * (y2 - y1) - (xr - xl) * (yr - yl); // 把相交部分减掉剩下部分需要 C 覆盖
    }
    printf("%d\n", ans);
}