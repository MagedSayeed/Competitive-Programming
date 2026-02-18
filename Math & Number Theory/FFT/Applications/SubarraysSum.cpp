
with this apporach you can find the count of subarrays have sum X 

/**
    how to solve this problem with fft
    count all sub arrays sums
    this problem can be solved if summation over all array is less than 1e5
    first make prefix sum on array
    poly1 = Sum(freq[pref[i]] * x(pref[i]))
    poly2 = Sum(freq[pref[i]] * x(- pref[i] + shift))
    to generate all diffraces of prefixes to get summation of subarrays with this diffrence

    but take care of this note
    if we need pref[j]-pref[i] must this condition equal true j>=i the fft don't handel this it use any i with any j

    if(a[i]>=0){
        the valid diffrance is the postive diffrence or diffrence =0;
        the postive the fft calculate it correctly
        but the 0 doesn't calculated correctly
        the 0 must be counted without fft as a new subproplem
        count number of subarrays with sum =0
         map<int , int>mp;
         int sm=0 , ans=0;
         for(int i : a)
            sm+=i;
            ans+=mp[sm];
            mp[sm]++;
         }
 */
/// mul to polynomyal => without mod ( double in deep take care )

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

vector<int> multiply(vector<int> const& a, vector<int> const& b , int limit) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int) a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false );
    fft(fb, false  );
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true  );
    n=min(n , limit);
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // Compute prefix sums and track min/max
    vector<long long> pref(n+1, 0);
    long long mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + a[i];
        mn = min(mn, pref[i+1]);
        mx = max(mx, pref[i+1]);
    }

    // Shift to make all indices non-negative
    int shift = (int)(1e5);
    int range = (int)(mx - mn) ;
    int limit = 2 * shift + range;   // possible conv size
    vector<long long> freq1(limit, 0), freq2(limit, 0);
    for (long long v : pref) {
        freq1[v ]++;
        freq2[shift - v]++;
    }
    // FFT convolution
    auto conv = multiply(freq1, freq2, limit);

    // Handle zero-sum subarrays separately (count pref[j] == pref[i], j > i)
    long long zero_count = 0;
    unordered_map<long long,int> mp;
    for (long long v : pref) {
        zero_count += mp[v];
        mp[v]++;
    }
    int res=zero_count;
    for (long long S = 1; S <= shift; S++) {
        long long cnt = 0;
        int idx = (int)(S + shift);
        if (idx >= 0 && idx < (int)conv.size()) {
            cnt = conv[idx];
        }
        if(cnt)
        res+=S*cnt;
    }
    cout<<res;
}
