/*
    We can look at two main cases
    Case 1: if we have two different types of cards we haven't seen or theres one type of card 
    we havent seen and more than 3 cards are face up. 
    In this case we are only guaranteed types of card we have flipped up. So we just use 
    basic data structures to keep track of this data. 
    Case 2: is just the negation of case 1. In this case we are able to guess every 
    card type that is left. 
*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

int n,k;
string A[1000];
bool check[1000];
set<string> used;
map<string,int> seen;
int main()
{
    cin>>n;
    cin>>k;
    for(int i=0;i<k;i++){
        int u,v; string a,b;
        cin>>u>>v>>a>>b;
        u--;v--;
        A[u] = a;
        A[v] = b;
        check[u] = true; check[v] = true;
        if(a==b) used.insert(a);
    }
    int up = 0;
    int down = 0;
    for(int i=0;i<n;i++){
        if(check[i]){
            seen[A[i]]++;
            up++;
        }
        else down++;
    }
    int score = 0;
    for(auto x: seen){
        if(x.second==2 && used.find(x.first)==used.end()){
           score++; 
        }
    }
    if(n/2-seen.size()>=2 || (n/2-seen.size()==1 && down>=3)){
        cout<<score<<endl;
    }
    else{
        cout<<n/2-used.size()<<endl;
    }

    return 0;
}
