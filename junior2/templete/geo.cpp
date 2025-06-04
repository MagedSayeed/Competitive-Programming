typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()
#define PI acos(-1.0)
arg(Point) => angle [-PI,PI]
T dot(pt v, pt w) {return (conj(v)*w).x;}
T cross(pt v, pt w) {return (conj(v)*w).y;}
