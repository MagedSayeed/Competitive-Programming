struct SegTree
{
    vector<int> tree;
    SegTree(int n)
    {
        tree.assign(4 * n, {});
    }
    void build(vector<int> &v, int x, int lx, int rx)
    {
        if (lx == rx)
        {
            tree[x] = v[lx];
            return;
        }
        int md = lx + rx >> 1;
        build(v, x * 2 + 1, lx, md);
        build(v, x * 2 + 2, md + 1, rx);
        tree[x] = tree[x * 2 + 1] + tree[x * 2 + 2];
    }
    void update(int idx, int val, int x, int lx, int rx)
    {
        if (lx == rx)
            tree[x] = val;

        int md = lx + rx >> 1;

        if (idx >= md)
            update(idx, val, x * 2 + 2, md + 1, rx);
        else
            update(idx, val, x * 2 + 1, lx, md);

        tree[x] = tree[x * 2 + 1] + tree[x * 2 + 2];
    }
    int query(int l, int r, int x, int lx, int rx)
    {
        if (r < lx or l > rx)
            return 0;

        if (l <= lx and r >= rx)
            return tree[x];

        int md = lx + rx >> 1;
        return query(l, r, x * 2 + 1, lx, md) + query(l, r, x * 2 + 2, md + 1, rx);
    }
};
