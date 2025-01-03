struct Mat {
    static constexpr int n = 100; 
    LL A[n + 1][n + 1];
 
    LL* operator [](int i)  {return A[i];} 
    const LL* operator [](int i) const { return A[i]; } //在矩阵乘法中放入这两个函数之后，便可以直接通过 `ans[1][5]` 访问数组元素，而不是 `ans.a[1][5]`。

    Mat(int num = 0) {
        memset(A, 0, sizeof(A)); 
        rep(i, 0, n) A[i][i] = num;
    }
    const Mat operator*(const Mat &B) const {
        Mat C;
        rep(i, 0, n) rep(j, 0, n) 
            rep(k, 0, n) (C[i][j] += (A[i][k] * B[k][j]) % mod) %= mod;
        return C;
    }
};