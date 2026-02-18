const int sz = 2e+5 ,MOD = 998244353  ;
int fact[sz], inv[sz], invFact[sz];
ll mul(ll x,ll y,ll M = MOD){
    return (((x % M) * (y % M)) % M);
}
void pre(ll mod = MOD){
    inv[1] = 1;
    for (int i = 2; i < sz; ++i)
    {
        inv[i] = mod - mod / i * 1LL * inv[mod % i] % mod;
    }
    fact[0] = fact[1] = 1;
    invFact[0] = invFact[1] = 1;
    for (int i = 2; i < sz; ++i)
    {
        fact[i] = mul(fact[i - 1], i);
        invFact[i] = mul(invFact[i - 1], inv[i]);
    }
}
int nPr(int n, int r)
{
    if (r > n)return 0;
    return mul(
            fact[n],
            invFact[n - r]
    );
}
int nCr(int n, int r)
{
    return mul(
            mul( invFact[r], invFact[n - r] ),
            fact[n]
    );
}
