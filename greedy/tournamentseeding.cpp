/*
    From the requirements of the tournmanet we see that for the first round 
    half of the tournament with the highest ratings proceded. Which means if we 
    sort the ratings of the players. In the first round we need some pairing 
    between the first half and the second half that gives up maximum ans
    
    We can do this greedily if we have Al Al+1 Al+2 ... Ar 
    We first split the players into to halfs 
    A1<= A2<= A3<= A4 ...   B1<= B2<= B3<= B4....
    We first match B1 with the minimum rating which gives us a close game 
    Then we move on to B2 so on ans so on.
    We do this for all n rounds 
    
    we start with N = 2^n  players
    for each round we do a O(n) two pointers  to find the optimal paring 
    we have log(N) rounds so total time complexity is O(NlogN)
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>


ll n,k;
vll A;
int ans = 0;

void solve(int l, int r){
    int m = (r+l)/2;
    int j = 0;
    for(int i=l;i<=m;i++){
        if(A[m+1+j]-A[i]<=k) j++; 
    }
    ans+=j;
}
int main()
{
    cin>>n>>k;
    A.resize((1<<n));
    for(int i=0;i<(1<<n);i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    int L = 0, R = (1<<n)-1;
    for(int i=0;i<n;i++){
        solve(L,R);
        L = (R+L)/2+1;
    }
    cout<<ans<<endl;

    
    return 0;
}
