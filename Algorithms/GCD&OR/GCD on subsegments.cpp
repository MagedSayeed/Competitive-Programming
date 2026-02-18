Assume you have set of numbers in which you add elements one by one 
and on each step calculate  of all numbers from set. 
  Then we will have no more than log2 A different values of gcd. 
  Thus you can keep compressed info about all  on subsegments of :

code=>:
   int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> dp[n];
    /// dp[i][x] => the longest subarray ending in index i with GCD = x
    /**
    Key is gcd,
    Value is the largest length such that gcd(a[i - len], ..., a[i]) equals to key.
    */
    dp[0][a[0]] = 0; /// that mean j-i if you wanna the correct length start with 1 and also initialize any state with 1 not 0
    for (int i = 1; i < n; ++i) {
        dp[i][a[i]] = 0;
        for (const auto &[old_gcd, end_pos]: dp[i - 1]) {
            int new_gcd = gcd(old_gcd, a[i]);
            dp[i][new_gcd] = max(dp[i][new_gcd], end_pos + 1);
        }
    }
