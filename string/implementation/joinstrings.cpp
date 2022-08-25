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


struct Node{
    string val;
    Node* next;
    Node* last;
    Node(string v){
        val = v;
        next = NULL;
        last = this;
    }
};

int main()
{
        int n;
        cin>>n;
        vector<Node*> A;
        FOR(i,n){
            string s;
            cin>>s;
            A.pb(new Node(s));
        }

        FOR(i,n-1){
            int a,b; 
            cin>>a>>b;
            Node* x = A[a-1];
            Node* y = A[b-1];
            Node* la = x->last;
            la->next = y;
            x->last = y->last;
            A[b-1] = NULL;
        }

        FOR(i,n){
            if(A[i]!=NULL){
                Node* start = A[i];
                while(start){
                    cout<<start->val;
                    start = start->next;
                }
                cout<<endl;
            }
        }

	return 0;
}
