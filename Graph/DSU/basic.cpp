struct DSU {
    vector<int> par, sz;
 
    DSU(int n) {
        sz.assign(n + 2, 1);
        par.resize(n + 2);
        std::iota(par.begin(), par.end(), 0);
    }
 
    int find(int ch) {
        if (ch == par[ch]) return ch;
        else return par[ch] = find(par[ch]);
    }
 
    bool same(int u, int v) {
        return find(u) == find(v);
    }
 
    bool merge(int f, int s) {
        f = find(f), s = find(s);
        if (f == s) return false;
        return par[s] = f, sz[f] += sz[s], sz[s] = 0, true;
    }
};
