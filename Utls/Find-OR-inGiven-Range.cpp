const int N = 32;
const int M = 1e5 + 500;
const ll MOD = 1e9 + 7;
int pre[N][M];
 
void calc(vector<int> &a) {
    for (int i = 0; i < 32; i++) {
        pre[i][0] = ((a[0] >> i) & 1);
        for (int j = 1; j < n; j++) {
            pre[i][j] = ((a[j] >> i) & 1);
            pre[i][j] += pre[i][j - 1];
        }
    }
}
 
 
int query(int l, int r) {
 
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int x;
        if (l == 0) {
            x = pre[i][r];
        } else {
            x = pre[i][r] - pre[i][l - 1];
        }
        if (x != 0) {
            ans = (ans | (1 << i));
        }
    }
    return ans;
}
