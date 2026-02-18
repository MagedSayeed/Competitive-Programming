//////////////////////////////////////////  POLYGONS   //////////////////////////////////////////
 
bool isConvex(vector<pt> p) {
    bool hasPos=false, hasNeg=false;
    for (int i=0, n=p.size(); i<n; i++) {
        int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
        if (o > 0) hasPos = true;
        if (o < 0) hasNeg = true;
    }
    return !(hasPos && hasNeg);
}
 
ld areaTriangle(pt a, pt b, pt c) {
    return abs(cross(b-a, c-a)) / 2.0;
}
 
ld areaPolygon(vector<pt> p) {
    ld area = 0.0;
    for (int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i+1)%n]); // wrap back to 0 if i == n - 1
    }
    return abs(area) / 2.0;
}
 
// true if P at least as high as A
bool above(pt a, pt p) {
    return p.y >= a.y;
}
 
// check if [PQ] crosses ray from A
bool crossesRay(pt a, pt p, pt q) {
    return (above(a,q) - above(a,p)) * orient(a,p,q) > 0;
}
 
// if strict, returns false when A is on the boundary
bool inPolygon(vector<pt> p, pt a, bool strict = true) {
    int numCrossings = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        if (onSegment(p[i], p[(i+1)%n], a))
            return !strict;
        numCrossings += crossesRay(a, p[i], p[(i+1)%n]);
    }
    return numCrossings & 1; // inside if odd number of crossings
}
// 1 -> point out of polygon
// 0 -> point on border of polygon
// -1 -> point inside polygon
int inPolygonlg(pt pp, vector<pt> &v) // O(log(N))
{
  int n = v.size();
  int o1 = orient(v[0], v[1], pp);
  int o2 = orient(v[0], v[n - 1], pp);
  if (o1 == 0 && onSegment(v[0], v[1], pp))
    return 0;
  else if (o2 == 0 && onSegment(v[0], v[n - 1], pp))
    return 0;
  else if (o1 < 0 || o2 > 0)
    return 1;
  int l = 0, r = n - 1;
  int ans = 1;
  while (l <= r)
  {
    int mid = l + (r - l) / 2;
    int o = orient(v[0], v[mid], pp);
    if (o > 0)
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  int oo = orient(v[ans], v[(ans + 1) % n], pp);
  if (oo > 0)
    return -1;
  else if (oo == 0 && onSegment(v[ans], v[(ans + 1) % n], pp))
    return 0;
  return 1;
}
 
angle_t  moveTo(angle_t a, pt newD) {
    // check that segment [DD’] doesn’t go through the origin
    assert(!onSegment(a.d, newD, {0,0}));
    angle_t b{newD, a.t};
    if (a.t180() < b) // if b more than half a turn bigger
        b.t--; // decrease b by a full turn
    if (b.t180() < a) // if b more than half a turn smaller
        b.t++; // increase b by a full turn
    return b;
}
 
int windingNumber(vector<pt> p, pt a) {
    double ampli = 0;
    for (int i = 0, n = p.size(); i < n; i++)
        ampli += angleTravelled(a, p[i], p[(i+1)%n]);
    return round(ampli / (2*M_PI));
}
