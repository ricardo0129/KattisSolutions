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

vector<int> A;
bool used[10];
int digit[6];
int l, r;
int ans = 0;
void compute(int i){
    if(i==6){
        int guess = 0;
        FOR(k,6){
            guess+=pow(10,k)*digit[k];
        }
        FOR(k,6){
            if(guess%digit[k]!=0) return;
        }
        if(l<=guess && guess<=r) ans++;
        return;    
    }
    for(int k=1;k<=9;k++){
        if(used[k]) continue;
        digit[i] = k;  
        used[k] = true;
        compute(i+1);
        used[k] = false;
    }

}
int main()
{
    cin>>l>>r;
    compute(0);
    cout<<ans<<endl;
    return 0;
}
