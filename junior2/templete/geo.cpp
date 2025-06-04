typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()
#define PI acos(-1.0)
arg(Point) // return an angle [-PI,PI]
T dot(pt v, pt w) {return (conj(v)*w).x;} //how similar their directions are : returns 0 if to vectors are perpendiculer
double angle(pt v, pt w) {return acos(clamp(dot(v,w) / abs(v) / abs(w), -1.0, 1.0));} // returns angle between two vectors
T cross(pt v, pt w) {return (conj(v)*w).y;} //measure of how perpendicular they are : returns 0 if they are aligned
T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}  // determining the relative position of points and other objects (Pos=L,eq=align,neg=R)

