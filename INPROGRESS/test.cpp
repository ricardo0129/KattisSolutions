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

const int MOD = 13;

typedef vector<double> vd;
const double eps = 1e-12;
int solveLinear(vector<vd>& A, vd& b, vd& x) {

    int n = sz(A), m = sz(x), rank = 0, br, bc;
    if (n) assert(sz(A[0]) == m);
    vi col(m); iota(all(col), 0);
    rep(i,0,n) {
        double v, bv = 0;
        rep(r,i,n) rep(c,i,m)
            if ((v = fabs(A[r][c])) > bv)
                br = r, bc = c, bv = v;

        if (bv <= eps) {
            rep(j,i,n) if (fabs(b[j]) > eps) return -1;
            break;
        }
        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j,0,n) swap(A[j][i], A[j][bc]);
        bv = 1/A[i][i];

        rep(j,0,n) if (j != i){
            double fac = A[j][i] * bv;
            b[j] -= fac * b[i];
            rep(k,i+1,m) A[j][k] -= fac*A[i][k];
        }
        rank++;
    }
    x.assign(m, 0);
    for (int i = rank; i--;) {
        b[i] /= A[i][i];
        x[col[i]] = b[i];
        rep(j,0,i) b[j] -= A[j][i] * b[i];
    }

    
    x.assign(m, -1);
    rep(i,0,rank) {
        rep(j,rank,m) if (fabs(A[i][j]) > eps) goto fail;
        x[col[i]] = b[i] / A[i][i];
        fail:; 
    }
    return rank; // (multiple so lutions i f rank < m)
}



int main()
{
    vector<vector<double>> A(2,vector<double>(2)); 
    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 3; A[1][1] = 4;
    vector<double> b(2);
    b[0] = 2; b[1] = 3;
    vector<double> x(2);
    int rank = solveLinear(A, b,x);
    cout<<rank<<endl;
    for(double y: x) cout<<y<<endl;

    return 0;
}
