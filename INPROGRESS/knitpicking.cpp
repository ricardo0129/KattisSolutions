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

int A[1001][3];
int main()
{
    int n;
    cin>>n;
    memset(A,0,sizeof A);
    map<string,int> mp;
    FOR(i,n){
        string name, type; int v;
        cin>>name>>type>>v;
        if(mp.count(name)<=0) mp[name] = mp.size();
        int p ;
        if(type=="left") p = 0;
        else if(type=="right") p = 1;
        else p = 2;
        A[mp[name]][p]+=v;
    }
    bool valid = false;
    FOR(i,mp.size()){
        if( (A[i][0]&&A[i][1]) || (A[i][0]&&A[i][2]) || (A[i][1]&&A[i][2]) || A[i][2]>=2) valid = true;
    }
    if(!valid) cout<<"impossible\n";
    else{
        int ans = 0;
        FOR(i,mp.size()){
            ans+=max(1,max(A[i][0],A[i][1]));
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
