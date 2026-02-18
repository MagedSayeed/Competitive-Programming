   ////// add to the segment from l to r−1 the number v
   //,find the current value of element i
   struct SegmentTree{
       int sz ;
       vector<ll>seg;
   public:
       SegmentTree(int n ){
           sz=1;
           while(sz<n)sz*=2;
           seg=vector<ll>(sz*2,0);
       }
       void update(int i , int v ){
           update(i,v,0,0,sz-1);
       }
       int query(int l , int r){
           return query(l,r,0,0,sz-1);
       }
       void print(){
           for(auto i :seg)cout<<i<<" ";
           cout<<endl;
       }
       void clear (){
           seg=vector<ll>(2*sz,0);
       }
   private:
       ll op (ll lft , ll rt ){
           return lft+rt;
       }
       void update(int i , int v , int x , int lx , int rx  ){
           if(lx==rx){
               seg[x]+=v;
               return;
           }
           int mid = lx + (rx-lx)/2;
           if(i<=mid){
               update(i,v,2*x+1,lx,mid);
           }
           else
               update(i,v,2*x+2,mid+1,rx);
           seg[x]=op(seg[2*x+1],seg[2*x+2]);
       }
       ll query(int l , int r , int x , int lx , int rx){
           if(rx<l or r<lx)return 0;
           if(l<=lx and rx <=r) return seg[x];
           int mid = lx + (rx-lx)/2;
           return op (
                   query(l,r,2*x+1,lx,mid),
                   query(l,r,2*x+2,mid+1,rx)
           );
       }

   };
