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

template <class T> int sgn(T x) { return (x>0) - (x<0); }

template <class T> 
struct Point{
    typedef Point P;
    T x,y;
    explicit Point( T x=0, T y = 0) : x(x), y(y) {}
    P operator- (P p) const { return P(x-p.x,y-p.y); }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); } 
    T cross(P p) const { return x*p.y-y*p.x; }
};
template <class P>
int sideOf(P s, P e, P p) { return sgn(s.cross(e,p)); }

const int MOD = (int)1e9+7;
struct Angle{
    int x,y;
    int t;
    Angle(int x, int y, int t=0): x(x), y(y), t(t) {}
    Angle operator- (Angle b) const {return {x-b.x,y-b.y}; }
    int half() const {
        assert( x || y);
        return y<0 || (y==0 && x<0);
    }
    bool operator< (const Angle& b) const{
        return make_tuple(t,half(), y*(ll)b.x) <
               make_tuple(b.t,b.half(), x*(ll)b.y);
    }

};
typedef Point<int> P;
int main()
{
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    vector<Angle> A;
    FOR(i,n-1){
       int a, b; 
       cin>>a>>b;
       A.pb(Angle(a-x,b-y));
    }
    sort(A.begin(),A.end());
    n--;
    int j=0;
    int most = 0;
    int least = n+1000;
    FOR(i,n){
        while(sideOf(P(0,0),P(A[i].x,A[i].y),P(A[j].x,A[j].y))>=0 && j<n) j++;
        int left = j-i+1;
        int right = n-left;
        most = max(most,max(left,right));
        least = min(least,min(left,right));
    }
    cout<<most<<" "<<n-least+1<<endl;
    return 0;
}
