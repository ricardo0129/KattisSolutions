#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)

const double PI = acos(-1);
double EPS = 1e-7;
struct point { double x, y;
point() { x = y = 0.0; }
point(double _x, double _y) : x(_x), y(_y) {} };
double dist(point p1, point p2) {
return hypot(p1.x - p2.x, p1.y - p2.y); }
struct vec { double x, y; // name: ‘vec’ is different from STL vector
vec(double _x, double _y) : x(_x), y(_y) {} };
vec toVec(point a, point b) {
return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) {
return vec(v.x * s, v.y * s); }
point translate(point p, vec v) {
return point(p.x + v.x , p.y + v.y); }
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
double distToLine(point p, point a, point b, point &c) {
vec ap = toVec(a, p), ab = toVec(a, b);
double u = dot(ap, ab) / norm_sq(ab);
c = translate(a, scale(ab, u));
return dist(p, c); }
double distToLineSegment(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) { c = point(a.x, a.y);
	return dist(p, a); }
	if (u > 1.0) { c = point(b.x, b.y);
	return dist(p, b); }
	return distToLine(p, a, b, c); 
}
vector<point> polygon;
double angle(point a, point o, point b) { // returns angle aob in rad
vec oa = toVec(o, a), ob = toVec(o, b);
return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
bool ccw(point p, point q, point r) {
return cross(toVec(p, q), toVec(p, r)) > 0; }
bool inPolygon(point pt, const vector<point> &P) {
if ((int)P.size() == 0) return false;
double sum = 0;
// assume the first vertex is equal to the last vertex
for (int i = 0; i < (int)P.size(); i++) {
if (ccw(pt, P[i], P[(i+1)%P.size()]))
sum += angle(P[i], pt, P[(i+1)%P.size()]);
// left turn/ccw
else sum -= angle(P[i], pt, P[(i+1)%P.size()]); }
// right turn/cw
return fabs(fabs(sum) - 2*PI) < EPS; }

double solve(point p){
	double ans = 1e9;
	FOR(i,polygon.size()){
		point a = polygon[i];
		point b = polygon[(i+1)%polygon.size()];
		point c;
		double val = distToLineSegment(p,a,b,c);
		ans = min(ans,val);
	}
	return ans;
}

int main()
{
	int t = 1;
	while(true){
		int n;
		cin>>n;
		if(n==0) break;
		polygon.clear();
		FOR(i,n){
			int x,y;
			cin>>x>>y;
			polygon.pb(point(x,y));
		}
		int q;
		cin>>q;
		printf("Case %d\n",t++);
		FOR(i,q){
			int x,y;
			cin>>x>>y;
			point p(x,y);
			double d=solve(p);
			bool inside = inPolygon(p,polygon);
			if(abs(d)<=EPS) printf("Winged!\n");
			else if(inside) printf("Hit! %.8lf\n",d);
			else printf("Miss! %.8lf\n",d);
		}

	}
	return 0;
}
