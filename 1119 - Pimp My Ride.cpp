#include <bits/stdc++.h>
#define mx 30011
#define pb push_back
//#define int long long
#define mod 100000007

using namespace std;

int ara[15][15];
int n,m;
int dp[1<<15];

int call(int mask){
    if(mask==(1<<n)-1)
        return 0;

    if(dp[mask]!=-1)
        return dp[mask];

    int res=INT_MAX;
    for(int i=0;i<n;i++){
        if((mask&(1<<i))==0){
            int sum=ara[i][i];
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(mask&(1<<j))
                        sum+=ara[i][j];
                }
            }
            res = min(res,sum+call(mask|(1<<i)));
        }
    }
    return dp[mask]=res;

}

main()
{
    int t,k;
    scanf("%d",&t);
    int caseno=0;
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&ara[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",++caseno,call(0));
    }
}
