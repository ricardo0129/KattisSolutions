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
template<class T> 
struct Point{
    typedef Point P;
    T x,y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator < (P p) const {return tie(x,y) < tie(p.x,p.y);}
    bool operator == (P p) const {return tie(x,y) == tie(p.x,p.y);}
    P operator - (P p) const {return P(x-p.x,y-p.y);}
    T cross(P p) const {return x*p.y-y*p.x;}
    T cross(P a, P b) const {return (a-*this).cross(b-*this);}
    double dist() const {return sqrt((double)dist2());}
    T dist2() const {return x*x+y*y;}
};
typedef Point<ll> P;
vector<P> convexHull(vector<P> pts){
    sort(all(pts));
    vector<P> h(sz(pts)+1);
    int s = 0, t = 0;
    for(int it=2;it--; s=--t, reverse(all(pts))){
        for(P p: pts){
            while(t>=s+2 && h[t-2].cross(h[t-1],p)<=0) t--;
            h[t++] = p;
        }
    }
    return {h.begin(),h.begin()+t-(t==2 && h[0]==h[1])};
}
template<class P>
double lineDist(const P& a, const P& b, const P& p){
    return abs((double)(b-a).cross(p-a)/(b-a).dist());
}
int n,r;
int add(int i){
    return (i+1)%n;
}

int main()
{
    cin>>n>>r;
    vector<P> candles;
    FOR(i,n){
        int x,y;
        cin>>x>>y;
        candles.pb(P(x,y));
    }
    vector<P> hull = convexHull(candles);
    //for(P p:hull) cout<<p.x<<" "<<p.y<<endl;
    n = hull.size();
    double best = 1e17;
    if(n<=2) best = 0;
    int j = 0;
    if(n>=3)
    FOR(i,n){
        //we can just use two pointers to find the biggest difference 
        while(lineDist(hull[i],hull[add(i)],hull[j])<=lineDist(hull[i],hull[add(i)],hull[add(j)]) && j<n){
            j = add(j);
        }
        best = min(best,lineDist(hull[i],hull[add(i)],hull[j]));
    }
    printf("%.16lf\n",best);

    return 0;
}
