//////////////////////////////////////  TRANSFORMIONS   //////////////////////////////////////
pt translate(pt v, pt p) { return p + v; }
// scale point p by a factor around c
pt scale(pt c, T factor, pt p) {
    return c + (p-c)*factor;
}
 
//To rotate point p by a certain angle ϕ around center c
pt rot(pt p, pt c, ld a) {
    pt v = p - c;
    return {c.x +v.x*cos(a) - v.y*sin(a), c.y + v.x*sin(a) + v.y*cos(a)};
}
 
//point p has image fp, point q has image fq then what is image of point r
pt linearTransfo(pt p, pt q, pt r, pt fp, pt fq) {
    pt pq = q-p, num{cross(pq, fq-fp), dot(pq, fq-fp)};
    return fp + pt{cross(r-p, num), dot(r-p, num)} / sq(pq);
}



 

 

