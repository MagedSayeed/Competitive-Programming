struct query
{
    int l, r, id;
};
void add(int x)
{
   
}
void remove(int x)
{
   
}

vector<int> mo(vector<query> &q)
{
    sort(all(q), [&](const query &a, const query &b)
         { return (make_pair(a.l / SQ, a.r) < make_pair(b.l / SQ, b.r)); });
    int l = q[0].l, r = q[0].l;
    add(q[0].l);
    vector<int> ans(q.size());
    for (const auto &[le, ri, id] : q)
    {
        while (r < ri)add(++r);
        while (l < le)remove(l++);
        while (l > le)add(--l);
        while (r > ri)remove(r--);
        ans[id] = cur;
    }
    return ans;
}
