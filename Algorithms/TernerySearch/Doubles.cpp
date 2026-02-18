double ternary_search(double l = 0, double r = 1e14)///1st version
{
    double eps = 1e-9;//set the error limit here
    int iterations = 300;
    for (int i = 0; i < iterations  && l + eps < r; ++i){
        double md1 = l + (r - l) / 3;
        double md2 = r - (r - l) / 3;
        if (ok(md1) < ok(md1))
            l = md1;
        else
            r = md2;
    }
    return ok(l);
}
