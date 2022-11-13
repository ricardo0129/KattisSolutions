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

int n = 23;
map<string,int> dp;
int solve(string A){
    if(dp.count(A)>0) return dp[A];
    int best = 0;
    FOR(i,23) if(A[i]=='o') best++;
    //try all 
    for(int i=1;i<n-1;i++){
        if(A[i]=='o' && A[i+1]=='o' && A[i-1]=='-'){
            string B = A;
            B[i] = '-'; B[i+1]='-'; B[i-1]='o';
            best = min(best,solve(B));
        }
    }
    for(int i=0;i<n-2;i++){
        if(A[i]=='o' && A[i+1]=='o' && A[i+2]=='-'){
            string B = A;
            B[i] = '-'; B[i+1]='-'; B[i+2]='o';
            best = min(best,solve(B));
        }
    }
    return dp[A] = best;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string in;
        cin>>in;
        int ans = solve(in);
        cout<<ans<<endl;
    }
    return 0;
}
