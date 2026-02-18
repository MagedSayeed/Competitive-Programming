pair<vector <ll>, vector <int>> dijkstra(int src, vector <vector <pair<int, ll>>> &adj) {
    int n = (int)adj.size();
    vector <ll> dist(n, 2e18);
    dist[src] = 0;
    priority_queue <pair<ll, int>, vector <pair<ll, int>>, greater <>> pq;
    pq.push({0, src});
    vector <int> par(n, -1);
    while(!pq.empty()) {
        auto [dis, cur] = pq.top();
        pq.pop();
        if (dist[cur] < dis) continue;
        for (auto &[i, w] : adj[cur]) {
            if (dist[i] > dis+w) {
                dist[i] = dis+w;
                par[i] = cur;
                pq.push({dist[i], i});
            }
        }
    }
    return {dist, par};
}
 
vector <int> getPath(int src, int dest, vector <int> &par) {
    vector <int> path;
    int cur = dest;
    while(cur != src) {
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}
