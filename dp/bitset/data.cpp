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

int n;
int A[14];
int dp[1<<14];
const int N = 14*1000+1;
int cost[N];
vector<pii> pairs;
int last;
int solve(int i){
    if(i==last) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans = 0;
    for(pii x: pairs){
        if((x.f&i)) continue;
        ans = max(ans,solve(i|x.f)+x.s);
    }
    return dp[i] = ans;
}

int main()
{
    vector<bool> primes(N,true);
    primes[0] = primes[1] = false;
    vector<int> pr;
    for(int i=2;i<N;i++){
        if(primes[i]){
            pr.pb(i);
            for(int j=i*2;j<N;j+=i){
                primes[j] = false;
            }
        }
    }
    cost[0] = cost[1] = 0;
    for(int i=2;i<N;i++){
        int tot = 0;
        for(auto x: pr) if(i%x==0) tot++;
        cost[i] = tot;
    }
    cin>>n;
    FOR(i,n) cin>>A[i];
    FOR(i,1<<n){
        if(i==0) continue;
       int sum = 0;
       FOR(j,n){
        if(i&(1<<j)) sum+=A[j]; 
       }
       pairs.pb({i,cost[sum]});
    }
    last = (1<<n)-1;
    memset(dp,-1,sizeof dp);
    int ans = solve(0);
    cout<<ans<<endl;
    return 0;
}
