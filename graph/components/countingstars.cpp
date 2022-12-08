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
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int r,c;
bool valid(int i, int j){
    return i>=0 && i<r && j>=0 && j<c;
}
bool vist[100][100];
vector<string> g;
void dfs(int i, int j){
    vist[i][j] = true;
    FOR(k,4){
        int i2 = i+dx[k];
        int j2 = j+dy[k];
        if(valid(i2,j2)&& !vist[i2][j2] && g[i2][j2]=='-') dfs(i2,j2);
    }
}

int main()
{
    int cc = 1;
    while(cin>>r>>c){
        g.resize(r);
        FOR(i,r)
            cin>>g[i];
        memset(vist,false,sizeof vist);
        int ans = 0;
        FOR(i,r)
            FOR(j,c)
                if(g[i][j]=='-' && !vist[i][j]){
                    dfs(i,j);
                    ans++;
                }
        printf("Case %d: %d\n",cc++,ans);

        
    }
    return 0;
}
