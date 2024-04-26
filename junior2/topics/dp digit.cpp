int s(int i, bool upper, bool lower, bool zero)
{
    if (i == R.size())
    {
        return 1;
    }
    int &ret = dp[i][upper][lower][zero];
    if (~ret)
        return ret;
    ret = 0;
    // lower bool : to know if im bigger than smallest
    // number so that i can put from 0
    int L_LIMIT = (lower ? 0 : L[i]);
    // upper bool : to know if im smaller than biggest
    // number so that i can put till 9
    int R_LIMIT = (upper ? 9 : R[i]);
    for (int d = L_LIMIT; d <= R_LIMIT; d++)
    {
        int cur = (zero || d ? d : 1);
        ret = max(ret, cur *
                           s(i + 1,upper or (d < R[i]),lower or d > L[i],zero or d));
    }
    return ret;
}
