//function (1) find_by_order -> accessing index st[1] return iterator
       // (2) order_of_key  -> (kam rakm asghyr meny)
       // (3) less<int> -> lw sorted asc
       // (4) greater<int> -> lw sorted desc
//ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<>,  rb_tree_tag,tree_order_statistics_node_update>

//ordered_multiset -> el erase m4 shaghala
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
#define ordered_multiset tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>

//ordered_set -> b5aly feha dup 3ady 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<>,  rb_tree_tag,tree_order_statistics_node_update>



