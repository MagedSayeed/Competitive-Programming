int ternary_search(int l = 0,int r = 1e9){///1st version
    int ans = -1;
    while (l <= r){
        int md1 = l + (r - l) / 3;
        int md2 = r - (r - l) / 3;
        if (ok(md1) < ok(md2)){
            l = md1 + 1;///look in range [m1,r]
            ans = md2;
        }
        else{
            r = md2 - 1;///look in range [L,m2]
            ans = md1;
        }
    }
    return ans;
