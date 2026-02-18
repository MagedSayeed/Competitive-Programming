const int SQ = 460;

struct query {
    int l, r, idx;

    bool operator<(query &other) {
        if (l / SQ != other.l / SQ) return l / SQ < other.l / SQ;
        return ((l / SQ) & 1 ? r < other.r : r > other.r); /// ignore 2*sq
    }
};

void solve() {
    /// MO's
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l;
        cin >> queries[i].r;
        --queries[i].l;
        --queries[i].r;
        queries[i].idx = i;
    }
    //// sort fun
    std::sort(queries.begin(), queries.end());
    int l = 0, r = -1; /// r<l mean answer not include the current idx
    int ans{};
    vector<int> res(q);
    auto add = [&](int idx) {

    };
    auto del = [&](int idx) {

    };
    auto query = [&]() {
        return ans;
    };
    for (auto &[lq, rq, idx]: queries) {
        //// !! remember add before del
        while (lq < l)add(--l);
        while (r < rq)add(++r);
        while (l < lq)del(l++);
        while (rq < r)del(r--);
        res[idx] = query();
    }
}
