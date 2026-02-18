/** Remember that:
 *  - For a **directed** graph to have an Euler path:
 *      - Each node's in-degree and out-degree must match, except for:
 *          - One node with out-degree = in-degree + 1 (start point)
 *          - One node with in-degree = out-degree + 1 (end point)
 *      - If all nodes have equal in-degree and out-degree → Euler **circuit** exists.
 *  - `ord` stores the order of visited edges (by edge ID).
 *  - `path` stores the sequence of visited vertices in the Euler path.
 *  - `in[i]` and `out[i]` track the in/out degrees of node `i`.
 *  - `ptr[i]` tracks the current index in `adj[i]` to avoid reprocessing edges.
 */

struct DirectedEuler{ // 1-based
    vector<vector<array<int, 2>>> adj;
    vector<bool> vis;
    vector<int> path, ptr, ord, in, out;
    bool isCircuit = 0;
    int n, e = 0;

    DirectedEuler(int n) : n(n), in(n + 1), out(n + 1), ptr(n + 1), adj(n + 1){}

    void add_edge(int u, int v){
        adj[u].push_back({v, e});
        out[u]++; in[v]++;
        e++;
    }

    bool is_eulerian(){
        int src = 0, sink = 0;
        for(int i = 1; i <= n; i++){
            if(in[i] == out[i]) continue;
            if(abs(in[i] - out[i]) > 1) return 0;
            if(out[i] > in[i]) src++;
            else sink++;
        }
        if(src == 0 && sink == 0) isCircuit == 1;
        if(src == sink && src <= 1) return 1;
        return 0;
    }

    void dfs(int u){
        for(int& i = ptr[u]; i < sz(adj[u]); i++){
            auto& [v, id] = adj[u][i];
            if(vis[id]) continue;
            vis[id] = 1;
            dfs(v);
            ord.push_back(id);
        }
        path.push_back(u);
    }

    vector<int> get_path(){
        if (!is_eulerian()) return {};

        vis = vector<bool>(e);
        int start = 0;
        for(int i = 1; i <= n; i++){
            if(adj[i].empty()) continue;
            if(out[i] > in[i] || isCircuit){
                start = i;
                break;
            }
        }
        dfs(start);
        reverse(all(path));
        reverse(all(ord));
        return path;
    }
};
