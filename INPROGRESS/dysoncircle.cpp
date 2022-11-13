#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;
template<class T>
struct Point {
typedef Point P;
T x, y;
explicit Point(T x=0, T y=0) : x(x), y(y) {}
bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
P operator+(P p) const { return P(x+p.x, y+p.y); }
P operator-(P p) const { return P(x-p.x, y-p.y); }
P operator*(T d) const { return P(x*d, y*d); }
P operator/(T d) const { return P(x/d, y/d); }
T dot(P p) const { return x*p.x + y*p.y; }
T cross(P p) const { return x*p.y - y*p.x; }
T cross(P a, P b) const { return (a-*this).cross(b-*this); }
T dist2() const { return x*x + y*y; }
double dist() const { return sqrt((double)dist2()); }
// angle to x−axis in interva l [−pi , pi ]
double angle() const { return atan2(y, x); }
P unit() const { return *this/dist(); } // makes d is t ()=1
P perp() const { return P(-y, x); } // rotates +90 degrees
P normal() const { return perp().unit(); }
// returns point rotated ’a ’ radians ccw around the origin
P rotate(double a) const {
return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
friend ostream& operator<<(ostream& os, P p) {
return os << "(" << p.x << "," << p.y << ")"; }
};
typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
if (sz(pts) <= 1) return pts;
sort(all(pts));
vector<P> h(sz(pts)+1);
int s = 0, t = 0;
for (int it = 2; it--; s = --t, reverse(all(pts)))
for (P p : pts) {
while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
h[t++] = p;
}
return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}
int main()
{
    int n;
    cin>>n;
    vector<P> points;
    FOR(i,n){
        int x,y;
        cin>>x>>y;
        points.pb(P(x,y));
    }
    vector<P> hull = convexHull(points);
    n = hull.size();
    cout<<n<<endl;
    ll ans = 3*n;
    FOR(i,n){
       int v = max(abs(hull[i].x-hull[(i+1)%n].x),abs(hull[i].y-hull[(i+1)%n].y));
       int u = min(abs(hull[i].x-hull[(i+1)%n].x),abs(hull[i].y-hull[(i+1)%n].y));
       ans+=v-2;

    }
    cout<<ans<<endl;

    return 0;
}
