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

int n,r,c,l;
char G[10][10];
int xPos[5];
int yPos[5];
int tx,ty;
int ans = MOD;
bool valid(int i, int j){
    return i>=0 && i<r && j>=0 && j<c && G[i][j]=='.';
}
vector<pii> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
set<pair<string,int>> states;
void solve(int turn){
    if(turn>=ans) return;
    if(xPos[1]==tx && yPos[1]==ty){
        ans = min(ans,turn);
        return;
    }
    if(turn==l){
        return;
    }
    //chose piece 
    string ss(r*c,'0');
    FOR(i,r) FOR(j,c) ss[i*c+j] = G[i][j];
    if(states.find({ss,turn})!=states.end()) return;
    for(int i=1;i<=n;i++){
        //chose direction
        FOR(k,4){
            pii start = {yPos[i],xPos[i]};
            assert(isdigit(G[start.f][start.s]));
            pii curr = start;
            while(valid(curr.f+dirs[k].f,curr.s+dirs[k].s)){
                curr.f+=dirs[k].f;
                curr.s+=dirs[k].s;
            }
            yPos[i] = curr.f;
            xPos[i] = curr.s;
            swap(G[start.f][start.s],G[curr.f][curr.s]);
            solve(turn+1);
            yPos[i] = start.f;
            xPos[i] = start.s;
            swap(G[start.f][start.s],G[curr.f][curr.s]);
        }
    }
    states.insert({ss,turn});
}
int main()
{
    cin>>n>>c>>r>>l;
    FOR(i,r){
        FOR(j,c){
            cin>>G[i][j];
            for(char k='1';k<='4';k++){
                if(G[i][j]==k){
                    xPos[k-'0'] = j;
                    yPos[k-'0'] = i;
                }
            }
            if(G[i][j]=='X'){
                G[i][j] = '.';
                tx = j;
                ty = i;
            }
        }
    }
    solve(0);
    if(ans==MOD) cout<<"NO SOLUTION\n";
    else cout<<ans<<endl;
    return 0;
}
