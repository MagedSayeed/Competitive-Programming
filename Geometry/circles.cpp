//////////////////////////////////////////  CIRCLES   //////////////////////////////////////////

// Determining circle center and radius
pair<pt, T> circumCircle(pt a, pt b, pt c) {
    b = b-a, c = c-a; // consider coordinates relative to A
    assert(cross(b,c) != 0); // no circumcircle if A,B,C aligned
    return {a + perp(b*sq(c) - c*sq(b))/cross(b,c)/(T)2, abs(perp(b*sq(c) - c*sq(b))/cross(b,c)/(T)2)};
}

// Return number of points of intersection & out contains the points of intersections 
int circleLine(pt o, double r, line l, pair<pt,pt> &out) {
    double h2 = r*r - l.sqDist(o);
    if (h2 >= 0) { // the line touches the circle
        pt p = l.proj(o); // point P
        pt h = l.v* (T)(sqrt(h2)/abs(l.v)); // vector parallel to l, of length h
        out = {p-h, p+h};
    }
    return 1 + sgn(h2);
}

// Returns number of points intersection & Those points
int circleCircle(pt o1, T r1, pt o2, T r2, pair<pt,pt> &out) {
    pt d=o2-o1; T d2=sq(d);
    if (d2 == 0) {assert(r1 != r2); return 0;} // if two Circles identical
    T pd = (d2 + r1*r1 - r2*r2)/2; // = |O_1P| * d
    T h2 = r1*r1 - pd*pd/d2; // = hˆ2
    if (h2 >= 0) {
        pt p = o1 + d*pd/d2, h = perp(d)*sqrt(h2/d2);
        out = {p-h, p+h};
    }
    return 1 + sgn(h2);
}
 
int tangents(pt o1, T r1, pt o2, T r2, bool inner, vector<pair<pt,pt>> &out) {
    if (inner) r2 = -r2;
    pt d = o2-o1;
    T dr = r1-r2, d2 = sq(d), h2 = d2-dr*dr;
    if (d2 == 0 || h2 < 0) {assert(h2 != 0); return 0;}
    for (T sign : {-1,1}) {
        pt v = (d*dr + perp(d)*sqrt(h2)*sign)/d2;
        out.push_back({o1 + v*r1, o2 + v*r2});
    }
    return 1 + (h2 > 0);
}
