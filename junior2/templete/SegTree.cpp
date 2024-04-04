struct node /// deh
{
    int sum;
};
struct SegTree
{
#define LF (x * 2 + 1)
#define RT (x * 2 + 2)
#define md ((lx + rx) >> 1)
private:
    vector<node> seg;
    int n;
    node ign() /// deh
    {
        node res;
        res.sum = 0;
        return res;
    }
    node single(int x) ///deh
    {
        node res;
        res.sum = x;
        return res;
    }
    node mrg(const node &L, const node &R) /// deh
    {
        node res;
        res.sum = L.sum + R.sum;
        return res;
    }
    void build(vector<int> &arr, int x, int lx, int rx)
    {
        if (lx == rx)
        {
            seg[x] = single(arr[lx]);
            return;
        }
        build(arr, LF, lx, md);
        build(arr, RT, md + 1, rx);
        seg[x] = mrg(seg[LF], seg[RT]);
    }
    void update(int i, int v, int x, int lx, int rx)
    {
        if (lx == rx)
        {
            seg[x] = single(v);
            return;
        }
        if (md >= i)
            update(i, v, LF, lx, md);
        else
            update(i, v, RT, md + 1, rx);
        seg[x] = mrg(seg[LF], seg[RT]);
    }
    node query(int l, int r, int x, int lx, int rx)
    {
        if (l <= lx and rx <= r)
        {
            return seg[x];
        }
        if (r < lx or rx < l)
        {
            return ign();
        }
        return mrg(
            query(l, r, LF, lx, md),
            query(l, r, RT, md + 1, rx));
    }
public:
    SegTree(int n) : n(n) { seg.assign(4 * n, {}); }
    SegTree(vector<int> &arr)
    {
        n = arr.size();
        seg.assign(n * 4, {});
        build(arr, 0, 0, n - 1);
    }
    void update(int i, int v)
    {
        update(i, v, 0, 0, n - 1);
    }
    node query(int l, int r)
    {
        return query(l, r, 0, 0, n - 1);
    }
#undef LF
#undef RT
#undef md
};
