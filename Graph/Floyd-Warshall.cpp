const int N = 200;
int adj[N][N];
int INF;

vector<vector<int>> floyed() {
//  memset(adj, '?', sizeof adj);
//  INF = adj[0][0];
/// when you read input make sure to mimize the value of cost[i][j] (muliple edges with difftent values ) 
  //// make sure the diagonal is =0 cost[i][i]=0
  auto d = adj;
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (d[i][k] < INF && d[k][j] < INF)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}
