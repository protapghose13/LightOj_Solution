#include <bits/stdc++.h>
#define mx 30011
#define pb push_back
#define mod 100000007

using namespace std;

int n;
int coin[101];
int dp[10011];

int main()
{
    int t,k;
    scanf("%d",&t);
    int caseno=0;
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&coin[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;  ///base case
        for(int i=1;i<=n;i++){
            for(int j=coin[i];j<=k;j++){
                dp[j] = (dp[j]+dp[j-coin[i]])%mod;
            }
        }
        printf("Case %d: %d\n",++caseno,dp[k]%mod);
    }
}
