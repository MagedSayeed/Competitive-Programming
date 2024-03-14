int merge(int i, int j)
{
    return (i + j);
}
void build(const vector<int> &arr)
{

    SP.resize(__lg(a) + 1, arr);
    SP[0] = arr;
    for (int msk = 1; msk < SP.size(); msk++)
    {

        for (int ind = 0; ind <= a - (1 << msk); ind++)
        {
            int v1 = SP[msk - 1][ind];
            int v2 = SP[msk - 1][ind + (1 << (msk - 1))];
            SP[msk][ind] = merge(v1, v2);
        }
    }
}
