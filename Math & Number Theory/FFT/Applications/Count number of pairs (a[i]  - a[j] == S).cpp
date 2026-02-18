/**
 * FFT for Counting (a[i] - a[j] == x) Pairs
 *
 * Problem:
 *  - Given array `a` and `q` queries (each query = x)
 *  - For each x, count number of pairs (i, j) such that: a[i] - a[j] == x
 *
 * Observation:
 *  - Let freq[v] = count of value `v` in array
 *  - Let poly1(x) = Σ freq[a[i]] * x^(a[i])
 *  - Let poly2(x) = Σ freq[a[i]] * x^(-a[i])
 *  - Then poly1 * poly2 = P(x), where:
 *      - Coefficient of x^k gives number of (i, j) such that a[i] - a[j] = k
 *
 * Handling Negative Powers:
 *  - Use a large `shift` to avoid negative exponents
 *  - Construct:
 *      - poly1[i] = freq[i]
 *      - poly2[shift - i] = freq[i]
 *  - After multiplication:
 *      - Result[k + shift] = number of pairs where a[i] - a[j] = k
 */

using cd = complex<double>;
const double PI = acos(-1);

// In-place FFT
void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w = 1;
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert)
        for (cd &x : a) x /= n;
}

// Multiply two polynomials using FFT
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size() + (int)b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
    return result;
}

void solve() {
    int n;
    cin >> n;

    const int mxN = 1e5 + 5, shift = 1e5;
    vector<int> a(n), freq(mxN), freq2(mxN);
    for (int &x : a) cin >> x, freq[x]++, freq2[shift - x]++;

    // Multiply freq and reversed freq to count a[i] - a[j]
    vector<int> ans = multiply(freq, freq2);

    /**
     * Example:
     * Input:
     *   a = [1, 2, 2, 1, 3]
     *   Queries: -1, 2, 4
     * Output:
     *   -1 → 6   (pairs with difference -1)
     *   2  → 2   (pairs with difference 2)
     *   4  → 0   (no such pairs)
     */

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x + shift] << endl;
    }
}
