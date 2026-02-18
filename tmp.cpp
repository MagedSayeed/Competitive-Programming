MATH(EXPR stack_size "1024 * 1024 * 1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
cmake_minimum_required(VERSION 3.26)
=================

#include <bits/stdc++.h>
/// لتكن مشيئتك
#define int long long
#define endl  "\n"
using namespace std;

void solve() {
  

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        solve();
        cout << "\n";

    }
}
