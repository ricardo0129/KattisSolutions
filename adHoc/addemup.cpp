#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)
set<int> notflip;
map<int,int> f;

int flip(int n){
        int ans=0;
        int i=0;
        int x = n;
        while(x){
                x/=10;
                i++;
        }
        i--;
        while(n){
                int d = n%10; 
                if(notflip.find(d)!=notflip.end()) return -1;
                d = f[d];
                ans+=d*pow(10,i);
                i--;
                n/=10;
        }
        return ans;
}
int main()
{
        notflip.insert(3); notflip.insert(4); notflip.insert(7);
        f[1] = 1; f[2] = 2; f[5] = 5; f[6] = 9; f[8] = 8; f[9] = 6; f[0] = 0;

        int n,s;
        cin>>n>>s;
        vi A(n);
        FOR(i,n) cin>>A[i];

        set<int> numbers;
        bool possible = false;
        FOR(i,n){
                int inverse = s-A[i];
                if(numbers.find(inverse)!=numbers.end()) possible = true;
                int y = flip(A[i]);
                if(y!=-1){
                        if(numbers.find(s-y)!=numbers.end()) possible = true;
                        numbers.insert(y);
                }
                //cout<<A[i]<<" "<<y<<endl;
                numbers.insert(A[i]);
        }

        
        if(possible) cout<<"YES\n";
        else cout<<"NO\n";
        return 0;
}
