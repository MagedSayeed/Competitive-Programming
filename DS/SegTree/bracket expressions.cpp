// from L to R check if this sub-string is correct bracket expressions => update flip the braked status

array<int, 2> seg[4 * N];
int n;
string s;
#define md lx + (rx-lx)/2

array<int, 2> merge(array<int, 2> lf, array<int, 2> rt) {
    array<int, 2> ret = {0, 0};
    if (lf[0] >= rt[1]) {
        ret = {
                rt[0] + lf[0] - rt[1],
                lf[1]
        };
    } else {
        ret = {
                rt[0],
                lf[1] + rt[1] - lf[0]
        };
    }
    return ret;
}

void build(int x = 0, int lx = 0, int rx = n - 1) {
    if (lx == rx) {
        if (lx < n)
            seg[x] = {s[lx] == '(', s[lx] == ')'};
        return;
    }
    build(2 * x + 1, lx, md);
    build(2 * x + 2, md + 1, rx);
    seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
}

void update(int i, int x = 0, int lx = 0, int rx = n - 1) {
    if (lx == rx) {
        seg[x] = {!seg[x][0], !seg[x][1]};
        return;
    }
    if (i <= md)
        update(i, 2 * x + 1, lx, md);
    else
        update(i, 2 * x + 2, md + 1, rx);
    seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);

}

array<int, 2> query(int l, int r, int x = 0, int lx = 0, int rx = n - 1) {
    if (r < lx || rx < l) return {0, 0};
    if (l <= lx && rx <= r)return seg[x];
    return merge(
            query(l, r, 2 * x + 1, lx, md),
            query(l, r, 2 * x + 2, md + 1, rx)
    );
}
