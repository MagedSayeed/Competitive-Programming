matrix operator*(const matrix &a, const matrix &b) {
    matrix ret = matrix(a.size(), row(b[0].size(), inf));
    int r1 = a.size(), r2 = b.size(), c2 = b[0].size();
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < r2; k++)
                ret[i][j] = min(ret[i][j], (add(a[i][k], b[k][j])));
    return ret;
}
 
matrix operator^(const matrix &a, int k) {
    matrix ret = matrix(a.size(), row(a[0].size()));
    bool x = 1;
    for (matrix tmp = a; k; tmp = tmp * tmp, k /= 2) {
        if (k & 1) {
            if (x)ret = tmp, x = 0;
            else
                ret = ret * tmp;
        }
    }
    return ret;
}
 
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    matrix T(n, row(n, inf));
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        T[a][b] = min(c, T[a][b]);
    }
    T = T ^ k;
    if (T[0][n - 1] >= inf)T[0][n - 1] = -1;
    cout << T[0][n - 1];
 
 
}
