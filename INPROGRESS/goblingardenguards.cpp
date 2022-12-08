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

int mp[10001][10001];
int main()
{
    int n;
    scanf("%d", &n);
    //map<pii,int> mp;
    memset(mp,0,sizeof mp);
    FOR(i,n){
        int x,y;
        scanf("%d %d", &x, &y);
        //mp[make_pair(x,y)]++;
        mp[x][y]++;
    }
    int m;
    scanf("%d", &m);
    FOR(tt,m){
        ll x,y,r;
        scanf("%lld %lld %lld", &x, &y, &r);
        for(int i=x-r;i<=x+r;i++){
            for(int j=y-r;j<=y+r;j++){
                if(i<0 || j<0 || i>10000 || j>10000) continue;
                ll distSq = (x-i)*(x-i)+(y-j)*(y-j);
                if(distSq<=r*r){
                    /*
                    if(mp.count(make_pair(i,j))){
                        n-=mp[make_pair(i,j)]; 
                        mp.erase(make_pair(i,j));
                    }
                    */
                    n-=mp[i][j];
                    mp[i][j] = 0;
                }
            } 
        }
    }
    printf("%d\n", n);
    return 0;
}
