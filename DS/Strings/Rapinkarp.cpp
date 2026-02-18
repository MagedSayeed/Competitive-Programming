
//// https://cses.fi/problemset/task/1753/ -> problem 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/**
 *    "وَلْيَعْلَمُوا أَنَّ هذِهِ هِيَ يَدُكَ. أَنْتَ يَا رَبُّ فَعَلْتَ هذَا." (مز 109: 27).
**/

#pragma clang diagnostic push
int power(int a, int p, int Mod) {
    if (!p)return 1;
    int res = power(a, p / 2, Mod);
    res = res * res % Mod;
    if (p & 1)res = res * a % Mod;
    return res;
}

void pushBack(int &h, int v, int base, int Mod) {
    h = h * base % Mod;
    h = (h + v) % Mod;
}

void pushFront(int &h, int v, int i, int base, int Mod) {
    v = v * power(base, i, Mod) % Mod;
    h = (h + v) % Mod;
}

void popBack(int &h, int v, int base, int Mod) {
    h = (h - v + Mod) % Mod;
    h = h * power(base, Mod - 2, Mod) % Mod;
}

void popFront(int &h, int v, int i, int base, int Mod) {
    v = v * power(base, i, Mod) % Mod;
    h = (h - v + Mod) % Mod;
}

void smsm() {
    string s, t;
    cin >> s >> t;
    if (t.size() > s.size()) {
        cout << 0;
        return;
    }
    if (t.size() == s.size()) {
        cout << (s == t);
        return;
    }
    int len = t.size(), Hash1{}, Hash2{}, pattern1{}, pattern2{}, B = 31, m1 = 1e9 + 9, B2 = 37, m2 = 1e9 + 19;
    for (int i = 0; i < len; ++i) {
        pushBack(Hash1, s[i] - 'a' + 1, B, m1);
        pushBack(pattern1, t[i] - 'a' + 1, B, m1);
        pushBack(Hash2, s[i] - 'a' + 1, B2, m2);
        pushBack(pattern2, t[i] - 'a' + 1, B2, m2);
    }
    int ans = (Hash1 == pattern1 and Hash2 == pattern2);
    int l = 0, r = len;
    while (r < s.size()) {
        popFront(Hash1, s[l] - 'a' + 1, len - 1, B, m1);
        pushBack(Hash1, s[r] - 'a' + 1, B, m1);
        popFront(Hash2, s[l] - 'a' + 1, len - 1, B2, m2);
        pushBack(Hash2, s[r] - 'a' + 1, B2, m2);
        ans += (Hash1 == pattern1 and Hash2 == pattern2);
        l++, r++;
    }
    cout << ans;

}
