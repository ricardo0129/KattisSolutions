#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)

int dp[1001][1001];
int main()
{
        int k;
        cin>>k;
        string A,B;
        cin>>A;
        cin>>B;
        int n = A.size();
        memset(dp,0,sizeof dp);
        dp[0][0] = A[0]!=B[0];
        dp[0][1] = A[0]==B[0];
        for(int i=1;i<n;i++){
                for(int j=0;j<=k && j<=(i+1);j++){
                        if((i-1)>=(j-1))
                        dp[i][j] = dp[i-1][j]+(int)(A[i]!=B[i]);
                        if(j!=0) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+(int)(A[i]==B[i]));
                }
        }
        cout<<dp[n-1][k]<<endl;



	return 0;
}
