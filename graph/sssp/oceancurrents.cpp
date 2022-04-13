/*
    A lot of boiler plate code but the question is very simple when modeled as a graph. 
    For a given square on the grid we can go into one of 8 adjacent grid spaces 
    if that space is inside the grid. The cost to move to each of the squares is 1
    and 0 if the direction we are going to matches the value of that grid spot. 
    So we can just run dijkstras on every single query and check the distance 
    from the given start node to the given end node. 
    Since the grid size can be up only up to 50*50. We can get a solution 
    under the time limit. 
*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>
const int INF = (int)1e9;

int r,c;
int grid[1000][1000];
vector<pii> dir = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

bool valid(int i, int j){
    return i>=0 && i<r && j>=0 && j<c;
}

vector<vi> solve(int x,int y){
    vector<vi> dist(r,vi(c,INF));

    dist[x][y] = 0;
    set<pair<int,pii>> q;
    q.insert({0,{x,y}});
    while(!q.empty()){
        pii u = q.begin()->second;
        q.erase(q.begin());
        for(int j=0;j<dir.size();j++){
            pii d = dir[j];
            pii v = {u.first+d.first,u.second+d.second};
            if(valid(v.first,v.second)){
               int w = (j==grid[u.first][u.second])?0:1; 
               if(dist[u.first][u.second]+w<dist[v.first][v.second]){
                    q.erase({dist[v.first][v.second],v});
                    dist[v.first][v.second] = dist[u.first][u.second]+w;
                    q.insert({dist[v.first][v.second],v});
               }
            }

        }
    }

    return dist;
}

int main()
{
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char c; cin>>c;
            grid[i][j] = c-'0';
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int r1,c1;
        cin>>r1>>c1;
        r1--; c1--;
        int r2,c2;
        cin>>r2>>c2;
        r2--; c2--;
        vector<vi> d = solve(r1,c1);
        cout<<d[r2][c2]<<endl;
    }

    
    return 0;
}
