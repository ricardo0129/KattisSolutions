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
    int n = in.size();
    //always possible when n
    int ans = n;
    for(int i=1;i<n;i++){
        if(n%i!=0) continue;
        bool valid = true;
        for(int k=0;k<n;k+=i){
            if(k!=0){
                //compare in[k,k+i-1] with in[k-i,k-1]
                int r = k;
                int l = k-1;
                FOR(s,i){
                    if(in[l]!=in[r]) valid = false;
                    if(s==0) l = k-i;
                    else l++;
                    r++;
                }
            }
        }
        if(valid){
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
