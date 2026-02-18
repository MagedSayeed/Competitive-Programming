
vector<vector<int>> pre(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pre[i][j] =
                    grid[i - 1][j - 1] +
                    pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }

//to get sum of submatrix from l , r to l2 , r2 such that l,r is the top left and l2,r2 is bottom right cell and result included 

 auto ask = [&](int l, int r, int l2, int r2) -> int {
        return pre[l2 + 1][r2 + 1] - pre[l2 + 1][r] - pre[l][r2 + 1] + pre[l][r];
    };
