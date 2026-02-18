
// Problem 2: Cyclic Right Shift and Dot Product
// Applications:
// - Cyclic Pattern Matching: Comparing circular sequences like DNA, circular buffers, etc.
// - Audio Signal Looping: Matching or blending audio wave segments in music or compression.
// - Rotating Queues: Evaluating dot products for every rotation in cyclic scheduling algorithms.
// - Hashing or Checksums: Bitwise or dot-product-based rolling hash in circular arrays.
//
// Explanation:
// - We fix array a and cyclically shift array b for each query.
// - After right-shifting b by k, compute the dot product a[i] * b[(i-k)%n]
// - To achieve this using FFT:
//   1. Extend a with zero-padding: [0, ..., 0, a0, ..., an-1]
//   2. Repeat b to simulate wrap-around: [b0, ..., bn-1, b0, ..., bn-1]
//   3. Use same convolution method with FFT to compute all possible shifts in one go
// - Extract result of kth cyclic shift from position (n-1+k)
// - Again, convolution lets us compute all dot products in O(n log n)
/**

      if you have an array a and you have some of queres of two types
      1-  Sum(a[i] * b[i]) for all i from 1 to n
      2- make a cyclic Right shift with K => K is given for each query of type 2 =>(if cyclic is right of left it doesn;t matter in logic of solution )

     we make the same logic of above problem but with nice trick
      assume array a = a1 , a2 , a3
      assume array b = b1 , b2 , b3
      answer is a1*b1 + a2*b2 + a3*b3
       after applying one right cyclic shift
       a = a1 , a2 , a3
        b = b3 ,b1 , b2
        answer is a1*b3 + a2*b1 + a3*b2

      we make this manual
       a = 0 , 0 , 0 , a1 , a2 , a3
       b = b1 , b2 , b3 ,b1 , b2 , b3
       and solve the above question as same and X is totSumOfShifting %(size of original array)
       => don't forgot shift and take care when i  , i+x we git answer of -x if i , i-x we get answer of x
       and in right shift actully i , i-x

*/


/// fft temolete

 int n  , q ;
    cin >> n >> q;
    vector<int> a(2*n), b(2*n);
    for (int i = n; i < 2*n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = n; i < 2*n; i++) b[i]=b[i%n];
    int shift = 2*n-1;
    vector<int> poly1(2 * n,0), poly2(2 * n,0);
    for (int i = 0; i < 2*n; i++) poly1[i] = a[i];
    for (int i = 0; i < 2*n; i++) poly2[shift - i] = b[i];
    vector<int> res = multiply(poly1, poly2);
    int tot_shift = 0;
    while (q--) {
        int type;
        cin >> type;
        if (type ==1) {
            cout << res[shift + tot_shift] << '\n';
        } else {
            int k; cin >> k;
            tot_shift = (tot_shift + k) % (n);
        }
    }
