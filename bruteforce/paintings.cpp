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
vector<string> colors;
const int N = 20;
bool bad[N][N];
int total;
bool used[N];
int arrangment[N];
int ans[N];
int n;
void solve(int i){
    if(i==n){
        if(total++==0){
            FOR(j,n) ans[j] = arrangment[j];
        }
        return;
    }
    FOR(k,n){
        if(used[k]) continue;
        if(i==0 || !bad[arrangment[i-1]][k]){
            arrangment[i] = k;
            used[k] = true;
            solve(i+1);
            used[k] = false;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        map<string,int> mp;
        colors.clear();
        memset(bad,false,sizeof bad);
        FOR(i,n){
            string in;
            cin>>in;
            colors.pb(in);
            mp[in] = mp.size();
        }
        int edges;
        cin>>edges;
        FOR(i,edges){
            string a,b;
            cin>>a>>b;
            int u = mp[a];
            int v = mp[b];
            bad[u][v] = true;
            bad[v][u] = true;
        }
        total=0;
        memset(used,false,sizeof false);
        solve(0);
        cout<<total<<endl;
        FOR(i,n) cout<<colors[ans[i]]<<" ";
        cout<<endl;

    }
    return 0;
}
