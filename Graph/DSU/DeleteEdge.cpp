struct dsu {
    vector<int> per, sm, sz;
    int Components, gsz;

    dsu(int n) {
        Components = n;
        gsz = n;
        sz.assign(2 * n + 2, 0);
        per.assign(2 * n + 2, 0);
        sm.assign(2 * n + 2, 0);
        for (int i = 0; i <= n; ++i) {
            sz[i] = 1;
            sm[i] = i;
            per[i] = n + i;
        }
        for (int i = n + 1; i < per.size(); ++i) {
            per[i] = i;
        }
        for (int i = 1; i <= n; ++i) {
            sz[n + i] += sz[i];
            sm[n + i] += sm[i];
        }
    }

    int find(int u) {
        if (u == per[u])return u;
        return per[u] = find(per[u]);
    }

    bool merge(int u, int v) {
        int leader1 = find(u), leader2 = find(v);
        if (leader1 == leader2)return false;
        sm[leader1] += (sm[leader2]);
        sz[leader1] += sz[leader2];
        sz[leader2] = 0;
        sm[leader2] = 0;
        per[leader2] = leader1;
        return true;
    }

    void unmerge(int v, int u) {
        int leader = find(v);
        sm[leader] -= v;
        sz[leader]--;
        leader = find(u);
        sm[leader] += v;
        sz[leader]++;
        per[v] = leader;
    }

};
