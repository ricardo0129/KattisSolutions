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

template<class T> int sgn(T x) { return (x>0) - (x<0) ; }
template<class T>
struct Point{
    typedef Point P;
    T x,y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y)<tie(p.x,p.y); }
    bool operator>(P p) const { return tie(x,y)>tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x,y+p.y); }
    P operator-(P p) const { return P(x-p.x,y-p.y); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y-y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); } 
};

template<class P> bool onSegment(P s, P e, P p){
    return p.cross(s,e)==0 && (s-p).dot(e-p)<=0;
}
typedef Point<ll> P;
vector<P> convexHull(vector<P> pts){
    sort(all(pts));
    vector<P> h(sz(pts)+1);
    int s = 0, t = 0;
    for(int it=2;it--;s=--t,reverse(all(pts)))
        for(P p: pts){
            while(t>=s+2 && h[t-2].cross(h[t-1],p)<=0) t--;
            h[t++] = p;
        }
    return {h.begin(),h.begin()+t-(t==2 && h[0]==h[1])};
}
template<class P> 
int sideOf(P s, P e, P p) { return sgn(s.cross(e,p)); } 
bool inHull(const vector<P>& l, P p, bool strict = false){
    int a = 1, b = sz(l)-1, r = !strict;
    if(sz(l)<3) return r && onSegment(l[0],l.back(),p);
    if(sideOf(l[0],l[a],l[b]) > 0) swap(a,b);
    if(sideOf(l[0],l[a],p) >= r || sideOf(l[0],l[b],p)<=-r)
        return false;
    while(abs(a-b)>1){
        int c = (a+b)/2;
        (sideOf(l[0],l[c],p)>0 ? b : a) = c;
    }
    return sgn(l[a].cross(l[b],p))<r;

}
int main()
{
    int l;
    scanf("%d", &l);
    vector<P> large,small;
    FOR(i,l){
        int x,y;
        scanf("%d %d", &x, &y);
        large.pb(P(x,y));
    }
    int s;
    scanf("%d", &s);
    FOR(i,s){
        int x,y;
        scanf("%d %d", &x, &y);
        small.pb(P(x,y));
    }
    vector<P> hull = convexHull(large);
    int ans = 0;
    for(P p: small){
        ans+=inHull(hull,p);
    }
    printf("%d\n",ans);
    
    return 0;
}
