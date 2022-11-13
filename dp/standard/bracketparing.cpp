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
ll dp[22][22];
int n;
string in;
int valid(int i, int j){
    if(in[i]=='?' && in[j]=='?') return 4;
    if(in[i]=='(' && (in[j]==')' || in[j]=='?') ) return 1;
    if(in[i]=='<' && (in[j]=='>' || in[j]=='?') ) return 1;
    if(in[i]=='{' && (in[j]=='}' || in[j]=='?') ) return 1;
    if(in[i]=='[' && (in[j]==']' || in[j]=='?') ) return 1;
    if(in[i]=='?' && (in[j]!='(' && in[j]!='[' && in[j]!='{' && in[j]!='<') ) return 1;
    return 0;
}
ll solve(int i, int j){
    if(i>j) return 1;
    if(i+1==j){
        return valid(i,j);
    }
    if(dp[i][j]!=-1) return dp[i][j];
    ll ans = 0;
    if(valid(i,j)){
        ans+=solve(i+1,j-1)*valid(i,j);
    }
    for(int k=j-1;k>i+1;k-=2){
        if(valid(k,j)){
            ans+=solve(i,k-1)*solve(k+1,j-1)*valid(k,j);
        }
    }
    return dp[i][j] = ans;
}
int main()
{
    cin>>in;
    n = in.size();
    memset(dp,-1,sizeof dp);
    ll ans = solve(0,n-1);
    cout<<ans<<endl;
    return 0;
}
