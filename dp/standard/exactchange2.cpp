/*
Lets define a recurse relation on our problem 
Lets dp[i][c] = (minimum val >= total, using k coins)
where i is the available number of bills and c is the sum of the bills used 

dp[i][c] = min(dp[i][c],dp[i][c+A[i]]+1)

This might be a little much to take in at once. But we can solve an easier problem first 
lets say we don't care about the number of coins we just want to pay the least amount possible while 
still paying. 

We can solve this recursively. let A = an array with the bills we can use, A[i] = bill of amount s 
Lets start with position 0, and sum of bills 0. 
Then lets say we chose position i. 
We get solve(0+1,0+A[i]) 
or lets say we dont chose bill i 
we get solve(0+1,0)
then we jsut take the minimum between solve(1,A[i]), solve(1,0) 
And lets solve this recursively and we can have a base case 
if i==n (no more bills to chose)
if c<m return INF <- since we want to minimize lets return the biggest element
else return c <- which is the current sum 
After this lets add memoization and were done. 
The answer to the original problem is not so different, we just add k the amount of coins used at each step
and solve it the same way.
*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

const int INF = (int)1e9;
int m;
int n;
vi A;
pii dp[100][30000];
pii solve(int i, int c){
    if(i==n){
        if(c<m) return {INF,INF};
        else return {c,0};
    }
    if(dp[i][c].first>=0 && dp[i][c].second>=0) return dp[i][c];
    pii a;
    if(c+A[i]<=20000)
    a = solve(i+1,c+A[i]);
    else
    a = {INF,INF};
    a.second+=1;
    pii b = solve(i+1,c);
    return dp[i][c] = min(a,b);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>m;
        cin>>n;
        A.resize(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        sort(A.begin(),A.end());
        for(int i=0;i<n;i++) for(int j=0;j<30000;j++) dp[i][j] = {-1,-1};
        pii ans = solve(0,0);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}
