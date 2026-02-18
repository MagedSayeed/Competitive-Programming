struct BIT
{
    vector<vector<int>> Tree;
    BIT(int a, int b) { Tree.assign(a + 1, vector<int>(b + 1, 0)); }
    void update(int x, int y, int v)
    {
        for (; x < Tree.size(); x += x & -x)
        {
            for (int j = y; j < Tree.size(); j += j & -j)
                Tree[x][j] += v;
        }
    }
    int query(int x, int y)
    {
        int res = 0;
        for (; x > 0; x -= x & -x)
            for (int j = y; j > 0; j -= j & -j)
                res += Tree[x][j];
        return res;
    }
    int query(int sx, int sy, int ex, int ey)
    {
        int res = query(ex, ey);
        res -= query(ex, sy - 1);//left 
        res -= query(sx - 1, ey);//right
        res += query(sx - 1, sy - 1);
        return res;
    }
};
