//The Convex Hull Trick is a technique used to optimize a set of linear functions of the form:
//  y= m⋅x+bi
//It helps you:
//    Efficiently find the minimum or maximum value of these lines at a given x
//    Especially useful when:
//        You're querying many values of x
//        Lines are added in order (e.g., slope m_i is increasing or decreasing)

typedef long long ll;
#define int ll
const ll is_query = -(1LL<<62);
struct line {
    long double m, b;
    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        long double x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
 
struct dynamic_hull : public multiset<line> {
    const ll inf = LLONG_MAX;
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
 
        /* compare two lines by slope, make sure denominator is not 0 */
        long double v1 = (x->b - y->b);
        if (y->m == x->m) v1 = x->b > y->b ? inf : -inf;
        else v1 /= (y->m - x->m);
        long double v2 = (y->b - z->b);
        if (z->m == y->m) v2 = y->b > z->b ? inf : -inf;
        else v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    //Inserts a new line y = m*x + b into the hull.
    void insert_line(long double m, long double b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    //Finds the value of the best maximum line at a given x
    // What if I want the minimum value? // insert_line(-m, -b) -> returned value will be in negative remember to use it with - 
    long double eval(long double x) {
        auto l = *lower_bound((line) { x, is_query });
        return l.m * x + l.b;
    }
};
