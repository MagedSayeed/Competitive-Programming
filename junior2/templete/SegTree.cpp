struct SegTree
{
#define LF (x * 2 + 1)
#define RT (x * 2 + 2)
#define md ((lx + rx) >> 1)
    struct node /// deh
    {
        int sum;
    };

private:
    vector<node> seg;
    int sz;
    node ign() /// deh
    {
        return {};
    }
    node mrg(const node &LF, const node &RT) /// deh
    {
        node res;
        res.sum = LF.sum + RT.sum;
        return res;
    }
    void build(vector<int> &arr, int x, int l, int r)
    {
        if (l == r)
        {
            seg[x] = arr[l];
        }
        build(arr, LF, lx, md);
        build(arr, RT, md + 1, rx);
        seg[x] = merge(seg[LF], seg[RT]);
    }
    void update(int l, int v, int x, int lx, int rx)
    {

        if (lx == rx)
        {
            seg[x] = v;
        }
        if (md >= i)
            update(l, v, LF, lx, md);
        else
            update(l, v, RT, md + 1, rx);
        seg[x] = merge(seg[LF], seg[RT]);
    }
    node query(int l, int r, int x, int lx, int rx)
    {
        if (l <= lx and rx <= r)
        {
            return seg[x];
        }
        if (r < lx or rx < l)
        {
            return ign;
        }
        return merge(
            query(l, r, LF, lx, md),
            query(l, r, RT, md + 1, rx));
    }

public:
    SegTree(vector<int> &n)
    {
        sz = n.size();
        seg.assign(sz * 4, {});
        build(arr, 0, 0, sz - 1);
    }
    void update(int i, int v)
    {
        update(i, v, 0, 0, sz - 1);
    }
    node query(int l, int r)
    {
        return query(l, r, 0, 0, sz - 1);
    }
#undef LF
#undef RT
#undef md
};
