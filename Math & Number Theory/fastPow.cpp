int power(int a, int p, int Mod) {
    if (!p)return 1;
    int res = power(a, p / 2, Mod);
    res = res * res % Mod;
    if (p & 1)res = res * a % Mod;
    return res;
}
