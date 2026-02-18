/*
O(√n).
Let \sigma(n) denote the sum of divisors of an integer n. For example, \sigma(12)=1+2+3+4+6+12=28.
Your task is to calculate the sum \sum_{i=1}^n \sigma(i) modulo 10^9+7.
  */
const int N = 1e6 + 5, mod = 1e9 + 7;

int add(int a, int b) {
    return (a % mod + b % mod) % mod;
}

int mul(int a, int b) {
    return (a % mod * b % mod) % mod;
}


int power(int a, int p) {
    if (!p)return 1;
    int res = power(a, p / 2);
    res = res * res % mod;
    if (p & 1)res = res * a % mod;
    return res;
}

void solve() {
    const int inv = power(2, mod - 2);
    int n;
    cin >> n;
    int st = 1, lst, res{};
    while (st <= n) {
        int now = n / st;
        lst = n / now;
        res = add(res,
                  mul(now,
                      mul(mul(lst - st + 1, add(st, lst)), inv)
                  )
        );
        st = lst + 1;
    }
    cout << res;

}
