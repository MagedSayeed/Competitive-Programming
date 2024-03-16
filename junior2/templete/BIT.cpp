struct BIT
{
    vector<int> tree;
    BIT(int n)
    {
        tree.assign(n + 1, 0);
    }
    void update(int l, int v)
    {
        while (l < tree.size())
        {
            tree[l] += v;
            l += l & -l;
        }
    }
    int query(int l)
    {
        int res = 0;
        while (l > 0)
        {
            res += tree[l];
            l -= l & -l;
        }
        return res;
    }
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};
