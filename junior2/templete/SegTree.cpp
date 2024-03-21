struct SegTree {
#define LF (x*2+1)
#define RT (x*2+2)
#define md ((lx+rx) >> 1)
  vector<int> seg;
  vector<int> lazy;
  int sz;

  SegTree(int n) {
    sz = n;
    ignoreValue = LLONG_MAX / 2; /// update this
    seg.assign(4 * n, {});
    lazy.assign(4 * n, {});
  }

  int merge(const int &lf, const int &rt) {
    return min(lf, rt); /// update this
  }
  void update(int l, int r, int v, int x = 0, int lx = 0, int rx = -1) {
    if (r < lx or rx < l) {
      return;
    }
    update(l, r, v, LF, lx, md);
    update(l, r, v, RT, md + 1, rx);
    seg[x] = merge(seg[LF], seg[RT]);
  }

  int query(int l, int r, int x = 0, int lx = 0, int rx = -1) {
    if (l <= lx and rx <= r) {
      return seg[x];
    }
    if (r < lx or rx < l) {
      return ignoreValue;
    }
    return merge(
        query(l, r, LF, lx, md),
        query(l, r, RT, md + 1, rx)
    );
  }

#undef md
#undef LF
#undef RT
};
