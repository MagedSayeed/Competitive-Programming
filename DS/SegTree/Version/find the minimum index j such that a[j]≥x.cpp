   ///// 1 i
   // v
   //: change the item with index i to v (0≤i<n0≤v≤109
   //2 x find the minimum index j such that a[j]≥x If there is no such element, print −1
   struct SegmentTree{
       int sz;
       vector<int>seg;
   public:
       SegmentTree(int n ){
           sz=1;
           while (sz<n)sz*=2;
           seg=vector<int>(sz*2);
       }
       void update(int i , int v){
           update(i,v,0,0,sz-1);
       }
       int query(int k){
           if(seg[0]<k)return -1;
           return query(k,0,0,sz-1);
       }
   private:
       int op(int a, int b){
           return max(a,b);
       }
       void update(int i , int v , int x , int lx , int rx){
           if(lx==rx){
               seg[x]=v;
               return;
           }
           int mid = lx + (rx-lx)/2;
           if(i<=mid)
               update(i,v,2*x+1,lx,mid);
           else
               update(i,v,2*x+2,mid+1,rx);
           seg[x]=op(seg[x*2+1],seg[x*2+2]);
       }
       int query(int k , int x , int lx,int rx){
           if(lx==rx){
               return (lx);
           }
           int lft = seg[2*x+1],rt=seg[2*x+2],mid=lx+(rx-lx)/2;
           if(lft>=k)
               return query(k,2*x+1,lx,mid);
           return query(k,2*x+2,mid+1,rx);
       }
   };
