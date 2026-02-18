/**
You are given k distinct prime numbers a_1,a_2,\ldots,a_k and an integer n.
Your task is to calculate how many of the first n positive integers are divisible by at least one of the given prime numbers.

**/
int n; /// range 
const int sz=20; /// number of primes -> 
int primes[sz];

int inc_exe(int idx = 0, __int128 d = 1, int sign = -1) {
    if (d > n)return 0;
    if (idx == sz) {
        if (d == 1)
            return 0;
        return sign * (n / d);
    }
    return inc_exe(idx + 1, d, sign) +
           inc_exe(idx + 1, d * primes[idx], sign * -1);
}
