There are n children and m apples that will be distributed to them. Your task is to count the number of ways this can be done.
For example, if n=3 and m=2, there are 6 ways: [0,0,2], [0,1,1], [0,2,0], [1,0,1], [1,1,0] and [2,0,0].
https://cses.fi/problemset/task/1716/
const int sz = 2e6 + 5, MOD = 1e9 + 7; //// check sz and mod 
int fact[sz], inv[sz], invFact[sz];

ll mul(ll x, ll y, ll M = MOD) {
    return (((x % M) * (y % M)) % M);
}

void pre(ll mod = MOD) {
    inv[1] = 1;
    for (int i = 2; i < sz; ++i) {
        inv[i] = mod - mod / i * 1LL * inv[mod % i] % mod;
    }
    fact[0] = fact[1] = 1;
    invFact[0] = invFact[1] = 1;
    for (int i = 2; i < sz; ++i) {
        fact[i] = mul(fact[i - 1], i);
        invFact[i] = mul(invFact[i - 1], inv[i]);
    }
}

int nCr(int n, int r) {
    return mul(
            mul(invFact[r], invFact[n - r]),
            fact[n]
    );
}

void solve() {
    pre();
    int n, m;
    cin >> n >> m;
    cout << nCr(m + n - 1, m);
}


/// if you wanaa try to divive all form 0 to n balls over m boxes (n+m)C(m)
