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

int main()
{
    int k,n,m;
    scanf("%d %d %d",&k, &n, &m);
    vector<vector<vi>> flights(n);
    vector<vector<pii>> arriving(n);
    vi people(k,0);
    FOR(i,m){
       int u,v,d,z; 
       scanf("%d %d %d %d",&u,&v,&d,&z);
       u--; v--; d--;
       flights[d].pb({u,v,z});
    }
    FOR(i,k*n){
        int a,d,c;
        scanf("%d %d %d",&a, &d, &c);
        a--; d--;
        arriving[d].pb({a,c});
    } 
    bool valid = true;
    FOR(i,n){
        vi new_people(k,0);
        for(pii v: arriving[i]){
            people[v.f]+=v.s;
        }
        for(vi fl: flights[i]){
            if(people[fl[0]]<fl[2]) valid = false;
            people[fl[0]]-=fl[2];
            new_people[fl[1]]+=fl[2];
        }

        FOR(i,k) people[i]+=new_people[i];
    }

    if(valid) printf("optimal\n");
    else printf("suboptimal\n");



    return 0;
}
