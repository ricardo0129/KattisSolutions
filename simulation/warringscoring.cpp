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

int main()
{
    int n;
    cin>>n;
    int lcy=0,lcn=0;
    int longest = 0;

    int lly=0,lln=0;
    int streak = 0;
    FOR(i,n){
        string in;
        cin>>in;
        if(in[0]=='Y') streak++;
        else streak--;
        lly = max(streak,lly);
        lln = min(streak,lln);
        if(in[0]=='Y'){
            if(longest>=0) longest++;
            else{
                longest = 1;
            }
        }
        else{
            if(longest<=0) longest--;
            else{
                longest = -1;
            }
        }
        lcy = max(lcy,longest);
        lcn = min(lcn,longest);
    }
    //1 = y win   -1 = n win  0 = tie
    int state1,state2;
    if(abs(lcy)==abs(lcn)) state1=0;
    else if(abs(lcy)>abs(lcn)) state1 = 1;
    else state1 = -1;

    if(abs(lly)==abs(lln)) state2=0;
    else if(abs(lly)>abs(lln)) state2 = 1;
    else state2 = -1;
    if(state1==state2) cout<<"Agree\n";
    else cout<<"Disagree\n";


    return 0;
}
