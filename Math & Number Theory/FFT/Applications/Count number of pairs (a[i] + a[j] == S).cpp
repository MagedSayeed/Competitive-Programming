/**
 * FFT (Fast Fourier Transform) and Polynomial Multiplication
 *
 * Core Idea:
 *  - Treat array `a` as a polynomial:
 *      - `a[i]` represents the coefficient of `x^i`, i.e., frequency of value `i`.
 *      - This builds a polynomial: P(x) = freq[0] + freq[1]x^1 + ... + freq[n]x^n.
 *
 * Application – Count number of pairs (a[i] + a[j] == S):
 *  - Multiply P(x) * P(x) → result[x^S] gives number of ways to form sum = S.
 *  - Because (x^i)*(x^j) = x^(i+j), and frequencies are multiplied.
 *  - Handles all pairs including (i == j).
 *  - To exclude (i == j): subtract 1 from result[2*i] for each occurrence of i.
 *  - For unordered pairs (i < j): divide final count by 2.
 *
 * Generalization:
 *  - To count k-sums (a[i1] + a[i2] + ... + a[ik] == S), compute P(x)^k.
 *
 * multiply(a, b):
 *  - Multiplies two integer polynomials using FFT and returns resulting coefficients.
 */


using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void solve() {
    int n;
    cin >> n;

    const int mxN = 1e5 + 1;
    vector<int> a(n), freq(mxN);
    for (int &x : a) cin >> x, freq[x]++;

    // Compute all possible a[i] + a[j] sums
    vector<int> ans = multiply(freq, freq);

    int q;
    cin >> q;
    while (q--) {
        int sum;
        cin >> sum;
        cout << ans[sum] << endl; // Includes i == j pairs
    }

    // Remove overcount from (i == j)
    for (int x : a)
        if (2 * x < (int)ans.size())
            ans[2 * x]--;

    // Count unordered pairs (i < j)
    cin >> q;
    while (q--) {
        int sum;
        cin >> sum;
        cout << ans[sum] / 2 << endl;
    }
}
