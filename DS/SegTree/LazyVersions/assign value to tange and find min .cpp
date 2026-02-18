
   ////// assign value v to all elements on the segment from l to r−1
   //find the minimum on the segment from l to r−1

   struct segTree{
       ll sz ;
       vector<ll>seg,lazy;
   public:
       segTree(ll n ){
           sz=1;
           while(sz<n)sz*=2;
           seg=vector<ll>(sz*2,0LL);
           lazy=vector<ll>(sz*2,-1LL);

       }
       void update (int l , int r , int v){
           update(l,r,v,0,0,sz-1);
       }
       ll query(int l , int r){
           return query(l,r,0,0,sz-1);
       }
   private:

       ll op (ll x , ll y ){
           return min(x,y);
       }
       void apply (int x , int lx , int rx){
           if(lazy[x]==-1) return;
           if(lx!=rx){
               lazy[x * 2 + 1] = lazy[x];
               lazy[x * 2 + 2] =  lazy[x];
           }
           seg[x] = (lazy[x] ) ;
           lazy[x]=-1;
       }
       void update (int l , int r , int v , int x , int lx , int rx){
           apply(x,lx,rx);
           if( l<= lx && rx <=r){
               lazy[x]= v ;
               apply(x,lx,rx);
               return;
           }
           if(r < lx || rx < l ) return;
           ll mid = lx + (rx-lx)/2;
           update(l,r,v,2*x+1,lx,mid);
           update(l,r,v,2*x+2,mid+1,rx);
           seg [x] =
                   op(seg[2*x+1],seg[2*x+2]);
       }
       ll query (int l , int r , int x , int lx , int rx){
           apply(x,lx,rx);
           if(l<=lx && rx<=r ){
               return seg[x];
           }
           if(r < lx || rx < l ) return LONG_LONG_MAX;
           ll mid = lx + (rx-lx)/2;
           return
                   op(query(l , r ,2*x+1 ,lx ,mid),
                      query(l ,r ,2*x+2 , mid+1 ,rx))
                   ;
       }

   };
