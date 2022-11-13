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
int dx[] = {-2, -2,-1,1,2,2,-1,1};
int dy[] = { 1, -1,-2,-2,1,-1,2,2};
bool valid(int i, int j){
    return i>=0 && i<r && j>=0 && j<c;
}
int main()
{
    int n;
    cin>>n;
    r = n; c = n;
    int cc[r][c];
    memset(cc,0,sizeof cc);
    FOR(i,r){
        FOR(j,c){
            FOR(k,8){
                if(valid(i+dx[k],j+dy[k])) cc[i][j]++;
            }
        }
    }
    FOR(i,r){
        FOR(j,c){
            //cout<<cc[i][j]<<" ";
        }
        //cout<<endl;
    }
    if(n%2==1) cout<<"first\n";
    else cout<<"second\n";
    return 0;
}
