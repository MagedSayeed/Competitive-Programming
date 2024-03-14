int merge(int a,int b)return min(a,b);
void build()
{
    b.assign(SQ, oo);
    for (int i = 0; i < n; i++)
        b[i / SQ] = merge(b[i / SQ], arr[i]);
}
void update(int i, int x)
{
    arr[i] = x;
    int l = i - i % SQ, r = merge(l + SQ - 1, n - 1), res = 1e9;
    for (int idx = l; idx <= r; idx++)
    {
        res = merge(res, arr[idx]);
    }
    b[i / SQ] = res;
}
int query(int l, int r)
{
    int ans = 1e9;
    while (l % SQ and l <= r)
    {
        ans = merge(arr[l], ans);
        l++;
    }
    while (l + SQ - 1 <= r)
    {
        ans = merge(ans, b[l / SQ]);
        l += SQ;
    }
    while (l <= r)
    {
        ans = merge(arr[l], ans);
        l++;
    }
    return ans;
}
