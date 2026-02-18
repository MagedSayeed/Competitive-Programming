 int l, r;
    cin >> l >> r;
    auto Xor = [&](int x) -> int {
        if (x % 4 == 0)return x;
        if (x % 4 == 1)return 1;
        if (x % 4 == 2)return x + 1;
        if (x % 4 == 3)return 0;
    };
    if (l)
        cout << (Xor(r) ^ Xor(l - 1));
    else
        cout << Xor(r);
