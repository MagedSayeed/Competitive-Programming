typedef vector<int> row;
typedef vector<row> matrix;
 
int add(int a, int b) {
    return (a % mod + b % mod + mod) % mod;
}
 
int mul(int a, int b) {
    return ((a % mod) * (b % mod)) % mod;
}
 
matrix operator*(const matrix &a, const matrix &b) {
    matrix ret = matrix(a.size(), row(b[0].size()));
    int r1 = a.size(), r2 = b.size(), c2 = b[0].size();
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < r2; k++)
                ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
    return ret;
}
 
matrix operator^(const matrix &a, int k) {
    matrix ret = matrix(a.size(), row(a[0].size()));
    for (int i = 0; i < a.size(); ++i) {
        ret[i][i] = 1;
    }
    for (matrix tmp = a; k; tmp = tmp * tmp, k /= 2) {
        if (k & 1)ret = ret * tmp;
    }
    return ret;
}
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    matrix T(n, row(n, 0));
    while (m--) {
        int a, b;
        cin >> a >> b;
        T[--a][--b]++;
    }
    T = T ^ k;
    cout << T[0][n - 1];
 
 
}
