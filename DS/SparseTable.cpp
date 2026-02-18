
struct sparseTable{
public:
    sparseTable(vector<ll> &arr){
        sp.resize(arr.size() , vector<ll>(mxBit+1));
        for(ll i = 0 ; i < arr.size() ; i++)
            sp[i][0] = arr[i];
        for(ll bit = 1 ; bit < mxBit+1 ; bit++){
            for(ll i = 0 ; i + (1<<bit) <= arr.size() ; i++){
                sp[i][bit] = sp[i][bit-1] | sp[i+(1<<(bit-1))][bit-1];
            }
        }
        lg.resize(arr.size()+5);
        lg[1] = 0;
        for(int i = 2 ; i < arr.size()+5 ; i++)
            lg[i] = lg[i/2] + 1;
    }
    ll query(int l , int r){
        ll j = lg[r-l+1];
        return sp[l][j] | sp[r-(1<<j)+1][j];
    }
private:
    const int mxBit = 22;
    vector<vector<ll>> sp;
    vector<int> lg;
};
