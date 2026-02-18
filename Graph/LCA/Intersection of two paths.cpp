int dis(int a, int b)
{
    int lc = LCA(a, b);
    return depth[a] + depth[b] - depth[lc] * 2;
}
/// x to z intersection y to z
int calc(int x, int y, int z)
{
    return (dis(x, z) + dis(y, z) - dis(x, y)) / 2 + 1;
}
 // dist from ((a to c) + (b to c)) -(a to b)
