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

int query(string in){
   cout<<in<<endl; 
   string out;
   cin>>out;
   cin>>out;
   if(out=="GRANTED") return -1;
   char x;
   cin>>x;
   string number;
   cin>>number;
   cin>>out;
   return stoi(number);
}
int main()
{
    int best = 0;
    int sz = -1;
    FOR(i,20){
        int x = query(string(i+1,'A'));
        if(x==-1) return 0;
        if(x>best){
            best = x;
            sz = i+1;
        }
    }
    string curr = string(sz,'A');
    FOR(i,sz){
        int best = 0;
        char v = 'c';
        for(char c='a';c<='z';c++){
            curr[i] = c;
            int x = query(curr);
            if(x==-1) return 0;
            if(x>best){
               best = x;
               v = c;
            }
        }
        for(char c='A';c<='Z';c++){
            curr[i] = c;
            int x = query(curr);
            if(x==-1) return 0;
            if(x>best){
               best = x;
               v = c;
            }
        }
        for(char c='0';c<='9';c++){
            curr[i] = c;
            int x = query(curr);
            if(x==-1) return 0;
            if(x>best){
               best = x;
               v = c;
            }
        }
        curr[i] = v;
    }
    
    return 0;
}
