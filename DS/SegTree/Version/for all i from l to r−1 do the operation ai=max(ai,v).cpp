
   ///// for all i from l to r−1 do the operation ai=max(ai,v)
   //, find the current value of element i
   struct SegmentTree{
       int sz ;
       vector<ll>seg;
   public:
       SegmentTree (int  n ){
           sz=1;
           while(sz<n)sz*=2;
           seg=vector<ll>(sz*2);
       }
       int query (int i){
           return query(i,0,0,sz-1);
       }
       void update (int l , int r , ll v){
           update(l,r,v,0,0,sz-1);
       }

   private:

       int query(int i , int x , int lx , int rx){
           if(lx==rx) return seg[x];
           ll mid = lx + (rx-lx)/2;
           if(i<=mid)
               return max(seg[x], query(i,2*x+1,lx,mid));
           return max(seg[x], query(i,2*x+2,mid+1,rx));
       }
       void update( int l , int r , ll v , int x,int lx , int rx){
           if(r < lx || rx < l  ) return;
           if(l <= lx && rx<=r) {
               seg[x] =max( v,seg[x]);
               return;
           }
           ll mid = lx + (rx-lx)/2;
           update(l,r,v,2*x+1,lx,mid);
           update(l,r,v,2*x+2,mid+1,rx);
       }
   };
