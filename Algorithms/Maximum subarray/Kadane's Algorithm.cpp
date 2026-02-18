/// Without Update

int maxSubarraySum(const vector<int> &a) {
    //// Finds the maximum subarray sum in `a` (Kadane's Algorithm) => handles the + case
    //// 
    //// If you want to find the absolute value of the most negative subarray sum (i.e., the most negative segment in `a`):
    ////     - Create a new array a_neg where a_neg[i] = -a[i]
    ////     - Then call this function with a_neg
    ////     - The result will be equal to abs(minimum subarray sum of the original `a`)
    ////     - So it effectively gives the max of -ve segment sums in original array
    int sum = 0, ans = LLONG_MIN;
    for (const int &i : a) {
        sum += i;
        ans = max(ans, sum);
        sum = max(sum, 0LL);
    }
    return ans;
}
