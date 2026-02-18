
 ////// : change the element with index i to the opposite.
   //2 k: find the k-th one (ones are numbered from 0, it is guaranteed that there are enough ones in the array).
 struct SegmantTree{
     ll sz =0;
     vector<ll>seg;
 public:
     SegmantTree (ll n ){
         sz=1;
         while(sz<n)sz*=2;
         seg=vector<ll>(sz*2);
     }
     void update(int i){
         update(i,0,0,sz-1);
     }
     ll query(int k){
         return query(k,0,0,sz-1);
     }
 private:
     ll op (ll a , ll b){
         return a+b;
     }
     void update(int i , int x , int lx , int rx){
         if(lx==rx){
             seg[x]= !seg[x];
             return;
         }
         int mid = lx+(rx-lx)/2;
         if(i<=mid){ /// go left
             update(i,2*x+1,lx,mid);
         }
         else{ /// go right
             update(i,2*x+2,mid+1,rx);
         }
         seg[x]=op(seg[2*x+1],seg[2*x+2]);
     }
     ll query(int k , int x , int lx , int rx){
         if(lx==rx) return lx;

         ll mid = lx + (rx-lx)/2;
         if(seg[2*x+1]>=k){
             return query(k,2*x+1,lx,mid);
         }
         else{
             return query(k-seg[2*x+1],2*x+2,mid+1,rx);
         }
     }
 };
