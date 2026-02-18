
 // assign value v to all elements on the segment from l to r−1
   // find the current value of element i
 struct SegmentTree{
#define ll pair<int , int>

     int sz ,timer;
     vector<ll>seg;
 public:
     SegmentTree (int  n ){
         sz=1;
         while(sz<n)sz*=2;
         seg=vector<ll>(sz*2);
     }
     int query (int i){
         return query(i,0,0,sz-1).second;
     }
     void update (int l , int r , int v){
         ++timer;
         update(l,r,v,0,0,sz-1);
     }

 private:

     ll query(int i , int x , int lx , int rx){
         if(lx==rx) return seg[x];
         int mid = lx + (rx-lx)/2;
         if(i<=mid)
             return max(seg[x], query(i,2*x+1,lx,mid));
         return max(seg[x], query(i,2*x+2,mid+1,rx));
     }
     void update( int l , int r , int v , int x,int lx , int rx){
         if(r < lx || rx < l  ) return;
         if(l <= lx && rx<=r) {
             seg[x] ={timer,v};
             return;
         }
         int mid = lx + (rx-lx)/2;
         update(l,r,v,2*x+1,lx,mid);
         update(l,r,v,2*x+2,mid+1,rx);
     }

#undef ll pair<ll , ll>
 };
