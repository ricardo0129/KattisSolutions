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

int main()
{
    string in;
    cin>>in;
    ll ans = 0;
    for(char i = 'a';i<='z';i++){
        for(char j=i+1;j<='z';j++){
            char previous = '0';
            FOR(k,in.size()){
               if(in[k]!=i && in[k]!=j) continue;
               if(previous=='0') previous = in[k];
               else if(previous!=in[k]){
                    previous = in[k];
                    ans++;
               }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
