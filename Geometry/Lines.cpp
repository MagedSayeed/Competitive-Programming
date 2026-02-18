//////////////////////////////////////////  LINES   //////////////////////////////////////////
 
struct line {
//v=(b,- a) , c=cross(v,p)
    pt v; T c;
 
// From direction vector v and offset c
    line(pt v, T c) : v(v), c(c) {}
 
// From equation ax+by=c
    line(T a, T b, T _c){
        v = {b,-a};
        c = _c;
    }
 
// From points P and Q
    line(pt p, pt q){
        v = q-p, c = cross(v,p);
    }
 
// - these work with T = int
    T side(pt p) {return cross(v,p)-c;}
    double dist(pt p) {return abs(side(p)) / abs(v);}
    double sqDist(pt p) {return side(p)*side(p) / (T)sq(v);}
    line perpThrough(pt p) {return {p, p + perp(v)};}
    bool cmpProj(pt p, pt q) {
        return dot(v,p) < dot(v,q);
    }
    line translate(pt t) {return {v, c + cross(v,t)};}
 
// - these require T = double
    line shiftLeft(double dist) {return {v, c + dist*abs(v)};}
    pt proj(pt p) {return p - perp(v)*side(p)/sq(v);}
    pt refl(pt p) {return p - perp(v) * (T)2.0 * side(p)/sq(v);}
};
 
//Two lines Intersection
bool inter(line l1, line l2, pt &out) {
    T d = cross(l1.v, l2.v);
    if (fabs(d) <= EPS) return false;
    out = (l2.v*l1.c - l1.v*l2.c) / d; // requires floating-point coordinates
    return true;
}
 
//Bisector of Two lines (interior da hatl)
line bisector(line l1, line l2, bool interior) {
    assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
    T sign = interior ? 1 : -1;
    return {l2.v/(T)abs(l2.v) + l1.v/(T)abs(l1.v) * sign,
            l2.c/abs(l2.v) + l1.c/abs(l1.v) * sign};
}
