using LL = long long;
using VI = vector<int>;
const LL p = 1e10;
 
struct LINT {
    vector<LL> A; 
    int n;
    LINT() : A(1) {}
    LINT(LL x) : A(1) {
        for(; x; x /= p) A.push_back(x % p);
        n = (int)A.size() - 1; 
    }
    LINT operator+(LINT B) {
        LINT tmp; tmp.n = max(B.n, n);
        tmp.A.resize(tmp.n + 1);
        rep(i, 1, tmp.n) {
            if(i <= n) tmp.A[i] += A[i];
            if(i <= B.n) tmp.A[i] += B.A[i];
            if(tmp.A[i] >= p && i + 1 > tmp.n) tmp.A.push_back(tmp.A[i] / p), tmp.n++;
            else tmp.A[i + 1] += tmp.A[i] / p;
            tmp.A[i] %= p;
        }
        return tmp;
    } 
    LINT operator*(int x) {
        LINT tmp; tmp.n = n; tmp.A = A;
        rep(i, 1, tmp.n) tmp.A[i] *= x;
        rep(i, 1, tmp.n - 1) tmp.A[i + 1] += tmp.A[i] / p, tmp.A[i] %= p;
        for(; tmp.A[tmp.n] >= p; ) tmp.A.push_back(tmp.A[tmp.n] / p), tmp.A[tmp.n] %= p, tmp.n++;
        return tmp;
    }
    void print() {
        cout << A[n];
        per(i, n - 1, 1) {
            int c = 10;
            while(c < p && A[i] * c < p) cout << 0, c *= 10;
            cout << A[i];
        }
        cout << '\n';
    } 
};