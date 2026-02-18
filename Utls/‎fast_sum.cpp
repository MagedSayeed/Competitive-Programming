long long fast_sum(int st , int n) { // summation n/i and i from st to n
    long long total = 0;
    int i = st;
    while (i <= n) {
        int q = n / i;
        int j = n / q;
        total += 1LL * q * (j - i + 1);
        i = j + 1;
    }
    return total;
}
