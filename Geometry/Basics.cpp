
//////////////////////////////////////////  BASICS   //////////////////////////////////////////
#define ld long double
#define EPS 1e-9
typedef ld T;
typedef complex<T> pt;
#define x real()
#define y imag()
 
 
bool operator==(pt a, pt b) {return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;}
bool operator!=(pt a, pt b) {return !(a == b);}
istream &operator>>(istream &in, pt &a)
{
  T real, imag;
  in >> real >> imag;
  a = pt(real, imag);
  return in;
}

int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
 
T sq(pt p) {return p.x*p.x + p.y*p.y;}
 
ld abs(pt p) {return sqrt(sq(p));}
 
pt perp(pt p) {return {-p.y, p.x};}
 
T dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}
 
T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}
 
bool isPerp(pt v, pt w) {return dot(v,w) == 0;}
