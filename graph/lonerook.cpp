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

int r,c;
vector<string> g;
vector<pii> k_move = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
int blocked[750][750];
bool cantTake[750][750];
bool valid(int i, int j){
    return i>=0 && i<r && j>=0 && j<c;
}
bool vist[750][750];
bool taken;
void removeKnight(int i, int j){
    taken = true;
    g[i][j] = '.';
    for(auto x: k_move){
        int i2 = i+x.f, j2 = j+x.s;
        if(valid(i2,j2)){
            blocked[i2][j2]--;
        }
    }  
}
bool ans;
pii start,ending;
void dfs(int i, int j){
    //left 
    vist[i][j] = true;
    if(i==ending.f && j==ending.s){
        ans = true;
    }
    for(int k=j-1;k>=0;k--){
        assert(k>=0);
        if(vist[i][k]) continue;
        if(cantTake[i][k]) break;
        if(blocked[i][k]) continue;
        if(g[i][k]=='K') removeKnight(i,k);
        dfs(i,k);
    }   
    //right
    for(int k=j+1;k<c;k++){
        assert(k>=0);
        if(vist[i][k]) continue;
        if(cantTake[i][k]) break;
        if(blocked[i][k]) continue;
        if(g[i][k]=='K') removeKnight(i,k);
        dfs(i,k);
    }   
    //down
    for(int k=i+1;k<r;k++){
        assert(k>=0);
        if(vist[k][j]) continue;
        if(cantTake[k][j]) break;
        if(blocked[k][j]) continue;
        if(g[k][j]=='K') removeKnight(k,j);
        dfs(k,j);
    }   
    //up
    for(int k=i-1;k>=0;k--){
        assert(k>=0);
        if(vist[k][j]) continue;
        if(cantTake[k][j]) break;
        if(blocked[k][j]) continue;
        if(g[k][j]=='K') removeKnight(k,j);
        dfs(k,j);
    }   
}

int main()
{
    cin>>r>>c;
    g.resize(r);
    FOR(i,r) cin>>g[i];
    FOR(i,r){
        FOR(j,c){
            if(g[i][j]=='R'){
                g[i][j] = '.';
                start = {i,j};
            }
            if(g[i][j]=='T'){
                g[i][j] = '.';
                ending = {i,j};
            }
            if(g[i][j]=='K'){
                for(auto x: k_move){
                    int i2 = i+x.f, j2 = j+x.s;
                    if(valid(i2,j2)){
                        if(g[i2][j2]=='K'){
                            blocked[i2][j2]++;
                            cantTake[i2][j2] = true;
                        }
                        else{
                            blocked[i2][j2]++;
                        }
                    }
                }  
            }
        }
    }
    do{
        taken = false;
        memset(vist,false,sizeof vist);
        dfs(start.f,start.s);
    }while(taken);
    memset(vist,false,sizeof vist);
    dfs(start.f,start.s);
    if(ans) cout<<"yes\n";
    else cout<<"no\n";




    return 0;
}
