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
int dx[] = {2,2,-1,1,-2,-2,-1,1};
int dy[] = {-1,1,2,2,-1,1,-2,-2};
bool valid(int i, int j){
    return i>=0 && i<5 && j>=0 && j<5;
}
int main()
{
    vector<string> board(5);
    FOR(i,5) cin>>board[i];
    bool good = true;
    int tot = 0;
    FOR(i,5){
        FOR(j,5){
            if(board[i][j]!='k') continue;
            tot++;
            FOR(k,8){
                int ii = i+dx[k];
                int jj = j+dy[k];  
                if(valid(ii,jj) && board[ii][jj]=='k'){
                    good = false;
                }
            }
        }
    }
    if(tot!=9) good = false;
    if(!good) cout<<"invalid\n";
    else cout<<"valid\n";
    return 0;
}
