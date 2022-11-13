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

const int MOD = (int)1e7+7;

const int N = 55;
int r,c,k;
char G[N][N];
string words[N];
int dp[N][N][N][N][3];
bool valid(int i, int j){
    return j>=0 && j<c;
}
int solve(int i, int j, int w, int l,int dir){
    //dir if 1 keep right them down
    //dir if 2 keep going left 
    //if zero either is fine
    //i,j pos in grid    w is current word    l = current letter on word
    if(i==r){
        if(w==0 || words[w].size()==l) return 0;
        return MOD;
    }
    if(dp[i][j][w][l][dir]!=-1) return dp[i][j][w][l][dir];
    int ans = MOD;
    if(w==0){
        //chose a word that starts with letter G[i][j]
        for(int s=1;s<=k;s++){
            if(words[s][0]==G[i][j]){
                int v =  solve(i+1,j,s,1,0)+1;
                ans =min(ans,v);
                if(valid(i,j+1) && dir!=2){
                    int v1 = solve(i,j+1,s,1,1)+1;
                    ans = min(ans,v1);
                }
                if(valid(i,j-1) && dir!=1){
                    int v2 = solve(i,j-1,s,1,2)+1;
                    ans = min(ans,v2);
                }
            } 
        }
    }
    else{
        if(words[w].size()==l){
            //finished word start a new one
            ans = min(ans,solve(i,j,0,0,dir));
        }
        else{
            if(words[w][l]==G[i][j]){
                //if valid continue;
                int v =  solve(i+1,j,w,l+1,0)+1;
                ans =min(ans,v);
                if(valid(i,j+1) && dir!=2){
                    int v1 = solve(i,j+1,w,l+1,1)+1;
                    ans = min(ans,v1);
                }
                if(valid(i,j-1) && dir!=1){
                    int v2 = solve(i,j-1,w,l+1,2)+1;
                    ans = min(ans,v2);
                }

            }
        }
    }
    return dp[i][j][w][l][dir] = ans;
}
int main()
{
    cin>>r>>c>>k;
    FOR(i,r) FOR(j,c) cin>>G[i][j];
    for(int i=1;i<=k;i++){
        cin>>words[i];
    }
    int ans = INT_MAX;
    memset(dp,-1,sizeof dp);
    FOR(i,c){
        ans = min(ans,solve(0,i,0,0,0));
    }
    if(ans>=MOD) cout<<"impossible\n";
    else cout<<ans<<endl;

    return 0;
}
