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
vector<string> g;
int cc[1000][1000];
bool vist[1000][1000];
int r,c;
int components = 0;
bool valid(int i, int j){
    return i>=0 && i<r && j>=0 && j<c;
}
void dfs(int i, int j){
    vist[i][j] = true;
    cc[i][j] = components;
    FOR(k,4){
        int i2 = i+dx[k];
        int j2 = j+dy[k];
        if(valid(i2,j2) && !vist[i2][j2] && g[i][j]==g[i2][j2]) 
            dfs(i2,j2);
    }
}
int main()
{
    cin>>r>>c;
    g.resize(r);
    FOR(i,r) cin>>g[i];
    int q;
    cin>>q;
    FOR(i,r){
        FOR(j,c){
            if(!vist[i][j]){
                dfs(i,j);
                components++;
            }
        }
    }

    FOR(i,q){
        int i1,j1,i2,j2;
        cin>>i1>>j1>>i2>>j2;
        i1--; j1--; i2--; j2--;
        if(cc[i1][j1]==cc[i2][j2]){
            if(g[i1][j1]=='1') cout<<"decimal\n";
            else cout<<"binary\n";
        }
        else cout<<"neither\n";
    }
    
    return 0;
}
