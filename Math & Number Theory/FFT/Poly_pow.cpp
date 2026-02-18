vector<int>poly_mod(vector<int>p , int k){
    vector<int>ret{1};
    while (k){
        if(k&1)ret= multiply(ret , p);
        p= multiply(p , p);
        k/=2;

    }
    return ret;
}
