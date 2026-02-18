int n;
cin >> n;
vector<int> a(n);
for (int i = 0; i < n; ++i) {
    cin >> a[i];
}
map<int, int> dp[n]; // dp[i][g] = number of subarrays ending at i with GCD g
map<int, int> ans;   // ans[g] = total number of subarrays in whole array with GCD g
dp[0][a[0]] = 1;
ans[a[0]]++;
for (int i = 1; i < n; ++i) {
    dp[i][a[i]] = 1;
    ans[a[i]]++;
        for (auto &[old_gcd, frq]: dp[i - 1]) {
        int new_gcd = gcd(old_gcd, a[i]);
        dp[i][new_gcd] += frq;
        ans[new_gcd] += frq;
    }
}
while (q--) {
        int x;
        cin >> x;
        if (ans.count(x)) {
            cout << ans[x];
        } else cout << 0;
        cout << endl;
    }
