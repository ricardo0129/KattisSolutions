#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define f first
#define s second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MOD = (int)1e9+7;
template <class T> int sgn(T x){ return (x>0) - (x<0);}
template<class T>
struct Point{
    typedef Point P;
    T x,y;
    explicit Point(T x=0, T y=0): x(x), y(y) {}
    bool operator< (P p) const {return tie(x,y) < tie(p.x,p.y);}
    bool operator== (P p) const {return tie(x,y) == tie(p.x,p.y);}
    P operator+ (P p) const {return P(x+p.x,y+p.y);}
    P operator- (P p) const {return P(x-p.x,y-p.y);}
    T dist2() const {return x*x + y*y;}
};
typedef Point<double> P;
pair<P, P> closest(vector<P> v){
    set<P> S;
    sort(all(v),[](P a, P b){return a.y<b.y;});
    pair<double,pair<P,P>> ret{1e17,{P(),P()}};
    int j=0;
    for(P p: v){
        P d{(double)(1+sqrt(ret.first)),0};
        while(v[j].y<=p.y-d.x)S.erase(v[j++]);
        auto lo = S.lower_bound(p-d),hi = S.upper_bound(p+d);
        for(;lo!=hi;lo++)
            ret = min(ret, {(*lo - p).dist2(), {*lo, p}});
        S.insert(p);
    }
    return ret.second;
}
int main()
{
    while(true){
        int n;
        cin>>n;
        if(n==0) break;
        vector<P> points;
        FOR(i,n){
            double x, y;
            cin>>x>>y;
            points.pb(P(x,y));
        }
        pair<P, P> ans = closest(points);
        printf("%.2lf %.2lf %.2lf %.2lf\n",ans.f.x,ans.f.y,ans.s.x,ans.s.y);
    } 
    return 0;
}
