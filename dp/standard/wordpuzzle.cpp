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
string in,guess;
const int N = (int)1e5+1;
ll dp[N][51];
ll solve(int i, int j){
    if(i==in.size()) return j==guess.size();
    if(j==guess.size()) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    ll ans = solve(i+1,j)%MOD;
    if(guess[j]==in[i]) ans=(ans+(solve(i+1,j+1)%MOD))%MOD;
    return dp[i][j] = ans;
}
int main()
{
    cin>>in;
    cin>>guess;
    ll ans = 0;
    set<string> rotations;
    FOR(i,guess.size()){
        if(rotations.find(guess)==rotations.end()){
            FOR(i,in.size()) FOR(j,guess.size()) dp[i][j] = -1;
            ans=(ans+solve(0,0))%MOD;
        }
        rotations.insert(guess);
        rotate(guess.begin(),guess.begin()+1,guess.end());
    }
    cout<<ans%MOD<<endl;
    return 0;
}
