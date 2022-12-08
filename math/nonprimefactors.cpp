#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define rep(i, a, b) for(int i = a; i < (b); ++i)

const int MOD = (int)1e9+7;
const int LIM = 2e6+10;
//bitset<LIM> isPrime;
bool isPrime[LIM];

void era(){
    const int S = (int)round(sqrt((int)3e6)), R = LIM/2;
    vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
    vector<pii> cp;
    for(int i=3;i<=S;i+=2) if(!sieve[i]){
        cp.pb({i,i*i/2});
        for(int j=i*i;j<=S;j+=2*i) sieve[j] = 1;
    }
    for(int L = 1;L<=R;L+=S){
        //array<bool,S> block{};
        vector<bool> block(S);
        for(auto &[p,idx] : cp)
            for(int i = idx; i<S+L;idx=(i+=p)) block[i-L] = 1;
        rep(i,0,min(S,R-L))
            if(!block[i]) pr.pb((L+i)*2+1);
    }
    for(int i: pr) isPrime[i] = 1;
}
int dp[(int)2e6+100];
int main()
{
    int t;
    era();
    //cin>>t;
    scanf("%d",&t);
    memset(dp,-1,sizeof dp);
    int x,tot,cc,y;
    int times;
    while(t--){
        scanf("%d",&x);
        if(dp[x]!=-1){
            printf("%d\n",dp[x]);
            continue;
        }
        if(isPrime[x]){
            dp[x] = 1;
            printf("%d\n",1);
            continue;
        }
        tot = 1;
        cc = 0;
        y = x;
        if(y%2==0){
            cc++;
            times=0;
            while(y%2==0){
                times++;
                y/=2;
            }
            tot*=(times+1);
        }
        for(int i=3;i*i<=x;i+=2){
            if(x%i!=0) continue;

            if(isPrime[i]){
                cc++;
                times =0;
                while(y%i==0){
                    times++;
                    y/=i;
                }
                tot*=(times+1);
            }
        }
        if(isPrime[y]){
            tot*=2;
            cc++;
        }
        tot-=cc;
        dp[x] = tot;
        printf("%d\n",tot);
        //cout<<tot<<endl;
    }
    
    return 0;
}
