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
int A[26];
map<char,int> mp;
vi pos[10];
vi last;
vi letter;
int main()
{
    int n;
    cin>>n;
    vector<string> w(n);
    FOR(i,n){
        cin>>w[i]; 
        reverse(w[i].begin(),w[i].end());
        FOR(j,w[i].size()){
            if(mp.count(w[i][j])<=0){
                mp[w[i][j]] = mp.size();
            }
            if(i!=n-1)
                pos[j].pb(mp[w[i][j]]);
            else
                last.pb(mp[w[i][j]]);
        }
        letter.pb(mp[w[i][w[i].size()-1]]);
    }
    int fact[11];
    fact[0] = 1;
    for(int i=1;i<=10;i++){
        fact[i] = fact[i-1]*10;
    }
    int ans = 0;
    vi perm(10);
    FOR(i,10) perm[i] = i;
    int sum;
    bool valid;
    int xx;
    do{
        sum = 0; 
        valid = true;
        for(int x: letter) if(perm[x]==0) valid = false;
        if(!valid) continue;
        FOR(i,last.size()){
            sum-=fact[i]*perm[last[i]];
        }

        FOR(i,10){
            for(int x:pos[i]) sum+=fact[i]*perm[x];
        }
        if(sum==0 && valid){
            ans++;
        }

    }while(next_permutation(perm.begin(),perm.end()));

    int left = 10-(int)mp.size();
    int ff = 1;
    for(int i=1;i<=left;i++) ff*=i;
    cout<<ans/ff<<endl;
    return 0;
}
