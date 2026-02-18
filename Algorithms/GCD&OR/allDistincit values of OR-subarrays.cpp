 int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> total, dp;
    for (int i = 0; i < n; ++i) {
        set<int> curr;
        total.insert(a[i]);
        curr.insert(a[i]);
        for (int x: dp) {
            curr.insert(a[i] | x);
            total.insert(a[i] | x);
        }
        swap(dp, curr);
    }
    cout << total.size(); /// total contain all values of subarrayOR
