//// it give u maximaum subArray in full array if u want to find res in range u can make a  Query function . 
struct SegTree {
private:
    struct node {
        int sum, maxSeg, suf, pref;

        node() : sum(0), maxSeg(0), suf(0), pref(0) {}

        node(int v) : sum(v), maxSeg(max(v, 0LL)), suf(max(v, 0LL)), pref(max(v, 0LL)) {}

    };

    vector<node> seg;
    int sz;

    node opt(node lft, node rt) {
        node res;
        res.sum = lft.sum + rt.sum;
        res.maxSeg = max({
                                 lft.maxSeg,
                                 rt.maxSeg,
                                 lft.suf + rt.pref
                         });
        res.suf = max(
                rt.suf,
                rt.sum + lft.suf
        );
        res.pref = max(
                lft.pref,
                lft.sum + rt.pref
        );
        return res;
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx == lx) {
            seg[x] = {v};
            return;
        }
        int m = (rx + lx) >> 1;
        if (i <= m) {
            update(i, v, x * 2 + 1, lx, m);
        } else {
            update(i, v, x * 2 + 2, m + 1, rx);
        }
        seg[x] = opt(seg[x * 2 + 1], seg[x * 2 + 2]);
    }

    node build(int n, int x, int lx, int rx) {
        if (lx == rx) {
            if (lx < n)return seg[x] = node(-1);
            node aa(0);
            return aa;
        }
        int m = (lx + rx) >> 1;
        build(n, x * 2 + 1, lx, m);
        build(n, x * 2 + 2, m + 1, rx);
        seg[x] = opt(seg[x * 2 + 1], seg[x * 2 + 2]);
        return seg[x];
    }

public:
    SegTree(int n) {
        sz = 1;
        while (sz < n)sz <<= 1;
        seg = vector<node>(sz << 1);
        build(n, 0, 0, sz - 1);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, sz - 1);
    }

    int query() {
        return seg[0].maxSeg;
    }


};
