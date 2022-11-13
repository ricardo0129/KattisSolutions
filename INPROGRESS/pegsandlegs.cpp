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

int l,p;
const int N = 2e5+1;
vector<pair<int,double>> G[N];
int score[N];
vi initial;
double solve(int u, int k){
    if(u<l) return (double)score[u];    
    double ex = 0;
    double outside=1;
    for(auto v: G[u]){
        ex += solve(v.f)*v.s;
        outside-=v.s;
    }
    if(outside>0){
        for(auto x: initial){
            ex+=
        }
    }
    return ex;
}

int main()
{
    cin>>l>>p;

    FOR(i,l){
       cin>>score[i]; 
    }
    vi indeg(p,0);
    FOR(i,p){
        double p1, p2;
        cin>>p1>>p2;
        int v1, v2;
        cin>>v1>>v2;
        v1--;v2--;
        G[i+l].pb({v1,p1});
        G[i+l].pb({v2,p2});
        if(v1>=l) indeg[v1-l]++;
        if(v2>=l) indeg[v2-l]++;
    }
    FOR(i,p){
        if(indeg[i]==0)
            initial.pb(i+l);
    }

    double best = 0;
    FOR(i,p){
        if(indeg[i]==0){
            best = max(best,solve(i+l,10));
            cout<<solve(i+l,10)<<endl;
        }
    }
    printf("%.8lf\n",best);
    return 0;
}
