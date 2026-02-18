
/** Remember that:
 *  - For an undirected graph to have an Euler path:
 *      - The number of vertices with an odd degree must be 0 or 2.
 *      - If exactly 2 vertices have an odd degree → Euler **path** exists.
 *      - If 0 vertices have an odd degree → Euler **circuit** (and path) exists.
 *  - `ord` stores the order of visited edges (by edge ID).
 *  - `path` stores the sequence of visited vertices in the Euler path.
 *  - `ptr` is used to track the current position in `adj[u]` to ensure each edge is processed at most once, avoiding TLE.
 */

struct UndirectedEuler { // 1-based
    vector<vector<array<int, 2>>> adj;
    vector<bool> vis;
    vector<int> path, ptr, ord;
    bool isCircuit = 0;
    int n, e = 0;

    UndirectedEuler(int n) : n(n), ptr(n + 1), adj(n + 1) {}

    void add_edge(int u, int v) {
        adj[u].push_back({v, e});
        adj[v].push_back({u, e});
        e++;
    }

    bool is_eulerian() {
        int odd = 0;
        for (int i = 1; i <= n; i++) {
            odd += (adj[i].size()) & 1;
        }
        if (odd == 0) isCircuit = 1;
        if (odd == 0 || odd == 2) return 1;
        return 0;
    }

    void dfs(int u) {
        for (int &i = ptr[u]; i < (adj[u].size()); i++) {
            auto &[v, id] = adj[u][i];
            if (vis[id]) continue;
            vis[id] = 1;
            dfs(v);
            ord.push_back(id);
        }
        path.push_back(u);
    }

    vector<int> get_path() {
        if (!is_eulerian()) return {};

        vis = vector<bool>(e);
        int start = 0;
        for (int i = 1; i <= n; i++) {
            if (adj[i].empty()) continue;
            if ((adj[i].size()) % 2 || isCircuit) {
                start = i;
                break;
            }
        }
        dfs(start);
        reverse(path.begin(), path.end());
        reverse(ord.begin(), ord.end());
        return ord;
    }
};
