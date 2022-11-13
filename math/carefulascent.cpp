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

const int MOD = (int)1e9+7;
struct shield{
    int l,u;
    double f;
    shield(int _l, int _u, double _f){
        l = _l;
        u = _u;
        f = _f;
    }
};

int main()
{
    int x,y;
    cin>>x>>y;
    int n;
    cin>>n;
    vector<shield> all;
    FOR(i,n){
        int x,y; double f;
        cin>>x>>y>>f;
        all.pb(shield(x,y,f));
    }
    double notused = y;
    double tot =0;
    FOR(i,n){
        notused-=all[i].u-all[i].l;
        tot+=(all[i].u-all[i].l)*all[i].f;
    }
    tot+=notused;
    double ans = x/tot;
    printf("%.10lf\n",ans);


    return 0;
}
