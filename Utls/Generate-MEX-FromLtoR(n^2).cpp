{
        int n;
        cin >> n;
        int Mex[n][n];
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            int mex = 0;
            set<int> curr;
            for (int j = i; j < n; ++j) {
                if (a[j] == mex)mex++;
                else if (a[j] > mex) {
                    curr.emplace(a[j]);
                }
                while (!curr.empty() and mex == *curr.begin()) {
                    mex++;
                    curr.erase(curr.begin());
                }
                Mex[i][j] = mex;
            }
        }
