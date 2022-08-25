#include <iostream>
#include <cstring>

int dp[100][2000000];
int A[100];
int mm(int a, int b){
        return a<b?a:b;
}
int main()
{
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&A[i]);
        int large = A[n-1]+A[n-2];
        memset(dp,0x7f,sizeof(int)*(large+1)*n);
        for(int i=0;i<=large;i++) dp[0][i] = i;
        for(int i=1;i<n;i++){
                for(int j=0;j<A[i];j++) dp[i][j] = dp[i-1][j];
                for(int j=A[i];j<=large;j++){
                        dp[i][j] = mm(dp[i-1][j],dp[i][j-A[i]]+1);
                }
        }
        bool possible = true;
        int sol,greedy,v,c;
        for(int j=1;j<=large;j++){
                sol = dp[n-1][j];
                greedy = 0;
                v = j;
                for(int i=n-1;i>=0 && v;i--){
                        if(A[i]>v) continue;
                        c = v/A[i];
                        greedy+=c;
                        v-=c*A[i];
                }
                if(sol!=greedy){
                        possible = false;
                        break;
                }
        }
        if(!possible) printf("non-canonical\n");
        else printf("canonical\n");

	return 0;
}
