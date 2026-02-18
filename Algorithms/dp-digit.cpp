/// given range from L to R count some thing
int solve(int i, bool isEqL, bool isEqR) {
    if (i == L.size()) {
        return 0;
    }
    int &ret = dp[i][isEqL][isEqR];
    if (vis[i][isEqL][isEqR] == vid) {
        return ret;
    }
    vis[i][isEqL][isEqR] = vid;
    ret = 1e9;
    int l = isEqL ? L[i] : 0,
            r = isEqR ? R[i] : 9;
    for (int d = l; d <= r; ++d) {
        int v = (d == L[i]) + (d == R[i]);
        ret = min(ret, solve(i + 1, isEqL && (d == L[i]), isEqR && (d == R[i])) + v);
    }
    return ret;
}
 
