/// this code answer for fixed length in O(n)*log for constant X if X is variable ask samy for FFT Solution 

void solve() {
    int n, m, res{}, x, cur{};
    cin >> n >> m;
    map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cur += x;
        res += mp[cur - m];
        mp[cur]++;
    }
    cout << res;
}
