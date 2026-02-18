/*
 if u get a range from l to r -> l, r 0-indexed
  and you want to calculate this formula 
 a[l]*1 + a[l+1]*2 + ...... a[r]*(r-l+1) 
 it solve for fixed array but if there are updated go to Arithmetic Progression Segtree
*/ 
 int n;
    cin >> n;
    vector<int> a(n), pre, wpre;
    for (int &i: a)cin >> i;
    pre = a;
 
    for (int i = 1; i < n; ++i) {
        pre[i] = add(pre[i], pre[i - 1]);
    }
    wpre = a;
    wpre[0] = 0;
    for (int i = 1; i < n; ++i) {
        wpre[i] = mul(wpre[i], i);
        wpre[i] = add(wpre[i], wpre[i - 1]);
 
    }
    auto query = [&](int l, int r) -> int {
        if (!l)return sub((wpre[r]), mul((l - 1), (pre[r])));
        return sub(sub(wpre[r], wpre[l - 1]), mul((l - 1), sub(pre[r], pre[l - 1])));
    };
