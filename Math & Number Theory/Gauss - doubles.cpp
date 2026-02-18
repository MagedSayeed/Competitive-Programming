const double eps = 1e-9;
/// equations 
/*
Solving:
{ 𝑥+2𝑦=4
 3𝑥+4𝑦=10
You'd represent it as:
vector<vector<double>> a = {
  {1, 2, 4},
  {3, 4, 10}
};
vector<double> ans;
int result = Gauss(a, ans);
Returns an int indicating the type of solution:

-1: No solution

1: Unique solution

2: Infinite solutions
  */
int Gauss(vector<vector<double>> a, vector<double> &ans) {
  int n = (int) a.size(), m = (int) a[0].size() - 1;
  vector<int> pos(m, -1);
  double det = 1;
  int rank = 0;
  for (int col = 0, row = 0; col < m && row < n; ++col) {
    int mx = row;
    for (int i = row; i < n; i++) if (fabs(a[i][col]) > fabs(a[mx][col])) mx = i;
    if (fabs(a[mx][col]) < eps) {
      det = 0;
      continue;
    }
    for (int i = col; i <= m; i++) swap(a[row][i], a[mx][i]);
    if (row != mx) det = -det;
    det *= a[row][col];
    pos[col] = row;
    for (int i = 0; i < n; i++) {
      if (i != row && fabs(a[i][col]) > eps) {
        double c = a[i][col] / a[row][col];
        for (int j = col; j <= m; j++) a[i][j] -= a[row][j] * c;
      }
    }
    ++row, ++rank;
  }
  ans.assign(m, 0);
  for (int i = 0; i < m; i++) {
    if (pos[i] != -1) ans[i] = a[pos[i]][m] / a[pos[i]][i];
  }
  for (int i = 0; i < n; i++) {
    double sum = 0;
    for (int j = 0; j < m; j++) sum += ans[j] * a[i][j];
    if (fabs(sum - a[i][m]) > eps) return -1; //no solution
  }
  for (int i = 0; i < m; i++) if (pos[i] == -1) return 2; //infinte solutions
  return 1; //unique solution
}
