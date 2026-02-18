/// x1+x2+xL = Sum and xi>=1
/// dp solution  N*N
 prefix[0][0] = 1;
    for (int j = 1; j < sz; ++j) {
        prefix[0][j] = add(prefix[0][j], prefix[0][j - 1]);
    }
    for (int i = 1; i < sz; ++i) {
        for (int rem = 1; rem < sz; ++rem) {
            dp[i][rem] = add(dp[i][rem], prefix[i - 1][rem - 1]);
        }
        for (int j = 0; j < sz; ++j) {
            prefix[i][j] = add(prefix[i][j], dp[i][j]);
            if (j)
                prefix[i][j] = add(prefix[i][j], prefix[i][j - 1]);
        }

    }

//// Combinatorics 
(Sum-1)C(L-1) Sum refere to apples , L refere to Boxes
