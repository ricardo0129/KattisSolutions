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
int c,n;
int weight[2000];
int value[2000];
int dp[2000][2001];
char previous[2000][2001];
int main()
{
    while(cin>>c){
        cin>>n;
        FOR(i,n){
            cin>>value[i]>>weight[i];
        }
        memset(dp,0,sizeof dp);
        int ans = 0;
        FOR(i,c+1) previous[0][i] = 'U';
        if(weight[0]<=c){
            dp[0][weight[0]] = value[0];
            previous[0][weight[0]] = 'L';
        }
        pii best;
        for(int i=1;i<n;i++){
            FOR(j,c+1){
                dp[i][j] = (dp[i-1][j]);
                previous[i][j] = 'U';
                if(j-weight[i]>=0){
                    //dp[i][j] = max(dp[i][j],dp[i-1][j-weight[i]]+value[i]);
                    if(dp[i-1][j-weight[i]]+value[i]>dp[i][j]){
                        dp[i][j] = dp[i-1][j-weight[i]]+value[i];
                        previous[i][j] = 'L';
                    }
                }
                if(ans<dp[i][j]){
                    ans = dp[i][j];
                    best = {i,j};
                }
            }
        }
        vector<int> chosen;
        pii pre = best;
        int i = best.f;
        int j = best.s;
        while(i>=0){
            if(previous[i][j]=='U'){
                i--;
            }
            else{
                j-=weight[i];
                chosen.pb(i);
                i--;
            }
        }
        cout<<chosen.size()<<endl;
        for(auto x: chosen) cout<<x<<" ";
        cout<<endl;

    }
    return 0;
}
