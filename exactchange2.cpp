#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

const int INF = (int)1e9;
int m;
int n;
vi A;
pii dp[100][30000];
pii solve(int i, int c){
    if(i==n){
        if(c<m) return {INF,INF};
        else return {c,0};
    }
    if(dp[i][c].first>=0 && dp[i][c].second>=0) return dp[i][c];
    pii a;
    if(c+A[i]<=20000)
    a = solve(i+1,c+A[i]);
    else
    a = {INF,INF};
    a.second+=1;
    pii b = solve(i+1,c);
    return dp[i][c] = min(a,b);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>m;
        cin>>n;
        A.resize(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        sort(A.begin(),A.end());
        for(int i=0;i<n;i++) for(int j=0;j<30000;j++) dp[i][j] = {-1,-1};
        pii ans = solve(0,0);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}
