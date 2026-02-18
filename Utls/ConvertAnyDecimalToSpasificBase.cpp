   auto get_base = [](ll num, ll base)
    {
        vector<ll> digits;
        while (num > 0)
        {
            digits.push_back(num % base);
            num /= base;
        }
        return digits;
    };
