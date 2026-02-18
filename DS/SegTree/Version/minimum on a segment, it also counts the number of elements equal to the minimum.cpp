
 ////////////   minimum on a segment, it also counts the number of elements equal to the minimum.
 struct SegmantTree{
     struct node {
         ll item , freq;
         node(){
             item = mod;
             freq=0;
         }
     }ignore;
     ll sz =0;
     vector<node>seg;
 public:
     SegmantTree (ll n ){
         sz=1;
         while(sz<n)sz*=2;
         seg=vector<node>(2*sz);
     }
     void update(int i , int v){
         update(i,v,0,0,sz-1);
     }
     node query(int l , int r){
         return query(l,r,0,0,sz-1);
     }
 private:
     node op (node a , node b){
         node tmp;
         tmp.item=min(a.item,b.item);
         tmp.freq=0;
         tmp.freq+=(a.item==tmp.item?a.freq:0);
         tmp.freq+=(b.item==tmp.item?b.freq:0);
         return tmp;

     }
     void update(int i , int v , int x , int lx , int rx){
         if(lx==rx){
             seg[x].item=v;
             seg[x].freq=1;
             return;
         }
         int mid = lx+(rx-lx)/2;
         if(i<=mid){ /// go left
             update(i,v,2*x+1,lx,mid);
         }
         else{ /// go right
             update(i,v,2*x+2,mid+1,rx);
         }
         seg[x]=op(seg[2*x+1],seg[2*x+2]);
     }
     node query(int l , int r , int x , int lx , int rx){
         if(r< lx or rx < l ) return ignore;
         if(l <= lx and rx <= r ) return seg[x];
         ll mid = lx + (rx-lx)/2;
         return op (
                 query(l,r,2*x+1,lx,mid),
                 query(l,r,2*x+2,mid+1,rx)
         );
     }
 };
