//function (1) find_by_order -> accessing index st[1]
       // (2) order_of_key  -> (kam rakm asghyr meny)

//ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>,  rb_tree_tag,tree_order_statistics_node_update>

//ordered_multiset
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
#define ordered_multiset tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>
