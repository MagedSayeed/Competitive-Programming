//// to avoid hacking when you want to use hash in online round use this trick 
void build() {
    random_device rd;
    mt19937 mt(rd());
    auto check = [](int x) {
        for (int i = 2; i * i <= x; ++i)
            if (!(x % i))return false;
        return true;
    };
    auto rnd = [&](int l, int r) {
        return uniform_int_distribution<int>(l, r)(mt);
    };
    MOD1 = rnd(1e8, 2e9);
    MOD2 = rnd(1e8, 2e9);
    B1 = rnd(10, 300);
    B2 = rnd(10, 300);
    while (!check(MOD1))--MOD1;
    while (MOD1 == MOD2 or !check(MOD2))--MOD2;
    pw[0] = {1, 1};
    for (int i = 1; i < N; ++i) {
        pw[i].first = 1LL * pw[i - 1].first * B1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * B2 % MOD2;
    }

}
