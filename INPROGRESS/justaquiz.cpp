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

const int N = 2e5+1;
struct Node{
    string val,ans;
    int idx=-1;
    int unique=0;
    bool end=false;
    int biggest=-1;
    vector<Node*> child;
    unordered_map<string,int> mp; 
    Node(){
        val = "$";
    }
    Node(string v){
        val = v;
    }
    void add(vector<string> v,string _ans){
        Node* start = this;    
        for(string s: v){
            if(start->mp.count(s)<=0){
                start->mp[s] = start->mp.size();
                start->child.pb(new Node(s));
            }
            start = start->child[start->mp[s]];
        }
        assert(start->end==false);
        start->ans = _ans;
        start->end = true;
    }
};
int subtree[N];
int dfs_numb;
unordered_map<string,int>* m_set[N];
void dfs(Node* root){
    root->idx = dfs_numb++;
    subtree[root->idx] = root->end;
    Node* big = NULL; int size_big = 0;
    for(Node* v: root->child){
        dfs(v);
        subtree[root->idx]+=subtree[v->idx];
        if(size_big<subtree[v->idx]){
            size_big = subtree[v->idx];
            big = v;
        }
    }

    int biggest = 1;
    if(!big){
        m_set[root->idx] = new unordered_map<string,int>();        
        (*m_set[root->idx])[root->ans]++;
        big = root;
    }
    else{
        biggest = big->biggest;
        m_set[root->idx] = m_set[big->idx];
    }
    for(Node* v: root->child){
        assert(v->idx>=0);
        if(v->idx==big->idx) continue;
        for(auto s: *m_set[v->idx]){
            (*m_set[root->idx])[s.f]+=s.s;
            biggest = max(biggest,(*m_set[root->idx])[s.f]);
        }
    }
    assert(root->idx>=0);
    root->unique = m_set[root->idx]->size();
    assert(biggest>=1);
    root->biggest = biggest;
}

#define ldd long double 
Node* top;
vector<vector<ldd>> dp;
ldd solve(Node* root, int t){
    if(t==0) return 0;
    if(dp[root->idx][t]>=0) return dp[root->idx][t];
    //we can either guess at the current node 
    ldd ex = 0;
    ex = solve(top,t-1)+( (ldd) root->biggest/(ldd) subtree[root->idx]);
    //or we continue
    ldd ex2 = 0;
    for(Node* v: root->child){
       ex2+=solve(v,t-1)*((ldd)subtree[v->idx])/(ldd)(subtree[root->idx]); 
       //assert(v->unique<=root->unique);
       //ex2+=solve(v,t-1)*(v->unique)/(ldd)(root->unique);
    }
    assert(ex>=0);
    assert(ex2>=0);
    return dp[root->idx][t] = max(ex,ex2);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<string>> q;
    vector<string> ans;
    FOR(i,m){
        string in;
        vector<string> ques;
        while(cin>>in){
            ques.pb(in);
            if(in[sz(in)-1]=='?') break;
        }
        q.pb(ques);
        string a;
        cin>>a;
        ans.pb(a);
    }
    Node* root = new Node();
    FOR(i,m){
        root->add(q[i],ans[i]);
    }
    memset(subtree,0,sizeof subtree);
    dfs_numb = 0;
    dfs(root);
    dp.assign(dfs_numb,vector<ldd>(n+1,-1));
    top = root;
    ldd sol = solve(root,n);
    printf("%.8Lf\n",sol);

    return 0;
}
