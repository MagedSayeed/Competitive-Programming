
   /// 1 l r flip all Si such that (l≤i≤r)
   //2 l r how many ones in the substring S[l...r]

   struct SegmentTree{
       vector<ll>seg,lazy;
       ll sz ;
       SegmentTree ( ll n  , string s ){
           sz=1;
           while (sz<n)sz*=2;
           seg.resize(sz*2,0);
           lazy.resize(sz*2,0);
           build(n,0,0,sz-1,s);
       }

       void update_range(ll l , ll r){
           update_range(l,r,0,0,sz-1);
       }
       ll query(ll l , ll r){
           return query(l,r,0,0,sz-1);
       }
       void apply(ll x , ll lx , ll rx){
           if(lazy[x]==0)return;
           if(lx!=rx){
               lazy[2*x+1]^=1;
               lazy[2*x+2]^=1;
           }
           seg[x]=(rx-lx+1)-seg[x];
           lazy[x]=0;
       }
       void build (ll n ,ll x , ll lx , ll rx  , string & s ){
           if (lx == rx) {
               if (rx < n) {
                   seg[x] = s[lx] -'0';
               }
               return;
           }
           int m = (lx+rx)>>1;
           build(n,2*x+1,lx,m,s) ;
           build(n,2*x+2,m+1,rx,s) ;
           seg[x]=seg[2*x+1]+seg[2*x+2];

       }
       void update_range(ll l , ll r ,ll x , ll lx , ll rx){
           apply(x,lx,rx);
           if(l<=lx && rx<=r){
               lazy[x]=1;
               apply(x,lx,rx);
               return;
           }
           if (r < lx || rx < l)return;
           int m = (rx + lx) >> 1;
           update_range(l, r, x * 2 + 1, lx, m);
           update_range(l, r, x * 2 + 2, m + 1, rx);
           seg[x]=seg[2*x+1]+seg[2*x+2];

       }
       ll query ( ll l , ll r ,ll x , ll lx , ll rx){
           apply(x,lx,rx);
           if (r < lx || rx < l)return 0;
           if(l<=lx && rx<=r) return seg[x];
           int m = (rx + lx) >> 1;
           return (query(l, r, x * 2 + 1, lx, m) + query(l, r, x * 2 + 2, m + 1, rx));
       }

   };
