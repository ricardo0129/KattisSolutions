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
#define ull unsigned long long 

const int MOD = (int)1e9+7;
int A[100][100];
ull absa(ull a){
  if(a>=0) return a;
  return a*-1;
}
int main()
{
  /*
   * if 2 zeros ans is just 0 
   * if 1 zero  ans is either 1 or 2 depending on the smallest number other than zero 
   * otherwise if twos are equal the answer is zero if not the answer is 2^(n/2)
   */
    int r, c;
    cin>>r>>c;
    int zeros = 0;
    int twos = 0;
    int ones = 0;
    FOR(i,r) FOR(j,c){
        cin>>A[i][j];
        if(A[i][j]==0) zeros++;
        else if(A[i][j]==2) twos++;
        else ones++;
    }
    if(zeros>=2) cout<<0<<endl;
    else if(zeros==1){
        if(c==1){
          if(A[0][0]==0) cout<<A[r-1][0]<<endl;
          else if(A[r-1][0]==0) cout<<A[0][0]<<endl;
          else cout<<min(A[0][0],A[r-1][0])<<endl;
        }
        else if(r==1){
          if(A[0][0]==0) cout<<A[0][c-1]<<endl;
          else if(A[0][c-1]==0) cout<<A[0][0]<<endl;
          else cout<<min(A[0][0],A[0][c-1])<<endl;
        }
        else if(ones) cout<<1<<endl;
        else cout<<2<<endl;
    }
    else if(twos==0){
      cout<<0<<endl;
    }
    else{
      if(twos%2==0) cout<<0<<endl;
      else cout<<(1LL<<(twos/2))<<endl;
    }


    return 0;
}
