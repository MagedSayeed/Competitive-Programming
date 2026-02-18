vector<int> bfs(vector<vector<int>> &adj, int src) {
  const int n = adj.size();
  vector<int> dis(n);
  queue<pair<int, int>> q;
  q.emplace(src, -1);
  while (q.size()) {
    auto [u, p] = q.front();
    q.pop();
    for (int &v: adj[u]) {
      if (v == p)continue;
      dis[v] = dis[u] + 1;
      q.emplace(v, u);
    }
  }
  return dis;
}

pair<int, vector<int>> diameter(vector<vector<int>> &adj) {
  auto d1 = bfs(adj, 0);
  int u = max_element(d1.begin(), d1.end()) - d1.begin();
  d1 = bfs(adj, u);
  int v = max_element(d1.begin(), d1.end()) - d1.begin();
  auto d2 = bfs(adj, v);
  int dia = *max_element(d2.begin(), d2.end());
  for (int i = 0; i < adj.size(); ++i) {
    d1[i] = max(d1[i], d2[i]);
  }
  return {dia, d1}; 
  /// if dia start with u , end with v
  /// d1[i] max(dis(u , d[i] ) , dis(v , d[i]))
  /// length of dia , max distance b
}
