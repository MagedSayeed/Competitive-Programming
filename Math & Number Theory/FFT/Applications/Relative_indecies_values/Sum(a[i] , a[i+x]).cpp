// Problem 1: Sum(a[i] * b[i+x]) for given x
// Applications:
// - Time Series Analysis: Aligning and comparing two signals or datasets with an offset.
// - Correlation Function in Digital Signal Processing (DSP): Cross-correlation helps find similarity with shift.
// - Pattern Matching with Offsets: Used in matching genomic sequences, audio signals, etc.
// - Signal Delay Estimation: Estimating delay or shift between two time-domain signals.
//
// Explanation:
// - We treat array a as a polynomial with positive powers of X: a[i]*X^i
// - We treat array b as a polynomial with negative powers of X: b[i]*X^(-i)
// - Convolution of these polynomials gives us all values of Sum(a[i]*b[i+x]) for x = -(n-1) to (n-1)
// - Result is extracted from the coefficient corresponding to shift (X^(-x))
// - Important to shift indexing by n-1 to make indices non-negative in implementation

/**

 solving the following problem with fft
    you have two arrays of length n array a  , array b
       and you must answer the following eq for each given query =>   Sum(a[i] * b[i+x]) for all i from 1 to n , x is given per each query and x can be +ve or -ve
       first we make a ploy for first array where
       poly1[i] = a[i]*X^(i)
      second we make poly for second array bur with X power -ve power
       poly2[i] = b[i]*X^(-i)
      now if x = +1 so the answer where be in cofficeint of X^(-1) after muliply two polys
      don't forgot shift value here it be = n-1


      now some notes the idea of X(+ve) , X(-ve) is related with cyclic shift =>

  */


//// ur fft templete 


void solve() {
    int n, q;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int> A(2 * n), B(2 * n);
    int shift = n;
    for (int i = 1; i <= n; i++) A[i] = a[i];
    for (int i = 1; i <= n; i++) B[shift - i] = b[i];

    vector<int> res = multiply(A, B);

    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x < -shift || x > shift) cout << "0\n";
        else cout << res[shift + x] << '\n';
    }
}
