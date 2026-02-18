int pointRay(pt p, pt a, pt b) // a is ray's origin, b defines direction
{
  pt dir = b - a; // ray direction vector
  pt v = p - a;   // vector from origin to point
 
  T u = dot(v, dir);
 
  if (u <= 0) // Point is behind the ray origin
  {
    return abs(v); // distance from p to a
  }
  else // Point is in front of the ray
  {
    // Compute closest point on the ray: a + (u / ||dir||²) * dir
    pt closest = a + (u / norm(dir)) * dir;
    return abs(p - closest); // distance from p to closest point
  }
}
bool segSegIntersect(pt p1, pt p2, pt p3, pt p4)
{
  auto onSegment = [](pt a, pt b, pt c)
  {
    // Checks if c lies on segment ab
    return abs(orient(a, b, c)) < EPS &&
           min(a.x, b.x) - EPS <= c.x && c.x <= max(a.x, b.x) + EPS &&
           min(a.y, b.y) - EPS <= c.y && c.y <= max(a.y, b.y) + EPS;
  };
 
  T d1 = orient(p3, p4, p1);
  T d2 = orient(p3, p4, p2);
  T d3 = orient(p1, p2, p3);
  T d4 = orient(p1, p2, p4);
 
  // Proper intersection
  if (sgn(d1) * sgn(d2) < 0 && sgn(d3) * sgn(d4) < 0)
    return true;
 
  // Colinear & endpoint overlap cases
  if (abs(d1) < EPS && onSegment(p3, p4, p1))
    return true;
  if (abs(d2) < EPS && onSegment(p3, p4, p2))
    return true;
  if (abs(d3) < EPS && onSegment(p1, p2, p3))
    return true;
  if (abs(d4) < EPS && onSegment(p1, p2, p4))
    return true;
 
  return false;
}
 
ld rayRay(pt a, pt b, pt c, pt d)
{
  ld inf = 1e12;
  b = a + (b - a) * inf;
  d = c + (d - c) * inf;
  if (segSegIntersect(a, b, c, d))
    return 0;
  return min({segPoint(a, b, c), segPoint(a, b, d), segPoint(c, d, a), segPoint(c, d, b)});
}
