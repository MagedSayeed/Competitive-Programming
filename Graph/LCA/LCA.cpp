const int LG = 20;
struct LCA {
    int n;
    vector <int> depth, up[LG];

    LCA(vector <vector <int>> &adj, int root = 0) {
        n = (int)adj.size();
        depth.assign(n, 0);
        for (auto &i : up) i.resize(n);
        dfs(root, adj);
        init();
    }

    void dfs(int cur, vector <vector <int>> &adj) {
        for (auto &i : adj[cur]) {
            if (i == up[0][cur]) continue;
            up[0][i] = cur;
            depth[i] = depth[cur]+1;
            dfs(i, adj);
        }
    }

    void init() {
        for (int i = 1; i < LG; i++) {
            for (int j = 0; j < n; j++) {
                up[i][j] = up[i-1][up[i-1][j]];
            }
        }
    }

    int kthAncestor(int u, int k) {
        if (depth[u] < k)return -1;
        for (int bt = 0; bt < LG; bt++) {
            if (k>>bt&1) {
                u = up[bt][u];
            }
        }
        return u;
    }

    int lca(int u, int v) {
        if (depth[u] > depth[v]) {
            swap(u, v);
        }

        int diff = depth[v]-depth[u];
        v = kthAncestor(v, diff);
        if (u == v) {
            return u;
        }

        for (int bt = LG-1; ~bt; bt--) {
            if (up[bt][u] != up[bt][v]) {
                u = up[bt][u];
                v = up[bt][v];
            }
        }
        return up[0][u];
    }
};
