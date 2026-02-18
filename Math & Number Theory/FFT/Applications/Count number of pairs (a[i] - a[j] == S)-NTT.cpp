/**
You have an array of pairs of integers (Xi,Fi)
 where Fi
 is the frequency of Xi
 in some very big array A
.

You will be given Q
 queries to be performed on A
, each query will have 2
 integers l
 and r
.

For each query, output the number of pairs of integers (Ai,Aj)
 with an absolute difference between l
 and r
 (inclusive). In other words, the number of pairs (Ai,Aj)
 such that l≤|Ai−Aj|≤r
.

Since this number is large, output it modulo 132120577
.

Input
First line will be the number of test cases T
, in each test case you will be given the following:

First line containing an integer N
, the number of frequency pairs. (1≤N≤105)

Followed by N
 lines where each line has 2 integers separated by a space: Xi
 and Fi
. (1≤Xi≤N)
 and (1≤Fi≤109)

Followed by a line containing an integer Q
, the number of queries. (1≤Q≤106)

Followed by Q
 lines, each line containing 2 integers l
 and r
 separated by a space. (1≤l,r≤N)

Output
For each test case, output Q
 integers, each integer on a separate line.

Each line should contain 1
 integer, the answer to the ith
 query.

Example
InputCopy
1
3
1 1
2 1
3 1
1
1 3
OutputCopy
3
*/

/// that make the same thing fft with mod but make sure your prime is spicial one ( C * 2^X => 2^x is the size of answer array )
 
const ll mod = 63*(1LL<<21)+1, root = 5; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
 
 
ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}
 
// Primitive Root of the mod of form 2^a * b + 1
int generator () {
    vector<int> fact;
    int phi = mod-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);
 
    for (int res=2; res<=mod; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= modpow (res, phi / fact[i]) != 1;
        if (ok)  return res;
    }
    return -1;
}
int modpow(int b, int e, int m) {
    int ans = 1;
    for (; e; b = (ll)b * b % m, e /= 2)
        if (e & 1) ans = (ll)ans * b % m;
    return ans;
}
 
void ntt(vector<int> &a) {
    int n = (int)a.size(), L = 31 - __builtin_clz(n);
    vector<int> rt(2, 1); // erase the static if you want to use two moduli;
    for (int k = 2, s = 2; k < n; k *= 2, s++) { // erase the static if you want to use two moduli;
        rt.resize(n);
        int z[] = {1, modpow(root, mod >> s, mod)};
        for (int i = k; i < 2*k; ++i) rt[i] = (ll)rt[i / 2] * z[i & 1] % mod;
    }
    vector<int> rev(n);
    for (int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                int z = (ll)rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
                a[i + j + k] = ai - z + (z > ai ? mod : 0);
                ai += (ai + z >= mod ? z - mod : z);
            }
        }
    }
}
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    if (a.empty() || b.empty()) return {};
    int s = (int)a.size() + (int)b.size() - 1, B = 32 - __builtin_clz(s), n = 1 << B;
    int inv = modpow(n, mod - 2, mod);
    vector<int> L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    for (int i = 0; i < n; ++i) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
    ntt(out);
    return {out.begin(), out.begin() + s};
}
void solve() {
    int n;
    cin >> n;
    const int mxN = n + 5 , shift=n;
    vector<int> a(n), freq(mxN) , freq2(mxN);
    while (n--) {
        int x , f; cin>>x>>f;
         freq[x]+=f , freq2[shift-x]+=f;
         freq[x]%=mod;
         freq2[shift-x]%=mod;
    }
 
    vector<int> ans = multiply(freq, freq2);
    for (int i = 1; i < ans.size(); ++i) {
        ans[i]+=ans[i-1];
        ans[i]%=mod;
    }
    int q;
       cin >> q;
    while (q--) {
       int l , r ; cin>>l>>r;
       cout<<(ans[shift+r]-ans[shift+l-1]+mod)%mod<<"\n";
    }
}
