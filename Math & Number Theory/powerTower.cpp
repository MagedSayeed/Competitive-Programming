/// A^B^C.
int mul(int a, int b, int Mod) {
    return (a % Mod) * (b % Mod) % Mod;
}


int power(int a, int p, int Mod) {
    if (!p)return 1;
    int res = power(a, p / 2, Mod);
    res = mul(res, res, Mod) % Mod;
    if (p & 1)res = mul(res, a, Mod) % Mod;
    return res;
}


void solve() {
    int c, b, a;
    
    if (a % mod == 0) cout << 0;
    else
        cout << power(a, power(b, c, mod - 1), mod);
}
