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
vector<string> g;
int remain[9][9];
int G[81][81];
int n;
bool vist[9][9];
int origi[9][9];
bool cycle = false;
int f(int i, int j){
    return i*(n+1)+j;
}
bool valid(int i, int j){
    return i>=0 && i<=n && j>=0 && j<=n;
}
int dirx[4] = {1,1,-1,-1};
int diry[4] = {-1,1,-1,1};
void dfs(int i, int j, int k, int l){
   vist[i][j] = true;
   FOR(R,4){
        int i2 = i+dirx[R];
        int j2 = j+diry[R];
        if(valid(i2,j2) && !vist[i2][j2] && G[f(i,j)][f(i2,j2)]){
            dfs(i2,j2,i,j);
        }
        else if(valid(i2,j2) && G[f(i,j)][f(i2,j2)] && vist[i2][j2]){
            if(i2!=k || j2!=l)
            cycle = true;
        }
   }
}
bool checkcycle(){
    memset(vist,false,sizeof vist);
    cycle = false;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(!vist[i][j]){
                dfs(i,j,i,j);
            }
        }
    }
    return cycle;
}
void printsol(){
   FOR(i,n){
    FOR(j,n){
        if(G[f(i,j)][f(i+1,j+1)]) cout<<"\\";
        else cout<<"/";
    }
    cout<<endl;
   }
}
bool checkrow(int r){
    FOR(i,n+1){
       if(origi[r][i]==100) continue; 
       if(remain[r][i]!=0) return false;
    }
    return true;
}
bool checkcyclerow(int r){
    memset(vist,false,sizeof vist);
    cycle = false;
    FOR(i,n+1){
        if(!vist[r][i]) dfs(r,i,r,i);    
    }
    return cycle;
}
bool found = false;
int rows[8];
vector<pii> all;
void solve(int choice){
    if(found) return;
    if(choice==n*n){
        if(!checkcyclerow(choice/n) && checkrow(n) && checkrow(n-1) && checkrow(n-2)){
            printsol();
            found = true;
        }
        return;
    }

    FOR(i,n)
        if(rows[i]==n && checkcyclerow(i)) return;

    FOR(i,n){
        if(rows[i]!=n) continue;
    }
    


    //if(choice%n==0 && choice>=2*n) if(!checkrow(choice/n-2)) return; 
    //if(choice%n==0 && checkcyclerow(choice/n)) return;

    int r1 = all[choice].s/n; int r2 = r1+1;
    int c1 = all[choice].s%n; int c2 = c1+1;
        if(remain[r1][c1] && remain[r1+1][c1+1]){
            remain[r1][c1]--;
            remain[r1+1][c1+1]--;
            G[f(r1,c1)][f(r1+1,c1+1)] = true;
            G[f(r1+1,c1+1)][f(r1,c1)] = true;

            rows[r1]++;
            solve(choice+1);
            rows[r1]--;

            G[f(r1,c1)][f(r1+1,c1+1)] = false;
            G[f(r1+1,c1+1)][f(r1,c1)] = false;
            remain[r1][c1]++;
            remain[r1+1][c1+1]++;
        }
        if(remain[r1][c1+1] && remain[r1+1][c1]){
            remain[r1][c1+1]--;
            remain[r1+1][c1]--;
            G[f(r1,c1+1)][f(r1+1,c1)] = true;
            G[f(r1+1,c1)][f(r1,c1+1)] = true;
            
            rows[r1]++;
            solve(choice+1);
            rows[r1]--;

            remain[r1][c1+1]++;
            remain[r1+1][c1]++;
            G[f(r1,c1+1)][f(r1+1,c1)] = false;
            G[f(r1+1,c1)][f(r1,c1+1)] = false;

        }
}
int main()
{
    cin>>n;
    g.resize(n+1);

    FOR(i,n+1) FOR(j,n+1) remain[i][j] = 100;

    FOR(i,n+1){
        cin>>g[i];
        FOR(j,n+1){
            if(g[i][j]!='+'){
                remain[i][j] = g[i][j]-'0';
            }
            origi[i][j] = remain[i][j];
        }
    }
    g.clear();
    int kk = 0;
    for(int i=0;i<n;i++){
        int conditions = 0;
        for(int j=0;j<n;j++){
            if(remain[i][j]!=100) conditions+=remain[i][j];
            if(remain[i+1][j]!=100) conditions+=remain[i+1][j];
            if(remain[i][j+1]!=100) conditions+=remain[i][j+1];
            if(remain[i+1][j+1]!=100) conditions+=remain[i+1][j+1];
            all.pb(make_pair(conditions,kk++));
        }
    }
    sort(all.begin(),all.end());
    solve(0);

    return 0;
}
