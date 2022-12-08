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

double calc(pair<double,double> A, pair<double,double> B){
    return abs(A.s-B.s)/abs(A.f-B.f);
}
bool check(vector<pair<double,double>>& A, double L){
   bool valid = true;
   FOR(i,sz(A)){
        double v1 =0, v2 = 0;
        if(i!=0) v1 = calc(A[i],A[i-1]);
        if(i!=sz(A)-1) v2 = calc(A[i],A[i+1]);
        valid &= v1<=L;
        valid &= v2<=L;
   }
   return valid;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<double,double>> A(n);
    FOR(i,n) cin>>A[i].f>>A[i].s;
    sort(A.begin(),A.end());
    double l = 0, r = 5e9;
    double ans = r;
    while(abs(r-l)>=1e-6){
        double m = (l+r)/2;
        bool possible = true;
        possible &= check(A,m); 

        if(possible){
            r = m; 
            ans = m;
        }
        else l = m;
    }
    printf("%.8lf\n",ans);

    return 0;
}
