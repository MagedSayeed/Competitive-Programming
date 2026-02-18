/// there are values on edged and wanna to do some operation on path
struct LCA {
    int n;
    vector<vector<int>> up, withOp;
    vector<int> depth;
    int ignoreValue;

    LCA(vector<vector<pair<int, int>>> &adj, int ig = 0, int root = 0) {
        n = (int) adj.size();
        ignoreValue = ig;
        depth = vector<int>(n, 0);
        up = vector<vector<int>>(LG, vector<int>(n));
        withOp = vector<vector<int>>(LG, vector<int>(n, ignoreValue));
        dfs(root, adj);
        init();
    }

    void dfs(int cur, vector<vector<pair<int, int>>> &adj) {
        for (auto &[i, w]: adj[cur]) {
            if (i == up[0][cur]) continue;
            up[0][i] = cur;
            withOp[0][i] = w;
            depth[i] = depth[cur] + 1;
            dfs(i, adj);
        }
    }

    int merge(int lf, int rt) {
      /// update here
        return max(lf, rt);
    }

    void init() {
        for (int i = 1; i < LG; i++) {
            for (int j = 0; j < n; j++) {
                up[i][j] = up[i - 1][up[i - 1][j]];
                withOp[i][j] = merge(withOp[i - 1][j],
                                     withOp[i - 1][up[i - 1][j]]);

            }
        }
    }

    int OpOnPath(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);

        int ans = ignoreValue;
        int diff = depth[v] - depth[u];
        for (int bt = 0; bt < LG; ++bt) {
            if ((diff >> bt) & 1) {
                ans = merge(ans, withOp[bt][v]);
                v = up[bt][v];
            }
        }
        if (u == v) return ans;

        for (int bt = LG - 1; bt >= 0; --bt) {
            if (up[bt][u] != up[bt][v]) {
                ans = merge(ans, withOp[bt][u]);
                ans = merge(ans, withOp[bt][v]);
                u = up[bt][u];
                v = up[bt][v];
            }
        }
        ans = merge(ans, withOp[0][u]);
        ans = merge(ans, withOp[0][v]);
        return ans;
    }

    int kthAncestor(int u, int k) {
        if (depth[u] < k)return -1;
        for (int bt = 0; bt < LG; bt++) {
            if (k >> bt & 1) {
                u = up[bt][u];
            }
        }
        return u;
    }

    int lca(int u, int v) {
        if (depth[u] > depth[v]) {
            swap(u, v);
        }

        int diff = depth[v] - depth[u];
        v = kthAncestor(v, diff);
        if (u == v) {
            return u;
        }

        for (int bt = LG - 1; ~bt; bt--) {
            if (up[bt][u] != up[bt][v]) {
                u = up[bt][u];
                v = up[bt][v];
            }
        }
        return up[0][u];
    }

    int dis(int u, int v) {
        int l = lca(u, v);
        return (depth[u] + depth[v] - 2 * depth[l]);
    }
};
