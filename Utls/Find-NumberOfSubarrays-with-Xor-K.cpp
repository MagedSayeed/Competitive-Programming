///// try to avoid use map 
//// time is o(n)-> because frq array ! 
///// check the sizw  of frq array .
int NumberOfSubarrays_with_Xor_K(vector<int> &a, int k) {
    int sz = 2e5 + 5;
    int frq[sz]{}; /// ->  sz---> max Value of Xor + 5
    frq[0] = 1;
    int res{}, Xor{};
    for (int i = 0; i < a.size(); ++i) {
        Xor ^= a[i];
        res += frq[Xor ^ k];
        frq[Xor]++;
    }
    return res;
}
