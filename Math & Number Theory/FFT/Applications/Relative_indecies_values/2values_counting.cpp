/**
 * FFT for Counting (a[i], a[j]) Pairs with Fixed Distance and Values
 *
 * Problem:
 *  - Given array `a` of size `n` with elements in {2, 3}
 *  - Answer multiple queries:
 *      1. Count pairs (i, j): a[i] = 3, a[j] = 2, and i - j = x
 *      2. Count pairs (i, j): a[i] = 2, a[j] = 2, and i - j = x
 *      3. Count pairs (i, j): a[i] = 3, a[j] = 3, and i - j = x
 *      4. Count pairs (i, j): a[i] = 2, a[j] = 3, and i - j = x
 *
 * Observation:
 *  - We want to compute Σ a[i] * b[i + x], for various `x`
 *  - This can be done using FFT convolution (cross-correlation)
 *  - For i - j = x, we use same array twice (e.g., 2 with 2, or 3 with 3)
  *  - Build binary arrays new_arr2 and new_arr3:
 *      - new_arr2[i] = 1 if a[i] == 2, else 0
 *      - new_arr3[i] = 1 if a[i] == 3, else 0
 *
 *  - For (2, 2) pairs:
 *      - poly2_1 = new_arr2 +ve power (like array a in Sum(a[i] *b[i+x])
 *      - poly2_2 = (new_arr2) -ve power (like array b in Sum(a[i] *b[i+x])  (shift -i)
 
 *  - For (3, 3) pairs:
 *      - poly3_1 = new_arr3 +ve power (like array a in Sum(a[i] *b[i+x])
 *      - poly3_2 = (new_arr3) -ve power (like array b in Sum(a[i] *b[i+x])  (shift -i)
 *
 *  - For (3, 2) pairs (directional, i - j = x):
 *      - poly32_1 = new_arr2 (acts as `a`)
 *      - poly32_2 = (new_arr3) (acts as `b`) (shift -i)
 *
 * FFT Result:
 *  - Let `res = FFT(poly1) * FFT(poly2)`
 *  - Result is centered at index `n - 1`, so:
 *      - To get number of pairs with i - j = x → res[n - 1 + x]
 *      - To get number of pairs with |i - j| = x → res[n - 1 + x] + res[n - 1 - x]
 *
 * Why It Works:
 *  - Convolution of a and reversed b gives Σ a[i] * b[i + x]
 *  - That's exactly the number of desired (i, j) pairs
 *  - Efficiently computes all `x` results in O(n log n)
 */
========================
ME :
  /*
  solving the following problem with fft
       you have an array a with length n and a[i] is (3 or 2 ) only on of this two values
       and you must answer the following queries
       type 3  , x: count what is the number of pairs of (3 , 3 ) and the distance of them is x in another word (a[i] , a[j]) where a[i]=a[j]=3 and abs(i-j)=x
       type 2  , x: count what is the number of pairs of (2 , 2 ) and the distance of them is x in another word (a[i] , a[j]) where a[i]=a[j]=2 and abs(i-j)=x


       idea is to solve for each number independantly
       if you solve for 3 generate the new array where new_arr[i] = (a[i]==3?1:0)
       form here you can solve it with the pervouis idea of Sum(a[i]*b[i+x])
       make 2 polynomial for each value  +ve (as a in matched idea ) -ve (as b in matched idea)
       and solve it and the answer is ans[shift+x]
       and make the same idea with another value 2

       form this idea now you can find answer of question with realtive distance between to thing in array and this is very important note

       now let's add new type of queres ask for
       type 1 ,x : count what is the number of pairs of (3 , 2 ) and the distance of them is x in another word (a[i] , a[j]) where a[i] 3 ,=a[j]=2 and abs(i-j)=x

       we will use the same idea
       first poly generate from new_arr3 and second form new_arr2 => new_arrY[i] =( 1 if the a[i] = Y )
       and first with +ve powers and second with -ve powers
       if you want number of pairs with (2 , 3) answer in -x make it as query of type 4
*/


/// FFT temp


void solve() {

    int n, q;
    cin >> n;
    vector<int> a(n);
    for(int &i : a)cin>>i;
    vector<int> new_arr2(n),new_arr3( n);
    vector<int> poly2_1(n),poly2_2( n);
    vector<int> poly3_1(n), poly3_2( n);
    vector<int> poly32_1(n), poly32_2( n);
    int shift = n-1;
    for (int i = 0; i < n; ++i) {
        new_arr2[i]=(a[i]==2);
        new_arr3[i]=(a[i]==3);

        poly2_1[i]=new_arr2[i];
        poly2_2[shift-i]=new_arr2[i];

        poly3_1[i]=new_arr3[i];
        poly3_2[shift-i]=new_arr3[i];

        poly32_1[i]=new_arr2[i];
        poly32_2[shift-i]=new_arr3[i];
    }
    auto res2 =multiply(poly2_1 , poly2_2);
    auto res3 =multiply(poly3_1 , poly3_2);
    auto res32 =multiply(poly32_1 , poly32_2);
    cin >> q;
    while (q--) {
        int type,x;
        cin >> type>>x;
        if (x < -shift || x > shift) cout << "0\n";
        else if(type==1) cout << res32[shift + x] << '\n';
        else if(type==4) cout << res32[shift - x] << '\n';
        else if(type==2) cout << res2[shift + x] << '\n';
        else if(type==3) cout << res3[shift + x] << '\n';
    }
    /**
     check with this sample
     5
3 2 3 2 2
8
1 1
1 2
2 1
2 2
3 1
3 2
4 1
4 2
     output
     2
1
1
1
0
1
1
0


     */
}
