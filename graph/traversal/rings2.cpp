#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;
vector<string> g;
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int n,m;
bool valid(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

int main()
{
    cin>>n>>m;
    
    g.resize(n);
    FOR(i,n) cin>>g[i];

    
    queue<int> X,Y;
    vector<vi> dist(n,vi(m,-1));
    FOR(i,n) FOR(j,m){
        if(g[i][j]=='.')
            dist[i][j] = 0; 
        else{
            bool corner = false;
            if(i==0 || i==n-1 || j==0 || j==m-1) corner = true;
            FOR(k,4){
                int i2 = i+dx[k];
                int j2 = j+dy[k];
                if(valid(i2,j2) &&  g[i2][j2]=='.')
                    corner = true;
                }
            
            if(corner){
                X.push(i);
                Y.push(j);
                dist[i][j] = 1;
            }
        }

        
    }
        
    int rings = 0;
    while(!X.empty()){
        int i = X.front(), j = Y.front(); 
        X.pop(); Y.pop();
        rings = max(rings,dist[i][j]);
        FOR(k,4){
            int i2 = i+dx[k];
            int j2 = j+dy[k];
            if(valid(i2,j2) && dist[i2][j2]==-1){
                X.push(i2);
                Y.push(j2);
                dist[i2][j2] = dist[i][j]+1;
            }
        }
    }
    int offset = rings<10?2:3;
    FOR(i,n){
        FOR(j,m){
            int off = offset;
            if(dist[i][j]>0 && dist[i][j]<10) off-=1;
            else if(dist[i][j]>=10) off-=2;
            cout<<string(off,'.');
            if(dist[i][j]) cout<<dist[i][j];
        }
        cout<<endl;
    }

    
    return 0;
}
