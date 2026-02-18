
ll pascal[61][61], fact[N], factInv[N];

ll fastexp(ll a, ll b)
{
    if(not b)
        return 1;
    
    ll ret = fastexp(a, b >> 1);
    return ((ret * ret)%mod * (b&1 ? a : 1))%mod;
}


ll nCr(ll n, ll r)
{
    if(r > n)
        return 0;
    return (fact[n] * ((factInv[r] * factInv[n-r])%mod)) %mod;
}

ll npr(ll n, ll r)
{
    if(r > n)
        return 0;
    return (fact[n] * factInv[n-r]) % mod;
}

void pre()
{
    // pascal[0][0] = 1;
    // for(int i=1; i<=60; i++)
    // {
    //     pascal[i][0] = 1;
    //     for(int j=1; j<=60; j++)
    //         pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
    // }
  
    fact[0] = 1;
    for(int i=1; i<N; i++)
        fact[i] = (fact[i-1] * i) %mod;

    factInv[N-1] = fastexp(fact[N-1], mod-2);
    for(int i=N-2; i>=0; i--)
        factInv[i] = (factInv[i+1] * (i+1))%mod;
}
