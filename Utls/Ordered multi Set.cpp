https://codeforces.com/blog/entry/88193

Properties:

Operation -> O(Log^2(n))

Declaration:

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;    
#define ordered_multiset tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>

orderd_multiset os;

Notes:

1 - Upper_bound and lower_bound exchange their functions
2 – Before using the built_in erase make sure the element is in the set using exist() user defined function

Function: (same functions from set) +

os.order_of_key (k) : Number of items strictly smaller than k .
*os.find_by_order(k) : K-th element in a set (counting from zero).
s.erase(s.upper_bound(k)) : erase one occurrence of k

User defined functions:

bool exist(ordered_multiset &s, int x){ //checks the existence of x in the set
    return (s.upper_bound(x) != s.end() && *s.upper_bound(x) == x);
}
int firstidx(ordered_multiset &s, int x){ //returns the first index with value x (0 based)
    if(!exist(s, x))
        return -1;
    return (s.order_of_key(x));
}
int lastidx(ordered_multiset &s, int x){ // returns the last index with value x (0 based)
    if(!exist(s, x))
        return -1;
    if(*s.find_by_order((int)s.size() - 1) == x)
        return (int)(s.size()) - 1;
    return firstidx(s,*s.lower_bound(x)) - 1;
}
int Count(ordered_multiset &s, int x){ //returns the number of occurrences of the value x 
    if(!exist(s, x))
        return 0;
    return lastidx(s, x) - firstidx(s, x) + 1;
}
