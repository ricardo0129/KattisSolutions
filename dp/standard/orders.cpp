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
int A[100];
int dp[100][30001];
char dir[100][30001];
int main()
{
    int n;
    cin>>n;
    FOR(i,n) cin>>A[i];
    //base case
    FOR(i,n) dp[i][0] = 1;
    for(int i=A[0];i<=30000;i+=A[0]){
        dp[0][i] = 1;
        dir[0][i] = 'L';
    }

    //coin change dp 
    for(int i=1;i<n;i++){
        for(int j=0;j<=30000;j++){
            //dont take
            dp[i][j] = dp[i-1][j];
            if(dp[i-1][j]) dir[i][j] = 'U';
            if(j-A[i]>=0){
                dp[i][j]+=dp[i][j-A[i]];
                if(dp[i][j-A[i]]) dir[i][j] = 'L';
            }
            dp[i][j] = min(dp[i][j],50);
        }
    }
    int q;
    cin>>q;
    FOR(i,q){
        int v;
        cin>>v;
        if(dp[n-1][v]==0) cout<<"Impossible\n";
        else if(dp[n-1][v]>1) cout<<"Ambiguous\n";
        else{
            pii start = {n-1,v};
            vector<int> order;
            while(start.s>0){
                if(dir[start.f][start.s]=='U') start.f--;
                else{
                    order.pb(start.f+1);
                    start.s-=A[start.f];
                }
            }
            for(int i=order.size()-1;i>=0;i--) cout<<order[i]<<" ";
            cout<<endl;
             
        }
    }

    return 0;
}
